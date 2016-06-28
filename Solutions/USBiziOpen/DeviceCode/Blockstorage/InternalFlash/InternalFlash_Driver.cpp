//-----------------------------------------------------------------------------
// Software that is described herein is for illustrative purposes only  
// which provides customers with programming information regarding the  
// products. This software is supplied "AS IS" without any warranties.  
// NXP Semiconductors assumes no responsibility or liability for the 
// use of the software, conveys no license or title under any patent, 
// copyright, or mask work right to the product. NXP Semiconductors 
// reserves the right to make changes in the software without 
// notification. NXP Semiconductors also make no representation or 
// warranty that such application will be suitable for the specified 
// use without further testing or modification. 
//-----------------------------------------------------------------------------

#include <tinyhal.h>
#include "InternalFlash_Driver.h"

#define IAP_LOCATION 0x7ffffff1
typedef void (*IAP)(unsigned int [],unsigned int[]);
unsigned int command[5];
unsigned int iap_result[2];
IAP iap_entry=(IAP)IAP_LOCATION;

int __section(SectionForFlashOperations) PrepareSector(int sector, int endsec)
{

    command[0]=50;
    command[1]=sector;
    command[2]=endsec;
    GLOBAL_LOCK(irq);
    iap_entry(command,iap_result);

    return iap_result[0];

}

//--//

BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::ChipInitialize( void* context )
{
    return TRUE;
}

BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::ChipUnInitialize( void* context )
{

    return TRUE;
}

const BlockDeviceInfo* __section(SectionForFlashOperations)InternalFlash_BS_Driver::GetDeviceInfo( void* context )
{
    MEMORY_MAPPED_NOR_BLOCK_CONFIG* config = (MEMORY_MAPPED_NOR_BLOCK_CONFIG*)context;
    
    return config->BlockConfig.BlockDeviceInformation;
}

BOOL  __section(SectionForFlashOperations)InternalFlash_BS_Driver::Read( void* context, ByteAddress StartSector, UINT32 NumBytes, BYTE * pSectorBuff)
{
	
    // XIP device does not need to read into a buffer
    NATIVE_PROFILE_HAL_DRIVERS_FLASH();

    if (pSectorBuff == NULL) return FALSE;

    StartSector = CPU_GetUncachableAddress(StartSector);

    CHIP_WORD* ChipAddress = (CHIP_WORD *)StartSector;
    CHIP_WORD* EndAddress  = (CHIP_WORD *)(StartSector + NumBytes);
    CHIP_WORD *pBuf        = (CHIP_WORD *)pSectorBuff;

    while(ChipAddress < EndAddress)
    {
        *pBuf++ = *ChipAddress++;
    }

    return TRUE;
}



BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::WriteX(void* context, ByteAddress StartSector, UINT32 NumBytes, BYTE * pSectorBuff, BOOL ReadModifyWrite, BOOL fIncrementDataPtr)
{

	INT32 total = NumBytes;

	while(total > 0)
	{
		NumBytes = (total > 1024) ? 1024 : NumBytes;

		volatile CHIP_WORD * ChipAddress;
		BOOL result= TRUE;
		CHIP_WORD * pData = (CHIP_WORD*)pSectorBuff;

		MEMORY_MAPPED_NOR_BLOCK_CONFIG* config = (MEMORY_MAPPED_NOR_BLOCK_CONFIG*)context;

		// if write protected, no update
		const BlockDeviceInfo * deviceInfo = config->BlockConfig.BlockDeviceInformation;
		//if (deviceInfo->Attribute.WriteProtected) return FALSE;

		#define TEMP_MEMORY_ADDRESS 0x4000FC00
			if(PrepareSector(18,27))
			return FALSE;

			// pData = (CHIP_WORD *)pSectorBuff;
		ASSERT(NumBytes<=1024);
		//ASSERT(NumOfBytes);
		//ASSERT(NumOfBytes==1024);

		memcpy((void*)TEMP_MEMORY_ADDRESS,(void*)StartSector,(1024));
		memcpy((void*)TEMP_MEMORY_ADDRESS,pSectorBuff,NumBytes);
    
		//burn
		command[0]=51;
		command[1]=(int)StartSector;
		command[2]=(int)TEMP_MEMORY_ADDRESS;
		command[3]=(1024);
		command[4]=SYSTEM_CYCLE_CLOCK_HZ/1000;
	
		{
			GLOBAL_LOCK(irq);
			iap_entry(command,iap_result);

			if( iap_result[0])
				return FALSE;
		}

		total-= NumBytes;
		StartSector += NumBytes;
		pSectorBuff += NumBytes;
	}

	return TRUE;

}

BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::Write(void* context, ByteAddress Address, UINT32 NumBytes, BYTE * pSectorBuff, BOOL ReadModifyWrite)
{
    NATIVE_PROFILE_PAL_FLASH();

    BYTE * pData;
    BYTE * pBuf = NULL;
    MEMORY_MAPPED_NOR_BLOCK_CONFIG* config = (MEMORY_MAPPED_NOR_BLOCK_CONFIG*)context;
    const BlockDeviceInfo * deviceInfo = config->BlockConfig.BlockDeviceInformation;
    
    UINT32 region, range;
    if(ReadModifyWrite) 
    {
        BOOL fRet = TRUE;
        
        if(!deviceInfo->FindRegionFromAddress(Address, region, range)) return FALSE;

        UINT32      bytesPerBlock   = deviceInfo->Regions[region].BytesPerBlock;
        UINT32      regionEnd       = deviceInfo->Regions[region].Start + deviceInfo->Regions[region].Size();
        UINT32      offset          = Address % bytesPerBlock;
        ByteAddress addr            = Address;
        ByteAddress addrEnd         = Address + NumBytes;
        UINT32      index           = 0;

        pBuf = (BYTE*)private_malloc(bytesPerBlock);

        if(pBuf == NULL) return FALSE;


        while(fRet && addr < addrEnd)
        {
            if(offset == 0 && NumBytes >= bytesPerBlock)
            {
                pData = &pSectorBuff[index];
            }
            else
            {
                int bytes = __min(bytesPerBlock - offset, NumBytes); 
                
                memcpy( &pBuf[0]     , (void*)(addr - offset), bytesPerBlock );
                memcpy( &pBuf[offset], &pSectorBuff[index]   , bytes         );

                pData = pBuf;
            }

            if(!EraseBlock( context, addr - offset ))
            {
                fRet = FALSE;
                break;
            }

            fRet = WriteX(context, (addr - offset), bytesPerBlock, pData, ReadModifyWrite, TRUE);

            NumBytes -= bytesPerBlock;
            addr     += bytesPerBlock;
            index    += bytesPerBlock - offset;
            offset    = 0;

            if(NumBytes > 0 && addr >= regionEnd)
            {
                region++;

                if(region >= deviceInfo->NumRegions)
                {
                    fRet = FALSE;
                }
                else
                {
                    regionEnd       = deviceInfo->Regions[region].Start + deviceInfo->Regions[region].Size();
                    bytesPerBlock   = deviceInfo->Regions[region].BytesPerBlock;

                    private_free(pBuf);

                    pBuf = (BYTE*)private_malloc(bytesPerBlock);

                    if(pBuf == NULL) fRet = FALSE;
                }
            }
                
        }

        if(pBuf != NULL)
        {
            private_free(pBuf);
        }

        return fRet;            
    }
    else
    {
        return WriteX(context, Address, NumBytes, pSectorBuff, ReadModifyWrite, TRUE);
    }
}


BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::Memset(void* context, ByteAddress Address, UINT8 Data, UINT32 NumBytes)
{
	ASSERT(FALSE);
	return FALSE;

    /*NATIVE_PROFILE_PAL_FLASH();

    CHIP_WORD chipData;

    memset(&chipData, Data, sizeof(CHIP_WORD));

    if(Data != 0)
    {
        // TODO: ERASE before memset - currently we only use this to set everything to zero for FS so no need to worry
        ASSERT(FALSE);
    }

    return WriteX(context, Address, NumBytes, (BYTE*)&chipData, TRUE, FALSE);*/
}


BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::GetSectorMetadata(void* context, ByteAddress SectorStart, SectorMetadata* pSectorMetadata)
{
    return FALSE;
}

BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::SetSectorMetadata(void* context, ByteAddress SectorStart, SectorMetadata* pSectorMetadata)
{
    return FALSE;
}


BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::IsBlockErased( void* context, ByteAddress BlockStart, UINT32 BlockLength )
{
	
    NATIVE_PROFILE_HAL_DRIVERS_FLASH();
    BlockStart = CPU_GetUncachableAddress(BlockStart);

    CHIP_WORD* ChipAddress = (CHIP_WORD *) BlockStart;
    CHIP_WORD* EndAddress  = (CHIP_WORD *)(BlockStart + BlockLength);
    
    while(ChipAddress < EndAddress)
    {
        if(*ChipAddress != 0xFFFF)
        {
            return FALSE;
        }
        ChipAddress++;
    }

    return TRUE;
}


BOOL __section(SectionForFlashOperations)InternalFlash_BS_Driver::EraseBlock( void* context, ByteAddress phyAddr )
{
	
    NATIVE_PROFILE_HAL_DRIVERS_FLASH();

    UINT32 RangeIndex;
    UINT32 RegionIndex;

    BLOCK_CONFIG* pConfig = (BLOCK_CONFIG*)context;

    if(!pConfig->BlockDeviceInformation->FindRegionFromAddress(phyAddr, RegionIndex, RangeIndex))
        return FALSE;

    const BlockRegionInfo* pRegion = &pConfig->BlockDeviceInformation->Regions[RegionIndex];

	if(IsBlockErased(context, phyAddr, pRegion->BytesPerBlock))
		return TRUE;

    ByteAddress StartSector = pConfig->BlockDeviceInformation->PhysicalToSectorAddress( pRegion, phyAddr );

    UINT32 SectorsPerBlock = pRegion->BytesPerBlock / pConfig->BlockDeviceInformation->BytesPerSector;

	UINT32 previosBlocks = 0;
	for(int i = 0; i < RegionIndex; i++)
		previosBlocks += pConfig->BlockDeviceInformation->Regions[i].NumBlocks;

	UINT32 block = (StartSector / SectorsPerBlock) + previosBlocks;

	if(PrepareSector(18, 27))
		return FALSE;
	//erase
	command[0]=52;
    command[1]=block;
    command[2]=block;
    command[3]=SYSTEM_CYCLE_CLOCK_HZ/1000;
    GLOBAL_LOCK(irq);
     iap_entry(command,iap_result);
	
    if( iap_result[0])
		return FALSE;

	return TRUE;
}

void  __section(SectionForFlashOperations)InternalFlash_BS_Driver::SetPowerState( void* context, BOOL State )
{
  
    return ;
}

//--// ---------------------------------------------------

#pragma arm section code = "SectionForFlashOperations"

UINT32 __section(SectionForFlashOperations)InternalFlash_BS_Driver::MaxSectorWrite_uSec( void* context )
{
    NATIVE_PROFILE_PAL_FLASH();

    MEMORY_MAPPED_NOR_BLOCK_CONFIG* config = (MEMORY_MAPPED_NOR_BLOCK_CONFIG*)context;
    
    return config->BlockConfig.BlockDeviceInformation->MaxSectorWrite_uSec;
}


UINT32 __section(SectionForFlashOperations)InternalFlash_BS_Driver::MaxBlockErase_uSec( void* context )
{
    NATIVE_PROFILE_PAL_FLASH();
    
    MEMORY_MAPPED_NOR_BLOCK_CONFIG* config = (MEMORY_MAPPED_NOR_BLOCK_CONFIG*)context;

    return config->BlockConfig.BlockDeviceInformation->MaxBlockErase_uSec;
    
}

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rodata = "g_InternalFlash_DeviceTable"
#endif

struct IBlockStorageDevice g_InternalFlash_DeviceTable = 
{                          
    &InternalFlash_BS_Driver::ChipInitialize,
    &InternalFlash_BS_Driver::ChipUnInitialize,
    &InternalFlash_BS_Driver::GetDeviceInfo,
    &InternalFlash_BS_Driver::Read,
    &InternalFlash_BS_Driver::Write,
    &InternalFlash_BS_Driver::Memset,
    &InternalFlash_BS_Driver::GetSectorMetadata,
    &InternalFlash_BS_Driver::SetSectorMetadata,
    &InternalFlash_BS_Driver::IsBlockErased,    
    &InternalFlash_BS_Driver::EraseBlock,
    &InternalFlash_BS_Driver::SetPowerState,
    &InternalFlash_BS_Driver::MaxSectorWrite_uSec,
    &InternalFlash_BS_Driver::MaxBlockErase_uSec,    
};

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rodata 
#endif 








