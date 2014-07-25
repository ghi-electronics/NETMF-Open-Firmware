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

void** arguments = NULL;
bool* freeNeededList = NULL;
int next = 0;
int count = 0;

void FreeMemory()
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
			if (freeNeededList[i])
				private_free(arguments[i]);
			
		private_free(arguments);
		private_free(freeNeededList);
	}
	
	next = 0;
	count = 0;
	arguments = NULL;
	freeNeededList = NULL;
}

void AddParameter(void* value, int size, HRESULT &hr)
{
	void* argument = arguments[next] = private_malloc(size);
	
	if (argument == NULL)
	{
		FreeMemory();
		hr = CLR_E_OUT_OF_MEMORY;		
		return;
	}
	
	memcpy(argument, value, size);
	freeNeededList[next++] = true;
}

void AddArray(void* value)
{
	arguments[next] = value;
	freeNeededList[next++] = false;
}

INT32 RuntimeLoadableProcedures_NativeFunction::NativeInvoke( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	INT32 result = ((int(*)(void**))Get_address(pMngObj))(arguments);

	FreeMemory();
	
	return result;
}

void RuntimeLoadableProcedures_NativeFunction::NativeBeginArguments( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr )
{
	next = 0;
	count = param0;
	
	if (count == 0)
		return;
		
	arguments = (void**)private_malloc(sizeof(void*) * count);
	freeNeededList = (bool*)private_malloc(sizeof(bool) * count);
	if (arguments == NULL || freeNeededList == NULL)
	{
		hr = CLR_E_OUT_OF_MEMORY;	
		count = 0;
		
		if (arguments != NULL)
			private_free(arguments);
		
		if (freeNeededList != NULL)
			private_free(freeNeededList);
		
		return;
	}
	
	for (int i = 0; i < count; i++)
	{
		arguments[i] = NULL;
		freeNeededList[i] = false;
	}	
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT16 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT16 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT64 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT64 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, float param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, double param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgumentBool( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr )
{
	AddParameter(&param0, sizeof(param0), hr);
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT8 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT16 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT16 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT32 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT32 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT64 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT64 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_float param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_double param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}

void RuntimeLoadableProcedures_NativeFunction::NativeAddArgumentBool( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT8 param0, HRESULT &hr )
{
	AddArray(param0.GetBuffer());
}