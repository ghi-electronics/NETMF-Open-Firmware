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


#ifndef _LIB_GHI_PROCESSOR_DISPLAY_H_
#define _LIB_GHI_PROCESSOR_DISPLAY_H_

namespace GHI
{
    namespace Processor
    {
        struct Display
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeGetLcdConfiguration( INT8 * param0, UINT8 * param1, UINT32 * param2, UINT32 * param3, INT8 * param4, INT8 * param5, INT8 * param6, INT8 * param7, INT8 * param8, UINT8 * param9, UINT8 * param10, UINT8 * param11, UINT8 * param12, UINT8 * param13, UINT8 * param14, UINT32 * param15, HRESULT &hr );
            static INT8 NativeSetLcdConfiguration( INT8 param0, UINT8 param1, UINT32 param2, UINT32 param3, INT8 param4, INT8 param5, INT8 param6, INT8 param7, INT8 param8, UINT8 param9, UINT8 param10, UINT8 param11, UINT8 param12, UINT8 param13, UINT8 param14, UINT32 param15, HRESULT &hr );
            static INT8 NativeSetSpiConfiguration( INT32 param0, INT32 param1, INT32 param2, INT32 param3, INT8 param4, INT8 param5, INT8 param6, INT32 param7, INT32 param8, INT32 param9, INT32 param10, INT32 param11, INT8 param12, HRESULT &hr );
            static INT8 NativeSetTouchPins( UINT32 param0, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4, UINT32 param5, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_DISPLAY_H_
