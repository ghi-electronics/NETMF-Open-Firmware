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
#include "Lib_GHI_Utilities_Xtea.h"

#include <GHI\Include\GHI_OSHW_PAL.h>
#include <TinyCLR_Runtime.h>
#include <corlib_native.h>

using namespace GHI::Utilities;

void Xtea::NativeEncrypt( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 plainData, INT32 plainDataOffset, INT32 dataCount, CLR_RT_TypedArray_UINT8 encryptedData, INT32 encryptedDataOffset, HRESULT &hr )
{
	if(plainDataOffset < 0 || encryptedDataOffset < 0 || dataCount < 0 || (plainDataOffset + dataCount) > plainData.GetSize() || (encryptedDataOffset + dataCount) > encryptedData.GetSize())
	{
		hr = CLR_E_INDEX_OUT_OF_RANGE;
	}
	else
	{
		CLR_RT_HeapBlock_Array* managedKey = pMngObj[Library_Lib_GHI_Utilities_Xtea::FIELD__key].DereferenceArray();

		UINT32 *key = (UINT32*)managedKey->GetFirstElement();
		if(!OSHW_PAL_Crypto_XTEA_Encrypt(key, plainData.GetBuffer() + plainDataOffset, encryptedData.GetBuffer() + encryptedDataOffset, dataCount))
			hr = CLR_E_INVALID_PARAMETER;
	}
}

void Xtea::NativeDecrypt( CLR_RT_HeapBlock* pMngObj, CLR_RT_TypedArray_UINT8 encryptedData, INT32 encryptedDataOffset, INT32 dataCount, CLR_RT_TypedArray_UINT8 plainData, INT32 plainDataOffset, HRESULT &hr )
{
	if(plainDataOffset < 0 || encryptedDataOffset < 0 || dataCount < 0 || (plainDataOffset + dataCount) > plainData.GetSize() || (encryptedDataOffset + dataCount) > encryptedData.GetSize())
	{
		hr = CLR_E_INDEX_OUT_OF_RANGE;
	}
	else
	{
		CLR_RT_HeapBlock_Array* managedKey = pMngObj[Library_Lib_GHI_Utilities_Xtea::FIELD__key].DereferenceArray();

		UINT32 *key = (UINT32*)managedKey->GetFirstElement();
		if(!OSHW_PAL_Crypto_XTEA_Decrypt(key, encryptedData.GetBuffer() + encryptedDataOffset, plainData.GetBuffer() + plainDataOffset, dataCount))
			hr = CLR_E_INVALID_PARAMETER;
	}
}

