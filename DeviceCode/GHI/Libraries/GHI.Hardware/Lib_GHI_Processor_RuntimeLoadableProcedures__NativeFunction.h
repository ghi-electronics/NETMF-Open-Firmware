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
            static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__disposed ); }

            static UINT32& Get_address( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__address ); }

            static INT8& Get_sizeSet( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__sizeSet ); }

            static INT32& Get_argumentCount( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__argumentCount ); }

            static UINT32& Get_nativeParameterPool( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__nativeParameterPool ); }

            static UINT32& Get_nativeParameterList( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__nativeParameterList ); }

            static UINT32& Get_nativeIndex( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__NativeFunction::FIELD__nativeIndex ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeDispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeInvoke( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeSetSize( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT16 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT16 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, UINT64 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, INT64 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, float param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, double param0, HRESULT &hr );
            static void NativeAddArgumentBool( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT8 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT16 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT16 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT32 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT32 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT64 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT64 param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_float param0, HRESULT &hr );
            static void NativeAddArgument( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_double param0, HRESULT &hr );
            static void NativeAddArgumentBool( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_INT8 param0, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__NATIVEFUNCTION_H_
