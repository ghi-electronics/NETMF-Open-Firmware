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

#include <TinyCLR_Graphics.h>
#include "..\..\..\..\..\CLR\Libraries\SPOT_Graphics\SPOT_graphics_native.h"

#include <GHI\Include\GHI_OSHW_PAL.h>

using namespace GHI::Utilities;

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeConvert___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U1__GHIUtilitiesBitmapsBitsPerPixel( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
		CLR_GFX_Bitmap* param0;
		TINYCLR_CHECK_HRESULT(Library_spot_graphics_native_Microsoft_SPOT_Bitmap::GetBitmap(&stack.Arg0(), false, param0));

        CLR_RT_TypedArray_UINT8 param1;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT8_ARRAY( stack, 1, param1 ) );

        UINT8 param2;
        TINYCLR_CHECK_HRESULT( Interop_Marshal_UINT8( stack, 2, param2 ) );

		hr = OSHW_PAL_Bitmap_ConvertBPP((BYTE*)param0->m_palBitmap.data, param0->m_bm.m_width * param0->m_bm.m_height * 2, param1.GetBuffer(), param1.GetSize(), param2);
	
        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeConvertToFile___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__I4__I4__SZARRAY_U1( CLR_RT_StackFrame& stack )
{
    TINYCLR_HEADER(); hr = S_OK;
    {
		hr = CLR_E_NOT_SUPPORTED;
		
        TINYCLR_CHECK_HRESULT( hr );
    }
    TINYCLR_NOCLEANUP();
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
