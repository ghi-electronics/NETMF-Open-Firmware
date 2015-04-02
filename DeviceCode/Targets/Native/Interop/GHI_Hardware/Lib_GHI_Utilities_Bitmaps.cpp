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

using namespace GHI::Utilities;

#define extractColor16(b1, b2, a, b, c) a = ((*(b1) & 0xF8) >> 3); b = (((*(b1) & 0x07) << 3) | ((*(b2) & 0xE0) >> 5)); c = (*(b2) & 0x1F)
#define packColor16(b1, b2, a, b, c) *(b1) = (a << 3) | ((b & 0x38) >> 3); *(b2) = (c & 0x1F) | ((b & 0x07) << 5)
#define packColor8(d, a, b, c) *(d) = (a << 5) | ((b & 0x07) << 2) | (c & 0x03)

enum BPP_Type
{
	BPP1_x128,
	BPP8_RGB, //3:3:2
	BPP8_RED,
	BPP8_GREEN,
	BPP8_BLUE,
	BPP16_RGB_BE, //5:6:5
	BPP16_RGB_LE,
	BPP16_BGR_BE,
	BPP16_BGR_LE,
};

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeConvert___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U1__GHIUtilitiesBitmapsBitsPerPixel(CLR_RT_StackFrame& stack)
{
	TINYCLR_HEADER(); hr = S_OK;
	{
		CLR_GFX_Bitmap* bitmap;
		TINYCLR_CHECK_HRESULT(Library_spot_graphics_native_Microsoft_SPOT_Bitmap::GetBitmap(&stack.Arg0(), false, bitmap));

		CLR_RT_TypedArray_UINT8 outputArray;
		TINYCLR_CHECK_HRESULT(Interop_Marshal_UINT8_ARRAY(stack, 1, outputArray));

		UINT8 bpp;
		TINYCLR_CHECK_HRESULT(Interop_Marshal_UINT8(stack, 2, bpp));

		INT32 count = outputArray.GetSize();
		UINT8* output = outputArray.GetBuffer();
		UINT8* input = (UINT8*)bitmap->m_palBitmap.data;

		UINT8 r, g, b;

		switch (bpp)
		{
		case BPP1_x128:
			UINT16* input16 = (UINT16*)input;

			for (int i = 0; i < bitmap->m_palBitmap.width * bitmap->m_palBitmap.height / 128 / 8; i++)
			{
				for (int z = 0; z < 128; z++)
				{
					*output = 0;

					if (input16[128 * 0]) *output |= 0x01;
					if (input16[128 * 1]) *output |= 0x02;
					if (input16[128 * 2]) *output |= 0x04;
					if (input16[128 * 3]) *output |= 0x08;
					if (input16[128 * 4]) *output |= 0x10;
					if (input16[128 * 5]) *output |= 0x20;
					if (input16[128 * 6]) *output |= 0x40;
					if (input16[128 * 7]) *output |= 0x80;

					output++;
					input16++;
				}

				input16 += (1024 - 128);
			}

			break;

		case BPP8_RED:
			for (int i = 0, j = 0; i < count; i++, j += 2) {
				extractColor16(input + j + 1, input + j, r, g, b);

				r <<= 3;

				output[i] = r | (r & 0x08 ? 0x07 : 0x00);
			}

			break;

		case BPP8_GREEN:
			for (int i = 0, j = 0; i < count; i++, j += 2) {
				extractColor16(input + j + 1, input + j, r, g, b);

				g <<= 2;

				output[i] = g | (g & 0x04 ? 0x03 : 0x00);
			}

			break;

		case BPP8_BLUE:
			for (int i = 0, j = 0; i < count; i++, j += 2) {
				extractColor16(input + j + 1, input + j, r, g, b);

				b <<= 3;

				output[i] = b | (b & 0x08 ? 0x07 : 0x00);
			}

			break;

		case BPP8_RGB:
			for (int i = 0, j = 0; i < count; i++, j += 2) {
				extractColor16(input + j + 1, input + j, r, g, b);

				r >>= 3;
				g >>= 3;
				b >>= 2;

				packColor8(output + i, b, g, r);
			}

			break;

		case BPP16_RGB_BE:
			for (int i = 0; i < count; i += 2) {
				extractColor16(input + i + 1, input + i, r, g, b);
				packColor16(output + i, output + i + 1, b, g, r);
			}

			break;

		case BPP16_RGB_LE:
			for (int i = 0; i < count; i += 2) {
				extractColor16(input + i + 1, input + i, r, g, b);
				packColor16(output + i + 1, output + i, b, g, r);
			}

			break;

		case BPP16_BGR_BE:
			for (int i = 0; i < count; i += 2) {
				output[i] = input[i + 1];
				output[i + 1] = input[i];
			}

			break;

		case BPP16_BGR_LE:
			for (int i = 0; i < count; i += 2) {
				output[i] = input[i];
				output[i + 1] = input[i + 1];
			}

			break;
		}

		TINYCLR_CHECK_HRESULT(hr);
	}
	TINYCLR_NOCLEANUP();
}

HRESULT Library_Lib_GHI_Utilities_Bitmaps::NativeConvertToFile___STATIC__VOID__MicrosoftSPOTGraphicsMicrosoftSPOTBitmap__SZARRAY_U1(CLR_RT_StackFrame& stack)
{
	TINYCLR_HEADER(); hr = S_OK;
	{
		hr = CLR_E_NOT_SUPPORTED;

		TINYCLR_CHECK_HRESULT(hr);
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
