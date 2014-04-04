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
#include "Lib_GHI_Processor_Configuration__StartupLogo.h"

using namespace GHI::Processor;

INT32 Configuration_StartupLogo::NativeSupportedWidth( HRESULT &hr )
{
    return 0;
}

INT32 Configuration_StartupLogo::NativeSupportedHeight( HRESULT &hr )
{
    return 0;
}

INT8 Configuration_StartupLogo::NativeGetEnabled( HRESULT &hr )
{
    return 0;
}

void Configuration_StartupLogo::NativeGetBitmap( CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

void Configuration_StartupLogo::NativeGetCoords( INT32 * param0, INT32 * param1, HRESULT &hr )
{
	*param0 = 0;
	*param1 = 0;
}

INT8 Configuration_StartupLogo::NativeSave( CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, INT8 param3, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

