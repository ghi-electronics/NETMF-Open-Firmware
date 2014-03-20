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


#ifndef _LIB_GHI_HARDWARE_CONFIGURATION__DISPLAY_H_
#define _LIB_GHI_HARDWARE_CONFIGURATION__DISPLAY_H_

namespace GHI
{
    namespace Hardware
    {
        struct Configuration_Display
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT8 NativeGetBootupMessage( HRESULT &hr );
            static INT8 NativeSetBootupMessage( INT8 param0, HRESULT &hr );
            static UINT8 NativeGetRotation( HRESULT &hr );
            static INT8 NativeSetRotation( UINT8 param0, HRESULT &hr );
            static void NativeGetConfiguration( UINT32 * param0, UINT32 * param1, INT8 * param2, INT8 * param3, INT8 * param4, INT8 * param5, INT8 * param6, UINT8 * param7, UINT8 * param8, UINT8 * param9, UINT8 * param10, UINT8 * param11, UINT8 * param12, UINT32 * param13, HRESULT &hr );
            static INT8 NativeSetConfiguration( UINT32 param0, UINT32 param1, INT8 param2, INT8 param3, INT8 param4, INT8 param5, INT8 param6, UINT8 param7, UINT8 param8, UINT8 param9, UINT8 param10, UINT8 param11, UINT8 param12, UINT32 param13, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_HARDWARE_CONFIGURATION__DISPLAY_H_
