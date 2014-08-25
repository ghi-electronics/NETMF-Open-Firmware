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
#include "Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction.h"

using namespace GHI::Processor;

void RuntimeLoadableProcedures_NativeFunction::NativeDispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	void* pool = (void*)Get_nativeParameterPool(pMngObj);
	void** list = (void**)Get_nativeParameterList(pMngObj);
	
	if (pool) private_free(pool);
	if (list) private_free(list);
}

INT32 RuntimeLoadableProcedures_NativeFunction::NativeInvoke( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	Get_nativeIndex(pMngObj) = 0;
	
	return ((int(*)(void**))Get_address(pMngObj))((void**)Get_nativeParameterList(pMngObj));
}

void RuntimeLoadableProcedures_NativeFunction::NativeSetSize( CLR_RT_HeapBlock* pMngObj, INT32 count, HRESULT &hr )
{
	if (count == 0)
	{
		Get_nativeParameterPool(pMngObj) = NULL;
		Get_nativeParameterList(pMngObj) = NULL;
		
		return;
	}
		
	void* pool = private_malloc(count * 8);
	void** list = (void**)private_malloc(count * sizeof(void*));
	
	if (pool == NULL || list == NULL) 
	{
		if (pool) private_free(pool);
		if (list) private_free(list);
		
		hr = CLR_E_OUT_OF_MEMORY;
		
		return;
	}
	
	Get_nativeParameterPool(pMngObj) = (UINT32)pool;
	Get_nativeParameterList(pMngObj) = (UINT32)list;
	
	for (int i = 0; i < count; i++)
		list[i] = ((UINT8*)pool) + (i * 8);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr )
{
	*(UINT8*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr )
{
	*(INT8*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT16 param0, HRESULT &hr )
{
	*(UINT16*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT16 param0, HRESULT &hr )
{
	*(INT16*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr )
{
	*(UINT32*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr )
{
	*(INT32*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT64 param0, HRESULT &hr )
{
	*(UINT64*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT64 param0, HRESULT &hr )
{
	*(INT64*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, float param0, HRESULT &hr )
{
	*(float*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, double param0, HRESULT &hr )
{
	*(double*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgumentBool( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr )
{
	*(INT8*)(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0;
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT8 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT16 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT16 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT32 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT32 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT64 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT64 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_float param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_double param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgumentBool( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT8 param0, HRESULT &hr )
{
	(((void**)Get_nativeParameterList(pMngObj))[Get_nativeIndex(pMngObj)++]) = param0.GetBuffer();
}