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


#ifndef _GHIELECTRONICS_OSH_NETMF_HARDWARE_GHIELECTRONICS_OSH_NETMF_HARDWARE_ANALOGIN_H_
#define _GHIELECTRONICS_OSH_NETMF_HARDWARE_GHIELECTRONICS_OSH_NETMF_HARDWARE_ANALOGIN_H_

namespace GHIElectronics
{
    namespace OSH
    {
        namespace NETMF
        {
            namespace Hardware
            {
                struct AnalogIn
                {
                    // Helper Functions to access fields of managed object
                    static UINT8& Get_channel( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_AnalogIn::FIELD__channel ); }

                    static UINT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_AnalogIn::FIELD__disposed ); }

                    static INT32& Get_min( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_AnalogIn::FIELD__min ); }

                    static INT32& Get_max( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_AnalogIn::FIELD__max ); }

                    // Declaration of stubs. These functions are implemented by Interop code developers
                    static void Dispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                    static void Finalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                    static void _ctor( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr );
                    static void SetLinearScale( CLR_RT_HeapBlock* pMngObj, INT32 param0, INT32 param1, HRESULT &hr );
                    static INT32 Read( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                };
            }
        }
    }
}
#endif  //_GHIELECTRONICS_OSH_NETMF_HARDWARE_GHIELECTRONICS_OSH_NETMF_HARDWARE_ANALOGIN_H_
