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


#ifndef _LIB_GHI_UTILITIES_XTEA_H_
#define _LIB_GHI_UTILITIES_XTEA_H_

namespace GHI
{
    namespace Utilities
    {
        struct Xtea
        {
            // Helper Functions to access fields of managed object
            static UNSUPPORTED_TYPE& Get_key( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Utilities_Xtea::FIELD__key ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeEncrypt( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, CLR_RT_TypedArray_UINT8 param3, INT32 param4, HRESULT &hr );
            static void NativeDecrypt( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, CLR_RT_TypedArray_UINT8 param3, INT32 param4, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_UTILITIES_XTEA_H_
