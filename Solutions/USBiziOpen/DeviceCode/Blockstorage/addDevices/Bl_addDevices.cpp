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

extern struct BlockStorageDevice  g_InternalFlash_BS;
extern struct IBlockStorageDevice g_InternalFlash_DeviceTable;
extern struct BLOCK_CONFIG        g_InternalFlash_BS_Config;

//--//

void BlockStorage_AddDevices() //tinyhal.cpp calls this
{
    BlockStorageList::AddDevice( &g_InternalFlash_BS, &g_InternalFlash_DeviceTable, &g_InternalFlash_BS_Config, FALSE );
}
