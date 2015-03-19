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


#ifndef _LIB_GHI_PROCESSOR_WATCHDOG_H_
#define _LIB_GHI_PROCESSOR_WATCHDOG_H_

namespace GHI
{
    namespace Processor
    {
        struct Watchdog
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static UINT8 NativeLastResetCause( HRESULT &hr );
            static UINT32 NativeGetMaxTimeout( HRESULT &hr );
            static void NativeEnable( UINT32 param0, HRESULT &hr );
            static void NativeDisable( HRESULT &hr );
            static void NativeResetCounter( HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_WATCHDOG_H_
