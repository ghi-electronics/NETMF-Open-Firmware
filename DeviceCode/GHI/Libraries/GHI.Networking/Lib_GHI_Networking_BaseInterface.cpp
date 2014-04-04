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
#include "Lib_GHI_Networking_BaseInterface.h"

using namespace GHI::Networking;

void BaseInterface::NativeConstructor( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	if (Get_type(pMngObj) != 1)
		hr = CLR_E_NOT_SUPPORTED;
}

void BaseInterface::NativeDispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
}

void BaseInterface::NativeActivate( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
}

void BaseInterface::NativeDeactivate( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
}

void BaseInterface::NativeUpdateMacAddress( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
    hr = CLR_E_NOT_SUPPORTED;
}

