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


#ifndef _LIB_GHI_HARDWARE_REALTIMECLOCK_H_
#define _LIB_GHI_HARDWARE_REALTIMECLOCK_H_

namespace GHI
{
    namespace Hardware
    {
        struct RealTimeClock
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeSetTime( INT32 param0, INT32 param1, INT32 param2, INT32 param3, INT32 param4, INT32 param5, INT32 param6, INT32 param7, HRESULT &hr );
            static void NativeGetTime( INT32 * param0, INT32 * param1, INT32 * param2, INT32 * param3, INT32 * param4, INT32 * param5, INT32 * param6, HRESULT &hr );
            static void NativeSetAlarm( INT32 param0, INT32 param1, INT32 param2, INT32 param3, INT32 param4, INT32 param5, INT32 param6, INT32 param7, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_HARDWARE_REALTIMECLOCK_H_
