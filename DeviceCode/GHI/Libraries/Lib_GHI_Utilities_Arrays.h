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


#ifndef _LIB_GHI_UTILITIES_ARRAYS_H_
#define _LIB_GHI_UTILITIES_ARRAYS_H_

namespace GHI
{
    namespace Utilities
    {
        struct Arrays
        {
            // Helper Functions to access fields of managed object
            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeInsertValue( CLR_RT_TypedArray_UINT8 param0, INT32 param1, LPCSTR param2, INT8 param3, HRESULT &hr );
            static void NativeInsertValue( CLR_RT_TypedArray_UINT8 param0, INT32 param1, float param2, HRESULT &hr );
            static float NativeExtractValue( CLR_RT_TypedArray_UINT8 param0, INT32 param1, HRESULT &hr );
            static INT32 NativeSplitToArray( CLR_RT_TypedArray_UINT8 param0, INT32 param1, CHAR param2, CLR_RT_TypedArray_float param3, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_UTILITIES_ARRAYS_H_
