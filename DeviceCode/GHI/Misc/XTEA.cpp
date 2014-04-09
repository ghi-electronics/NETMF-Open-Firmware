#include <GHI\Include\GHI_OSHW_PAL.h>

BOOL OSHW_PAL_Crypto_XTEA_Encrypt(const UINT32 key[4], const UINT8 * plainData, UINT8 *encryptedData, UINT32 dataSize)
{
	if(((dataSize % 8) == 0))
	{
		if(dataSize)
		{
			dataSize /= 8;
			UINT32 i;
			UINT32 v0, v1, sum;
			const UINT32 delta = 0x9E3779B9;
			while(dataSize--)
			{
				memcpy(&v0, plainData, 4);
				memcpy(&v1, plainData + 4, 4);
				sum=0;
				
				for (i=0; i < 32; i++)
				{
					v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
					sum += delta;
					v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum>>11) & 3]);
				}
				memcpy(encryptedData, &v0, 4);
				memcpy(encryptedData + 4, &v1, 4);

				plainData+=8;
				encryptedData+=8;
			}
		}

		return TRUE;
	}

	return FALSE;
}

BOOL OSHW_PAL_Crypto_XTEA_Decrypt(const UINT32 key[4], const UINT8 * encryptedData, UINT8 *plainData, UINT32 dataSize)
{
	if( (dataSize % 8) == 0)
	{
		if(dataSize)
		{
			dataSize /= 8;
			UINT32 i;
			UINT32 v0, v1, sum;
			const UINT32 delta = 0x9E3779B9;
			while(dataSize--)
			{
				memcpy(&v0, encryptedData, 4);
				memcpy(&v1, encryptedData + 4, 4);
				sum=0xC6EF3720;

				for(i=0; i<32; i++)
				{
					v1 -= (v0 << 4 ^ v0 >> 5) + v0 ^ sum + key[sum>>11 & 3];
					sum -= delta;
					v0 -= (v1 << 4 ^ v1 >> 5) + v1 ^ sum + key[sum&3];
				}
				memcpy(plainData, &v0, 4);
				memcpy(plainData + 4, &v1, 4);

				plainData+=8;
				encryptedData+=8;
			}
		}

		return TRUE;
	}

	return FALSE;
}