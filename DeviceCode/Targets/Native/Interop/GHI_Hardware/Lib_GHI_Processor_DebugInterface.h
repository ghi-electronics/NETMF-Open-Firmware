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


#ifndef _LIB_GHI_PROCESSOR_DEBUGINTERFACE_H_
#define _LIB_GHI_PROCESSOR_DEBUGINTERFACE_H_

namespace GHI
{
    namespace Processor
    {
        struct DebugInterface
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeLoad( INT32 * param0, INT32 * param1, INT8 * param2, HRESULT &hr );
            static INT8 NativeSave( INT32 param0, INT32 param1, INT8 param2, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_DEBUGINTERFACE_H_
