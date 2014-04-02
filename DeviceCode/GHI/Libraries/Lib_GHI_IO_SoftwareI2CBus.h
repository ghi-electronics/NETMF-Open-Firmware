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


#ifndef _LIB_GHI_IO_SOFTWAREI2CBUS_H_
#define _LIB_GHI_IO_SOFTWAREI2CBUS_H_

namespace GHI
{
    namespace IO
    {
        struct SoftwareI2CBus
        {
            // Helper Functions to access fields of managed object
            static UNSUPPORTED_TYPE& Get_emptyBuffer( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_IO_SoftwareI2CBus::FIELD__emptyBuffer ); }

            static INT8& Get_disposed( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_INT8( pMngObj, Library_Lib_GHI_IO_SoftwareI2CBus::FIELD__disposed ); }

            static UNSUPPORTED_TYPE& Get_clockPin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_IO_SoftwareI2CBus::FIELD__clockPin ); }

            static UNSUPPORTED_TYPE& Get_dataPin( CLR_RT_HeapBlock* pMngObj )    { return Interop_Marshal_GetField_UNSUPPORTED_TYPE( pMngObj, Library_Lib_GHI_IO_SoftwareI2CBus::FIELD__dataPin ); }

            // Declaration of stubs. These functions are implemented by Interop code developers
            static INT8 NativeWriteRead( INT32 param0, INT32 param1, UINT8 param2, CLR_RT_TypedArray_UINT8 param3, INT32 param4, INT32 param5, CLR_RT_TypedArray_UINT8 param6, INT32 param7, INT32 param8, INT32 * param9, INT32 * param10, HRESULT &hr );
        };
    }
}
#endif  //_LIB_GHI_IO_SOFTWAREI2CBUS_H_
