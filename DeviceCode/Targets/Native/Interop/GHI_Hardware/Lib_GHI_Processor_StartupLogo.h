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


#ifndef _LIB_GHI_PROCESSOR_STARTUPLOGO_H_
#define _LIB_GHI_PROCESSOR_STARTUPLOGO_H_

namespace GHI
{
    namespace Processor
    {
        struct StartupLogo
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT32 NativeSupportedWidth( HRESULT &hr );
            static INT32 NativeSupportedHeight( HRESULT &hr );
            static INT8 NativeGetEnabled( HRESULT &hr );
            static void NativeGetBitmap( CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static void NativeGetCoords( INT32 * param0, INT32 * param1, HRESULT &hr );
            static INT8 NativeSave( CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, INT8 param3, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_STARTUPLOGO_H_
