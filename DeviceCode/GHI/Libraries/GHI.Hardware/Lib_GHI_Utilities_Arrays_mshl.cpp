//-----------------------------------------------------------------------------
//
//    ** DO NOT EDIT THIS FILE! **
//    This file was generated by a tool
//    re-running the tool will overwrite this file.
//
//-----------------------------------------------------------------------------


#include "Lib.h"
#include "Lib_GHI_Utilities_Arrays.h"

using namespace GHI::Utilities;


HRESULT Library_Lib_GHI_Utilities_Arrays::NativeInsertValue___STATIC__VOID__SZARRAY_U1__I4__STRING__BOOLEAN( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
        CLR_RT_TypedArray_UINT8 param0;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT8_ARRAY( stack, 0, param0 ) );

        INT32 param1;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_INT32( stack, 1, param1 ) );

        LPCSTR param2;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_LPCSTR( stack, 2, param2 ) );

        INT8 param3;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_INT8( stack, 3, param3 ) );

        Arrays::NativeInsertValue( param0, param1, param2, param3, hr );
        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Arrays::NativeInsertValue___STATIC__VOID__SZARRAY_U1__I4__R4( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
        CLR_RT_TypedArray_UINT8 param0;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT8_ARRAY( stack, 0, param0 ) );

        INT32 param1;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_INT32( stack, 1, param1 ) );

        float param2;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_float( stack, 2, param2 ) );

        Arrays::NativeInsertValue( param0, param1, param2, hr );
        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Arrays::NativeExtractValue___STATIC__R4__SZARRAY_U1__I4( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
        CLR_RT_TypedArray_UINT8 param0;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT8_ARRAY( stack, 0, param0 ) );

        INT32 param1;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_INT32( stack, 1, param1 ) );

        float retVal = Arrays::NativeExtractValue( param0, param1, hr );
        TINYCLR_CHECK_HRESULT( hr );
        SetResult_float( stack, retVal );

    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Arrays::NativeSplitToArray___STATIC__I4__SZARRAY_U1__I4__CHAR__SZARRAY_R4( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
        CLR_RT_TypedArray_UINT8 param0;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT8_ARRAY( stack, 0, param0 ) );

        INT32 param1;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_INT32( stack, 1, param1 ) );

        CHAR param2;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_CHAR( stack, 2, param2 ) );

        CLR_RT_TypedArray_float param3;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_float_ARRAY( stack, 3, param3 ) );

        INT32 retVal = Arrays::NativeSplitToArray( param0, param1, param2, param3, hr );
        TINYCLR_CHECK_HRESULT( hr );
        SetResult_INT32( stack, retVal );

    }
    TINYCLR_NOCLEANUP();
}