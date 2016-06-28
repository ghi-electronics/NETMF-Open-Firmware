////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <tinyhal.h>
#include <GHI_OSH_Drivers\Include\GHI_OSH_HAL.h>

extern struct BlockStorageDevice		g_SD_BS;
extern struct IBlockStorageDevice		g_SD_BS_DeviceTable;
extern struct SD_BLOCK_CONFIG			g_SD_BS_Config;
//extern struct SD_BL_CONFIGURATION       g_SD_BL_Config;

extern int g_MCI_clock_speed_value_khz;

GPAL_ERROR GHI_OSH_Mount(UINT32 ClockFrequencyInKHz)
{
	if(ClockFrequencyInKHz == -1)
	{
          g_MCI_clock_speed_value_khz = 10000000/4;
	}
	else
	{
		g_MCI_clock_speed_value_khz = ClockFrequencyInKHz*1000;
	}
     // From BlockStorage_decl.h
     // Adds BlockStorageDevice pBSD to the list
     // If Init=true, the Init() will be called.
     // static BOOL AddDevice( BlockStorageDevice* pBSD, IBlockStorageDevice* vtable, void* config, BOOL Init);

	if(BlockStorageList::AddDevice(&g_SD_BS, &g_SD_BS_DeviceTable, &g_SD_BS_Config, TRUE))
          FS_MountVolume("SD", 0, 0, /*g_SD_BL_Config.Device);//*/&g_SD_BS);
     else
          return CLR_E_FAIL;
//     BlockStorageList::AddDevice(&g_SD_BS, &g_SD_BS_DeviceTable, &g_SD_BS_Config, TRUE);
//     FS_MountVolume("SD", 0, 0, /*g_SD_BL_Config.Device);//*/&g_SD_BS);

	return S_OK;
}

void GHI_OSH_Unmount()
{
     // From BlockStorage_decl.h
     // Removes BlockStorageDevice pBSD from the list
     // Uninit = true, UnInit() will be called.
     // static BOOL RemoveDevice( BlockStorageDevice* pBSD, BOOL UnInit);
     
     FS_UnmountVolume(/*g_SD_BL_Config.Device*/&g_SD_BS);
     BlockStorageList::RemoveDevice(&g_SD_BS, TRUE);

}
