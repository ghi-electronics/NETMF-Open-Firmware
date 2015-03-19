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


#include "Lib.h"
#include "Lib_GHI_Processor_Watchdog.h"

using namespace GHI::Processor;

UINT8 Watchdog::NativeLastResetCause( HRESULT &hr )
{
    return 0;
}

UINT32 Watchdog::NativeGetMaxTimeout( HRESULT &hr )
{
    return 0;
}

void Watchdog::NativeEnable( UINT32 param0, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

void Watchdog::NativeDisable( HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

void Watchdog::NativeResetCounter( HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

