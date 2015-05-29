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


#ifndef _LIB_GHI_PROCESSOR_CONFIGURATION_H_
#define _LIB_GHI_PROCESSOR_CONFIGURATION_H_

namespace GHI
{
    namespace Processor
    {
        struct Configuration
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeGetParameters( UINT32 * param0, UINT32 * param1, HRESULT &hr );
            static INT8 NativeRead( CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static INT8 NativeWrite( CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static INT32 NativeGetEntrySize( LPCSTR param0, HRESULT &hr );
            static INT8 NativeReadEntry( LPCSTR param0, CLR_RT_TypedArray_UINT8 param1, HRESULT &hr );
            static INT8 NativeWriteEntry( LPCSTR param0, CLR_RT_TypedArray_UINT8 param1, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_CONFIGURATION_H_
