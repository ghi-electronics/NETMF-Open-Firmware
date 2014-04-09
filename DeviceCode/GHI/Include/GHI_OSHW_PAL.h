////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GHI_OSHW_PAL_H_
#define _GHI_OSHW_PAL_H_

#include <tinyhal.h>
#include <TinyCLR_Interop.h>

typedef UINT32 OSHW_PAL_ERROR;

extern const CLR_RT_NativeAssemblyData g_CLR_AssemblyNative_GHI_Utilities_InternalEvent;

OSHW_PAL_ERROR OSHW_PAL_Bitmap_ConvertBPP(BYTE* bimap, INT32 bimapSize, BYTE* output, INT32 outputSize, BYTE bpp);

// CRC
UINT16 OSHW_PAL_CRC_16_CCITT(BYTE* buffer, UINT32 size, UINT16 seed);
UINT32 OSHW_PAL_CRC_32_IEEE_802_3(BYTE* buffer, UINT32 size, UINT32 seed);

// XTEA
BOOL OSHW_PAL_Crypto_XTEA_Encrypt(const UINT32 key[4], const UINT8 * plainData, UINT8 *encryptedData, UINT32 dataSize);
BOOL OSHW_PAL_Crypto_XTEA_Decrypt(const UINT32 key[4], const UINT8 * encryptedData, UINT8 *plainData, UINT32 dataSize);

#endif
