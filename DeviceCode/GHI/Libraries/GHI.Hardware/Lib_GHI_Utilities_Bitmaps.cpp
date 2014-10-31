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


#include "Lib.h"
#include "Lib_GHI_Utilities_Bitmaps.h"

#include <GHI\Include\GHI_OSHW_PAL.h>

using namespace GHI::Utilities;

void Bitmaps::NativeConvert( CLR_RT_TypedArray_UINT8 bitmap, CLR_RT_TypedArray_UINT8 output, UINT8 bpp, HRESULT &hr )
{
	hr = OSHW_PAL_Bitmap_ConvertBPP(bitmap.GetBuffer(), bitmap.GetSize(), output.GetBuffer(), output.GetSize(), bpp);
}

void Bitmaps::NativeConvertToFile( CLR_RT_TypedArray_UINT8 bitmap, INT32 width, INT32 height, CLR_RT_TypedArray_UINT8 output, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeGetBuffer___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U1( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
		hr = CLR_E_NOT_SUPPORTED;

        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeGetBuffer___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U2( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
		hr = CLR_E_NOT_SUPPORTED;

        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeSetBuffer___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U1( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
		hr = CLR_E_NOT_SUPPORTED;

        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeSetBuffer___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U2( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
		hr = CLR_E_NOT_SUPPORTED;

        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}
