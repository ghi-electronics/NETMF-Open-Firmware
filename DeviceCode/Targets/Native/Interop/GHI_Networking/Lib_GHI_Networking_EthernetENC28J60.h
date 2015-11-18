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


#ifndef _LIB_GHI_NETWORKING_ETHERNETENC28J60_H_
#define _LIB_GHI_NETWORKING_ETHERNETENC28J60_H_

namespace GHI
{
    namespace Networking
    {
        struct EthernetENC28J60
        {
            // Helper Functions to access fields of managed object
            static UNSUPPORTED_TYPE& Get_resetPin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Networking_EthernetENC28J60::FIELD__resetPin ); }

            static INT32& Get_spi( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_EthernetENC28J60::FIELD__spi ); }

            static INT32& Get_chipSelect( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_EthernetENC28J60::FIELD__chipSelect ); }

            static INT32& Get_externalInterrupt( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_EthernetENC28J60::FIELD__externalInterrupt ); }

            static INT32& Get_clockRate( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_Networking_EthernetENC28J60::FIELD__clockRate ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeSetHalConfig( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT8 NativeIsCableConnected( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_NETWORKING_ETHERNETENC28J60_H_
