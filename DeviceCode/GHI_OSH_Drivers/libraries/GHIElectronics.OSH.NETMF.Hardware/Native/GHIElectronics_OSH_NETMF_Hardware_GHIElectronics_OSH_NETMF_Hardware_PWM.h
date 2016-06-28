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


#ifndef _GHIELECTRONICS_OSH_NETMF_HARDWARE_GHIELECTRONICS_OSH_NETMF_HARDWARE_PWM_H_
#define _GHIELECTRONICS_OSH_NETMF_HARDWARE_GHIELECTRONICS_OSH_NETMF_HARDWARE_PWM_H_

namespace GHIElectronics
{
    namespace OSH
    {
        namespace NETMF
        {
            namespace Hardware
            {
                struct PWM
                {
                    // Helper Functions to access fields of managed object
                    static UINT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_PWM::FIELD__disposed ); }

                    static UINT8& Get_channel( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_PWM::FIELD__channel ); }

                    // Declaration of stubs. These functions are implemented by Interop code developers
                    static void Dispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                    static void Finalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                    static void _ctor( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr );
                    static void Set( CLR_RT_HeapBlock* pMngObj, INT32 param0, UINT8 param1, HRESULT &hr );
                    static void Set( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr );
                    static void SetPulse( CLR_RT_HeapBlock* pMngObj, UINT32 param0, UINT32 param1, HRESULT &hr );
                };
            }
        }
    }
}
#endif  //_GHIELECTRONICS_OSH_NETMF_HARDWARE_GHIELECTRONICS_OSH_NETMF_HARDWARE_PWM_H_
