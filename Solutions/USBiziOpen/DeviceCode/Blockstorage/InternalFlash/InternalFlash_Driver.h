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

//--//

#ifndef _INTERNAL_FLASH_DRIVER_H_
#define _INTERNAL_FLASH_DRIVER_H_

//--//


struct InternalFlash_BS_Driver
{
    typedef UINT16 CHIP_WORD;

    //--//

	static BOOL ChipInitialize( void* context );

	static BOOL ChipUnInitialize( void* context );

	static const BlockDeviceInfo* GetDeviceInfo( void* context );

	static BOOL Read( void* context, ByteAddress Address, UINT32 NumBytes, BYTE * pSectorBuff );

	static BOOL Write( void* context, ByteAddress Address, UINT32 NumBytes, BYTE * pSectorBuff, BOOL ReadModifyWrite );	

	static BOOL Memset( void* context, ByteAddress Address, UINT8 Data, UINT32 NumBytes );

	static BOOL GetSectorMetadata(void* context, ByteAddress SectorStart, SectorMetadata* pSectorMetadata);

	static BOOL SetSectorMetadata(void* context, ByteAddress SectorStart, SectorMetadata* pSectorMetadata);

	static BOOL IsBlockErased( void* context, ByteAddress BlockStart, UINT32 BlockLength );

	static BOOL EraseBlock( void* context, ByteAddress Address );

	static void SetPowerState( void* context, UINT32 State );

	static UINT32 MaxSectorWrite_uSec( void* context );

	static UINT32 MaxBlockErase_uSec( void* context );


private:

    	static BOOL WriteX( void* context, ByteAddress Address, UINT32 NumBytes, BYTE * pSectorBuff, BOOL ReadModifyWrite, BOOL fIncrementDataPtr );
};

//--//

#endif // _INTERNAL_FLASH_DRIVER_H_
