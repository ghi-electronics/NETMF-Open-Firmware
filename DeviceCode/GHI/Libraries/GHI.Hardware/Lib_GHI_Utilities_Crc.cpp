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
#include "Lib_GHI_Utilities_Crc.h"

#include <GHI\Include\GHI_OSHW_PAL.h>

using namespace GHI::Utilities;

UINT16 Crc::NativeCrc16( CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, UINT16 param3, HRESULT &hr )
{
    if(param1 < 0 || param2 < 0 || ((param1 + param2) > param0.GetSize()))
	{
		hr = CLR_E_INDEX_OUT_OF_RANGE;
		return 0;
	}

	return OSHW_PAL_CRC_16_CCITT(param0.GetBuffer() + param1, param2, param3);
}

UINT32 Crc::NativeCrc32( CLR_RT_TypedArray_UINT8 param0, INT32 param1, INT32 param2, UINT32 param3, HRESULT &hr )
{
    if(param1 < 0 || param2 < 0 || ((param1 + param2) > param0.GetSize()))
	{
		hr = CLR_E_INDEX_OUT_OF_RANGE;
		return 0;
	}

	return OSHW_PAL_CRC_32_IEEE_802_3(param0.GetBuffer() + param1, param2, param3);
}

