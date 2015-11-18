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


#ifndef _LIB_GHI_NETWORKING_PPPSERIALMODEM_H_
#define _LIB_GHI_NETWORKING_PPPSERIALMODEM_H_

namespace GHI
{
    namespace Networking
    {
        struct PPPSerialModem
        {
            // Helper Functions to access fields of managed object
            static UINT32& Get_deviceId( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Networking_PPPSerialModem::FIELD__deviceId ); }

            static UNSUPPORTED_TYPE& Get_port( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_PPPSerialModem::FIELD__port ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeEnable( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
            static INT8 NativeConnect( CLR_RT_HeapBlock* pMngObj, UINT32 param0, LPCSTR param1, LPCSTR param2, UINT32 param3, INT8 param4, HRESULT &hr );
            static void NativeDisconnect( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeIsLinkConnected( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_NETWORKING_PPPSERIALMODEM_H_
