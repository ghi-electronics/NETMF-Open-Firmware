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
#include "Lib_GHI_Hardware_LowLevel_Register.h"

using namespace GHI::Hardware::LowLevel;

void Register::NativeWrite( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr )
{
	(*(volatile unsigned *)Get_address(pMngObj)) = param0;
}

UINT32 Register::NativeRead( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	return (*(volatile unsigned *)Get_address(pMngObj));
}

void Register::NativeSetBits( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr )
{
	(*(volatile unsigned *)Get_address(pMngObj)) |= param0;
}

void Register::NativeClearBits( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr )
{
	(*(volatile unsigned *)Get_address(pMngObj)) &= ~param0;
}

void Register::NativeToggleBits( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr )
{
	(*(volatile unsigned *)Get_address(pMngObj)) ^= param0;
}

INT8 Register::NativeIsValid( UINT32 param0, HRESULT &hr )
{
    return true;
}

