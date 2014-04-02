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


#ifndef _LIB_GHI_IO_SIGNALGENERATOR_H_
#define _LIB_GHI_IO_SIGNALGENERATOR_H_

namespace GHI
{
    namespace IO
    {
        struct SignalGenerator
        {
            // Helper Functions to access fields of managed object
            static UINT32& Get_pin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_IO_SignalGenerator::FIELD__pin ); }

            static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_SignalGenerator::FIELD__disposed ); }

            static UINT32& Get_nativePointer( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_IO_SignalGenerator::FIELD__nativePointer ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT8 NativeConstructor( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr );
            static void NativeDispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeIsActive( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeSet( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr );
            static INT8 NativeSet( CLR_RT_HeapBlock* pMngObj, INT8 param0, CLR_RT_TypedArray_UINT32 param1, INT32 param2, INT32 param3, INT8 param4, HRESULT &hr );
            static void NativeSet( CLR_RT_HeapBlock* pMngObj, INT8 param0, CLR_RT_TypedArray_UINT32 param1, INT32 param2, INT32 param3, UINT32 param4, INT8 param5, UINT32 param6, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_IO_SIGNALGENERATOR_H_
