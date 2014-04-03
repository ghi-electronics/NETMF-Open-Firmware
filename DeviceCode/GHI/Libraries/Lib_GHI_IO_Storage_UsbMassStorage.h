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


#ifndef _LIB_GHI_IO_STORAGE_USBMASSSTORAGE_H_
#define _LIB_GHI_IO_STORAGE_USBMASSSTORAGE_H_

namespace GHI
{
    namespace IO
    {
        namespace Storage
        {
            struct UsbMassStorage
            {
                // Helper Functions to access fields of managed object
                static UINT32& Get_id( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_IO_Storage_UsbMassStorage::FIELD__id ); }

                // Declaration of stubs. These functions are implemented by Interop code developers
                static void NativeConstructor( CLR_RT_HeapBlock* pMngObj, UINT32 param0, UINT8 param1, UINT8 param2, HRESULT &hr );
                static void NativeFinalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                static void NativeMount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
                static void NativeUnmount( CLR_RT_HeapBlock* pMngObj, HRESULT &hr );
            };
        }
    }
}
#endif  //_LIB_GHI_IO_STORAGE_USBMASSSTORAGE_H_
