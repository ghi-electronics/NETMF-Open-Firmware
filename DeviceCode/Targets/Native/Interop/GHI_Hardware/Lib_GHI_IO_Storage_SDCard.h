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


#ifndef _LIB_GHI_IO_STORAGE_SDCARD_H_
#define _LIB_GHI_IO_STORAGE_SDCARD_H_

namespace GHI
{
    namespace IO
    {
        namespace Storage
        {
            struct SDCard
            {
                // Helper Functions to access fields of managed object
                static UINT32& Get_id( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_IO_Storage_SDCard::FIELD__id ); }

                static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_Storage_SDCard::FIELD__disposed ); }

                static INT8& Get_mounted( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_Storage_SDCard::FIELD__mounted ); }

                // Declaration of stubs. These functions are implemented by Interop code developers
                static void NativeConstructor( CLR_RT_HeapBlock* pMngObj, UINT32 param0, HRESULT &hr );
                static void NativeFinalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                static void NativeMount( CLR_RT_HeapBlock* pMngObj, INT32 param0, HRESULT &hr );
                static void NativeUnmount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            };
        }
    }
}
#endif  //_LIB_GHI_IO_STORAGE_SDCARD_H_
