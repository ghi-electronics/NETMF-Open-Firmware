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


#ifndef _LIB_GHI_PROCESSOR_INFIELDUPDATE_H_
#define _LIB_GHI_PROCESSOR_INFIELDUPDATE_H_

namespace GHI
{
    namespace Processor
    {
        struct InFieldUpdate
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT8 NativeInitialize( INT32 param0, HRESULT &hr );
            static INT8 NativeLoad( INT32 param0, CLR_RT_TypedArray_UINT8 param1, INT32 param2, HRESULT &hr );
            static INT8 NativeFlashAndReset( HRESULT &hr );
            static INT8 NativeAbort( HRESULT &hr );
            static UINT16 NativeCalculateCRC16( INT32 param0, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_INFIELDUPDATE_H_
