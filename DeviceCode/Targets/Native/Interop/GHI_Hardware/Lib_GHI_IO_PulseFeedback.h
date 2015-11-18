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


#ifndef _LIB_GHI_IO_PULSEFEEDBACK_H_
#define _LIB_GHI_IO_PULSEFEEDBACK_H_

namespace GHI
{
    namespace IO
    {
        struct PulseFeedback
        {
            // Helper Functions to access fields of managed object
            static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__disposed ); }

            static INT32& Get_timeout( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__timeout ); }

            static INT32& Get_pulseLength( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__pulseLength ); }

            static INT8& Get_pulseState( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__pulseState ); }

            static INT8& Get_echoState( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__echoState ); }

            static UINT8& Get_pulsePin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__pulsePin ); }

            static UINT8& Get_echoPin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__echoPin ); }

            static INT32& Get_mode( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__mode ); }

            static INT32& Get_resistorMode( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_PulseFeedback::FIELD__resistorMode ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT64 NativeReadDrainTime( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            static INT64 NativeReadEcho( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr );
            static void NativeFinalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_IO_PULSEFEEDBACK_H_
