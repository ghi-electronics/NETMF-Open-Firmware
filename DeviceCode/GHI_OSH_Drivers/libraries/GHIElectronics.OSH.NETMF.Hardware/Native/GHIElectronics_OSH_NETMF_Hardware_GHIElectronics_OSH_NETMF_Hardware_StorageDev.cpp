//-----------------------------------------------------------------------------
//
//                   ** WARNING! ** 
//    This file was generated automatically by a tool.
//    Re-running the tool will overwrite this file.
//    You should copy this file to a custom location
//    before adding any customization in the copy to
//    prevent loss of your changes when the tool is
//    re-run.
//
//-----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Portions Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "GHIElectronics_OSH_NETMF_Hardware.h"
#include "GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_StorageDev.h"

#include <GHI_OSH_Drivers\Include\GHI_OSH_HAL.h>

using namespace GHIElectronics::OSH::NETMF::Hardware;

void StorageDev::MountSD( HRESULT &hr )
{
	hr = GHI_OSH_Mount(-1); // Parameter is clock frequency in KHz; -1 represents default clock rate
}

void StorageDev::MountSD( UINT32 param0, HRESULT &hr )
{
	hr = GHI_OSH_Mount(param0); // Parameter is clock frequency in KHz
}

void StorageDev::UnmountSD( HRESULT &hr )
{
	GHI_OSH_Unmount();
}

