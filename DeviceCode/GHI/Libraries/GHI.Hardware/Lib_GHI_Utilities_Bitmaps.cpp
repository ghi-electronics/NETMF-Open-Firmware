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

void Bitmaps::NativeConvertToFile( CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, CLR_RT_TypedArray_UINT8 param3, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

