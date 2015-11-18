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


#ifndef _LIB_GHI_IO_SIGNALCAPTURE_H_
#define _LIB_GHI_IO_SIGNALCAPTURE_H_

namespace GHI
{
    namespace IO
    {
        struct SignalCapture
        {
            // Helper Functions to access fields of managed object
            static INT32& Get_timeout( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_SignalCapture::FIELD__timeout ); }

            static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_SignalCapture::FIELD__disposed ); }

            static UNSUPPORTED_TYPE& Get_port( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_IO_SignalCapture::FIELD__port ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT32 NativeRead( UINT32 param0, INT8 * param1, CLR_RT_TypedArray_UINT32 param2, INT32 param3, INT32 param4, INT32 param5, HRESULT &hr );
            static INT32 NativeRead( UINT32 param0, INT8 param1, CLR_RT_TypedArray_UINT32 param2, INT32 param3, INT32 param4, INT32 param5, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_IO_SIGNALCAPTURE_H_
