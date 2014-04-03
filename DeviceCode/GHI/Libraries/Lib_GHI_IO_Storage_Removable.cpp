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
#include "Lib_GHI_IO_Storage_Removable.h"

#include <GHI\Include\GHI_OSHW_HAL.h>

using namespace GHI::IO::Storage;

void Removable::NativeConstructor( CLR_RT_HeapBlock* pMngObj, UINT32 param0, UINT8 param1, UINT8 param2, HRESULT &hr )
{
	if (param0 != 1 && param1 != 0 && param2 != 0)
		hr = CLR_E_NOT_SUPPORTED;
}

void Removable::NativeFinalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
}

void Removable::NativeMount( CLR_RT_HeapBlock* pMngObj, INT32 speed, HRESULT &hr )
{
	hr = GHI_OSHW_Mount(speed);
}

void Removable::NativeUnmount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	GHI_OSHW_Unmount();
}

INT8 Removable::IsSDCardPresent( HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

UINT32 Removable::NativeFindId( LPCSTR param0, HRESULT &hr )
{
	if (param0 == NULL || strcmp(param0, "SD") != 0)
		hr = CLR_E_NOT_SUPPORTED;
	
    return 1;
}

