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
#include "Lib_GHI_Processor_AddressSpace.h"

using namespace GHI::Processor;

void AddressSpace::NativeWrite( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, INT32 param2, INT32 param3, HRESULT &hr )
{
	if( (param2 < 0) || (param3 < 0) || ((param2 + param3) > param1.GetSize()) )
	{
		hr = CLR_E_OUT_OF_RANGE;
		return;
	}

	memcpy((void*)param0, param1.GetBuffer() + param2, param3);
}

void AddressSpace::NativeRead( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, INT32 param2, INT32 param3, HRESULT &hr )
{
	if( (param2 < 0) || (param3 < 0) || ((param2 + param3) > param1.GetSize()) )
	{
		hr = CLR_E_OUT_OF_RANGE;
		return;
	}

	memcpy(param1.GetBuffer() + param2, (void*)param0, param3);
}

