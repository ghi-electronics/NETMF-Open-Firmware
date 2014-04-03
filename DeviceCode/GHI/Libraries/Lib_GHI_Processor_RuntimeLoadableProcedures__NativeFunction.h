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


#ifndef _LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__NATIVEFUNCTION_H_
#define _LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__NATIVEFUNCTION_H_

namespace GHI
{
    namespace Processor
    {
        struct RuntimeLoadableProcedures_NativeFunction
        {
            // Helper Functions to access fields of managed object
            static UINT32& Get_address( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__address ); }

            static UNSUPPORTED_TYPE& Get_arguments( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__arguments ); }

            static UNSUPPORTED_TYPE& Get_argumentSizes( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__argumentSizes ); }

            static UNSUPPORTED_TYPE& Get_emptyArray( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__emptyArray ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT32 InvokeNative( UINT32 param0, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_UINT32 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_INT32 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_float param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_INT16 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_UINT16 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_CHAR param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_UINT8 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
            static INT32 InvokeNative( UINT32 param0, CLR_RT_TypedArray_UINT8 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, CLR_RT_TypedArray_UINT8 param4, CLR_RT_TypedArray_UINT8 param5, CLR_RT_TypedArray_UINT8 param6, CLR_RT_TypedArray_UINT8 param7, CLR_RT_TypedArray_UINT8 param8, CLR_RT_TypedArray_INT8 param9, INT32 param10, CLR_RT_TypedArray_UINT32 param11, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__NATIVEFUNCTION_H_
