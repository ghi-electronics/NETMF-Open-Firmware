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


#ifndef _LIB_GHI_NETWORKING_WIFIRS9110_H_
#define _LIB_GHI_NETWORKING_WIFIRS9110_H_

namespace GHI
{
    namespace Networking
    {
        struct WiFiRS9110
        {
            // Helper Functions to access fields of managed object
            static UNSUPPORTED_TYPE& Get_waitOnScan( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnScan ); }

            static UNSUPPORTED_TYPE& Get_waitOnSendBssidRequest( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnSendBssidRequest ); }

            static UNSUPPORTED_TYPE& Get_waitOnJoin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnJoin ); }

            static UNSUPPORTED_TYPE& Get_waitOnDisconnect( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnDisconnect ); }

            static UNSUPPORTED_TYPE& Get_waitOnConnectionStatusResponse( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnConnectionStatusResponse ); }

            static UNSUPPORTED_TYPE& Get_waitOnCardReady( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnCardReady ); }

            static UNSUPPORTED_TYPE& Get_waitOnImageUpgrade( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__waitOnImageUpgrade ); }

            static UNSUPPORTED_TYPE& Get_activeNetwork( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__activeNetwork ); }

            static UNSUPPORTED_TYPE& Get_resetPin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__resetPin ); }

            static UNSUPPORTED_TYPE& Get_eventWorker( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__eventWorker ); }

            static UNSUPPORTED_TYPE& Get_completionWorker( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__completionWorker ); }

            static UNSUPPORTED_TYPE& Get_version( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__version ); }

            static INT32& Get_spi( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__spi ); }

            static INT32& Get_chipSelect( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__chipSelect ); }

            static INT32& Get_externalInterrupt( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__externalInterrupt ); }

            static INT32& Get_clockRate( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__clockRate ); }

            static INT32& Get_timeout( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__timeout ); }

            static UNSUPPORTED_TYPE& Get_hardwareMacAddress( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_WiFiRS9110::FIELD__hardwareMacAddress ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT8 NativeExecuteCompletion( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static UINT16 NativeGetLastJoinError( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeGetScanResponseSize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeGetBssidReponseSize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeSetHalConfig( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeTriggerContinuation( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeInitializeContinuations( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeUninitializeContinuations( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeInitializeSpiInterfaceRequest( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeGetEvent( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeSetBootloaderOption( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr );
            static INT8 NativeQueryMacAddress( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static void NativeGetMacAddress( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static LPCSTR NativeUpdateInternalMacAddress( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static void NativeSendBandRequest( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr );
            static void NativeInitializeRequest( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeScan( CLR_RT_HeapBlock* pMngObj, UINT32 param0, LPCSTR param1, HRESULT &hr );
            static INT8 NativeSendBssidRequest( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeGetBssidResponse( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static INT8 NativeDisconnect( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeQueryConnectionStatus( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT32 NativeGetConnectionStatus( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeQueryFirmwareVersion( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static LPCSTR NativeGetFirmwareVersion( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeJoin( CLR_RT_HeapBlock* pMngObj, INT32 param0, INT32 param1, CLR_RT_TypedArray_UINT8 param2, CLR_RT_TypedArray_UINT8 param3, INT32 param4, INT32 param5, INT32 param6, INT32 param7, INT32 param8, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_NETWORKING_WIFIRS9110_H_
