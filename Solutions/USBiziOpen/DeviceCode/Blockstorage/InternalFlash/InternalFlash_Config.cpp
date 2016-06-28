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
#include <InternalFlash_Driver.h>
//#include <GHI_Drivers\Include\GHAL.h>

#define FLASH_MANUFACTURER_CODE              0x1F//0x00010001
#define FLASH_DEVICE_CODE                    0x01C9//0x22DA22DA
#define FLASH_BLOCK_COUNT                    28
#define FLASH_BLOCK_ERASE_TYPICAL_TIME_USEC  1
#define FLASH_SECTOR_WRITE_TYPICAL_TIME_USEC 1
#define FLASH_BLOCK_ERASE_MAX_TIME_USEC      1
#define FLASH_SECTOR_WRITE_MAX_TIME_USEC     1

//--//

#define InternalFlash_FLASH_MEMORY_Base   0					
#define InternalFlash_FLASH_MEMORY_Size   (504*1024)		
//
#define InternalFlash_CHIP_SELECT      GPIO_PIN_NONE
#define InternalFlash_WAIT_STATES      0 
#define InternalFlash_RELEASE_COUNTS   0
#define InternalFlash_BIT_WIDTH        32
#define InternalFlash_WP_GPIO_PIN      GPIO_PIN_NONE
#define InternalFlash_WP_ACTIVE        FALSE

#define BYTES_PER_SECTOR            1024
    
#define REGION1_XIP_ADDRESS         InternalFlash_FLASH_MEMORY_Base
#define REGION1_BYTES_PER_BLK       (4*1024)
#define REGION1_SECTORS_PER_BLOCK   REGION1_BYTES_PER_BLK/BYTES_PER_SECTOR
#define REGION1_NUM_OF_BLOCKS       8
#define REGION1_SECTOR_START        0

#define REGION2_XIP_ADDRESS         REGION1_XIP_ADDRESS + REGION1_NUM_OF_BLOCKS* REGION1_BYTES_PER_BLK
#define REGION2_BYTES_PER_BLK       (32*1024)
#define REGION2_SECTORS_PER_BLOCK   REGION2_BYTES_PER_BLK/BYTES_PER_SECTOR
#define REGION2_NUM_OF_BLOCKS       14
#define REGION2_SECTOR_START        REGION1_SECTOR_START + REGION1_NUM_OF_BLOCKS*REGION1_SECTORS_PER_BLOCK

#define REGION3_XIP_ADDRESS         REGION2_XIP_ADDRESS + REGION2_NUM_OF_BLOCKS* REGION2_BYTES_PER_BLK
#define REGION3_BYTES_PER_BLK       (4*1024)
#define REGION3_SECTORS_PER_BLOCK   REGION3_BYTES_PER_BLK/BYTES_PER_SECTOR
#define REGION3_NUM_OF_BLOCKS       6
#define REGION3_SECTOR_START        REGION2_SECTOR_START + REGION2_NUM_OF_BLOCKS* REGION2_SECTORS_PER_BLOCK

#define InternalFlash_REMOVEABLE     FALSE
#define InternalFlash_SUPPORTXIP     TRUE
#define InternalFlash_WRITEPROTECTED FALSE

#define InternalFlash_NUMREGIONS     3

// -- // device information

// BlockDeviceInformation


BlockRange g_Internal_BlockRange1[] =	// 8 blocks
{
    { BlockRange::BLOCKTYPE_BOOTSTRAP	,  0,  7 },  
	
};

BlockRange g_Internal_BlockRange2[] =	// 14 blocks
{
    { BlockRange::BLOCKTYPE_BOOTSTRAP     ,  0,  11 }, 
	{ BlockRange::BLOCKTYPE_DEPLOYMENT , 12, 13 },  

};

BlockRange g_Internal_BlockRange3[] =	// 6 blocks
{
    { BlockRange::BLOCKTYPE_DEPLOYMENT , 0, 4 },  		
	{ BlockRange::BLOCKTYPE_CONFIG , 5, 5 },			

};


//--//

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rwdata = "g_InternalFlash_Config"
#endif


//--//

const BlockRegionInfo  g_InternalFlash_BlkRegion[InternalFlash_NUMREGIONS] = 
{
	{
		REGION1_XIP_ADDRESS,   // ByteAddress   Start;              // Starting Sector address
		REGION1_NUM_OF_BLOCKS,                 		 // UINT32          NumBlocks;          // total number of blocks in this region
		REGION1_BYTES_PER_BLK,              // UINT32        BytesPerBlock;      // Total number of bytes per block (MUST be SectorsPerBlock * DataBytesPerSector)

		ARRAYSIZE_CONST_EXPR(g_Internal_BlockRange1),
		g_Internal_BlockRange1,
	},

	{
		REGION2_XIP_ADDRESS,   // ByteAddress   Start;              // Starting Sector address
		REGION2_NUM_OF_BLOCKS,                 		 // UINT32          NumBlocks;          // total number of blocks in this region
		REGION2_BYTES_PER_BLK,              // UINT32        BytesPerBlock;      // Total number of bytes per block (MUST be SectorsPerBlock * DataBytesPerSector)

		ARRAYSIZE_CONST_EXPR(g_Internal_BlockRange2),
		g_Internal_BlockRange2,
	},

	{
		REGION3_XIP_ADDRESS,   // ByteAddress   Start;              // Starting Sector address
		REGION3_NUM_OF_BLOCKS,                 		 // UINT32          NumBlocks;          // total number of blocks in this region
		REGION3_BYTES_PER_BLK,              // UINT32        BytesPerBlock;      // Total number of bytes per block (MUST be SectorsPerBlock * DataBytesPerSector)

		ARRAYSIZE_CONST_EXPR(g_Internal_BlockRange3),
		g_Internal_BlockRange3,
	},
};

    
BlockDeviceInfo g_InternalFlash_DeviceInfo=
{
        {  
            InternalFlash_REMOVEABLE,                     // BOOL Removable;
            InternalFlash_SUPPORTXIP,                     // BOOL SupportsXIP;
            InternalFlash_WRITEPROTECTED,
        },

	    FLASH_SECTOR_WRITE_MAX_TIME_USEC,           // UINT32 Duration_Max_WordWrite_uSec;
	    FLASH_BLOCK_ERASE_MAX_TIME_USEC,             // UINT32 Duration_Max_SectorErase_uSec;
	    BYTES_PER_SECTOR,                         // UINT32 BytesPerSector; // Bytes Per Sector

	    InternalFlash_FLASH_MEMORY_Size,                              // UINT32 Size;

        InternalFlash_NUMREGIONS,                      // UINT32 NumRegions;
        g_InternalFlash_BlkRegion,                      //const BlockRegionInfo* pRegions;
};


struct MEMORY_MAPPED_NOR_BLOCK_CONFIG g_InternalFlash_BS_Config =
{
   { // BLOCK_CONFIG
        {
            InternalFlash_WP_GPIO_PIN,                       // GPIO_PIN             Pin;
            InternalFlash_WP_ACTIVE,                         // BOOL                 ActiveState;
        },
       &g_InternalFlash_DeviceInfo,                        // BlockDeviceinfo
    },

    {
        InternalFlash_CHIP_SELECT,                     // UINT8  CPU_MEMORY_CONFIG::ChipSelect;
        FALSE,                                           // UINT8  CPU_MEMORY_CONFIG::ReadOnly;
        InternalFlash_WAIT_STATES,                     // UINT32 CPU_MEMORY_CONFIG::WaitStates;
        InternalFlash_RELEASE_COUNTS,                  // UINT32 CPU_MEMORY_CONFIG::ReleaseCounts;
        InternalFlash_BIT_WIDTH,                       // UINT32 CPU_MEMORY_CONFIG::BitWidth;
        InternalFlash_FLASH_MEMORY_Base,                    // UINT32 CPU_MEMORY_CONFIG::BaseAddress;
        InternalFlash_FLASH_MEMORY_Size,                   // UINT32 CPU_MEMORY_CONFIG::SizeInBytes;
        0,0,0,
    },
    
    0,                                      // UINT32  ChipProtection;
    FLASH_MANUFACTURER_CODE,                // FLASH_WORD ManufacturerCode;
    FLASH_DEVICE_CODE,                      // FLASH_WORD DeviceCode;
};
    
#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rwdata
#endif

//--//

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rodata = "g_InternalFlash_BS"
#endif

struct BlockStorageDevice g_InternalFlash_BS;

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rodata
#endif
