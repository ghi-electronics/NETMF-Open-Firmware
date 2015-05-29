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
#include "Lib_GHI_Processor_Configuration.h"

using namespace GHI::Processor;

void Configuration::NativeGetParameters( UINT32 * param0, UINT32 * param1, HRESULT &hr )
{
	*param0 = 0;
	*param1 = 0;
}

INT8 Configuration::NativeRead( CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

INT8 Configuration::NativeWrite( CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

INT32 Configuration::NativeGetEntrySize( LPCSTR param0, HRESULT &hr )
{
    return 0;
}

INT8 Configuration::NativeReadEntry( LPCSTR param0, CLR_RT_TypedArray_UINT8 param1, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

INT8 Configuration::NativeWriteEntry( LPCSTR param0, CLR_RT_TypedArray_UINT8 param1, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}
