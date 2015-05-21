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


#ifndef _LIB_GHI_IO_PULSECAPTURE_H_
#define _LIB_GHI_IO_PULSECAPTURE_H_

namespace GHI
{
    namespace IO
    {
        struct PulseCapture
        {
            // Helper Functions to access fields of managed object
            static INT32& Get_timeout( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT32( pMngObj, Library_Lib_GHI_IO_PulseCapture::FIELD__timeout ); }

            static UINT8& Get_pulse( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_Lib_GHI_IO_PulseCapture::FIELD__pulse ); }

            static UINT8& Get_echo( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT8( pMngObj, Library_Lib_GHI_IO_PulseCapture::FIELD__echo ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT64 NativeMeasureDrain( CLR_RT_HeapBlock* pMngObj, INT8 param0, INT32 param1, HRESULT &hr );
            static INT64 NativeMeasureEcho( CLR_RT_HeapBlock* pMngObj, INT8 param0, INT32 param1, INT8 param2, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_IO_PULSECAPTURE_H_
