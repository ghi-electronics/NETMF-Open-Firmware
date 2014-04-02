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


#ifndef _LIB_GHI_IO_CONTROLLERAREANETWORK_H_
#define _LIB_GHI_IO_CONTROLLERAREANETWORK_H_

namespace GHI
{
    namespace IO
    {
        struct ControllerAreaNetwork
        {
            // Helper Functions to access fields of managed object
            static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__disposed ); }

            static INT8& Get_enabled( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__enabled ); }

            static UINT8& Get_channel( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__channel ); }

            static INT32& Get_receiveBufferSize( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__receiveBufferSize ); }

            static UINT32& Get_baudRateRegister( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__baudRateRegister ); }

            static UNSUPPORTED_TYPE& Get_MessageAvailable( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__MessageAvailable ); }

            static UNSUPPORTED_TYPE& Get_ErrorReceived( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_IO_ControllerAreaNetwork::FIELD__ErrorReceived ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeSetExplicitFilters( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT32 param0, HRESULT &hr );
            static void NativeSetGroupFilters( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT32 param0, CLR_RT_TypedArray_UINT32 param1, HRESULT &hr );
            static INT8 NativeEnable( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeDisable( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeReset( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeReceiveErrorCount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeTransmitErrorCount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeReceivedMessageCount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeTransmittedMessagesSent( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeTransmissionAllowed( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeDiscardIncomingMessages( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeSourceClock( HRESULT &hr );
            static UINT32 NativeCalculateRegisterValue( INT32 param0, INT32 param1, INT32 param2, INT32 param3, INT32 param4, INT8 param5, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_IO_CONTROLLERAREANETWORK_H_
