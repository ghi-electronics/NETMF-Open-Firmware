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


#ifndef _LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__ELFIMAGE_H_
#define _LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__ELFIMAGE_H_

namespace GHI
{
    namespace Processor
    {
        struct RuntimeLoadableProcedures_ElfImage
        {
            // Helper Functions to access fields of managed object
            static UINT32& Get_address( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__ElfImage::FIELD__address ); }

            static UINT32& Get_size( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__ElfImage::FIELD__size ); }

            static UINT32& Get_regionCount( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UINT32( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__ElfImage::FIELD__regionCount ); }

            static UNSUPPORTED_TYPE& Get_imageData( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_Processor_RuntimeLoadableProcedures__ElfImage::FIELD__imageData ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static void NativeZeroRegion( CLR_RT_HeapBlock* pMngObj, UINT32 param0, UINT32 param1, HRESULT &hr );
            static void NativeLoadElf( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, HRESULT &hr );
            static UINT32 NativeFindSymbolAddress( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 param0, LPCSTR param1, INT32 param2, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_PROCESSOR_RUNTIMELOADABLEPROCEDURES__ELFIMAGE_H_
