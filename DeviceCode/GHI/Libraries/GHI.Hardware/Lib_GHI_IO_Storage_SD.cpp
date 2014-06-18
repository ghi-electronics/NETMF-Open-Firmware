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
#include "Lib_GHI_IO_Storage_SD.h"

#include <GHI\Include\GHI_OSHW_HAL.h>

using namespace GHI::IO::Storage;

void SD::NativeConstructor( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
}

void SD::NativeFinalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
}

void SD::NativeMount( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr )
{
	hr = GHI_OSHW_Mount(param0);
}

void SD::NativeUnmount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	GHI_OSHW_Unmount();
}

INT8 SD::IsSDCardPresent( HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

