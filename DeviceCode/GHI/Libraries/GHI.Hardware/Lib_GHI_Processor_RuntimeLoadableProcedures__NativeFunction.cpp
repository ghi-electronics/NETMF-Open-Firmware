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

#define MAX_ARGS 8
void *_args[MAX_ARGS];

typedef int (*USER_FUNCTION)(unsigned int* generalArray, void** args, unsigned int argsCount, unsigned int* argSize);

INT32 General_Invoke_Helper( UINT32 address, CLR_RT_TypedArray_UINT8 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, unsigned int *generalArray, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
	_args[0] = param0.GetBuffer();
	_args[1] = param1.GetBuffer();
	_args[2] = param2.GetBuffer();
	_args[3] = param3.GetBuffer();
	_args[4] = param4.GetBuffer();
	_args[5] = param5.GetBuffer();
	_args[6] = param6.GetBuffer();
	_args[7] = param7.GetBuffer();

	return ((USER_FUNCTION)address)(generalArray, _args, param10, param11.GetBuffer());
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 address, HRESULT &hr )
{
	return ((USER_FUNCTION)address)(NULL, NULL, 0, NULL);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_UINT32 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_INT32 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_float param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_INT16 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_UINT16 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_CHAR param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_UINT8 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}

INT32 RuntimeLoadableProcedures_NativeFunction::InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_INT8 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr )
{
    return General_Invoke_Helper(param0, param1, param2, param3, param4, param5, param6, param7, param8, (unsigned int*)param9.GetBuffer(), param10, param11, hr);
}