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


#ifndef _LIB_GHI_HARDWARE_LOWLEVEL_REGISTER_H_
#define _LIB_GHI_HARDWARE_LOWLEVEL_REGISTER_H_

namespace GHI
{
    namespace Hardware
    {
        namespace LowLevel
        {
            struct Register
            {
                // Helper Functions to access fields of managed object
                static UINT32& Get_address( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Hardware_LowLevel_Register::FIELD__address ); }

                // Declaration of stubs. These functions are implemented by Interop code developers
                static void NativeWrite( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
                static UINT32 NativeRead( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                static void NativeSetBits( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
                static void NativeClearBits( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
                static void NativeToggleBits( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
                static INT8 NativeIsValid( UINT32 param0, HRESULT &hr );
            };
        }
    }
}
#endif  //_LIB_GHI_HARDWARE_LOWLEVEL_REGISTER_H_
