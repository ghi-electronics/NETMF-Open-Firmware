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
#include "Lib_GHI_Utilities_Arrays.h"

using namespace GHI::Utilities;

static int retValsLen = 0;
static char currValue[20] = {0 };
static int currValueLen = 0;

int SplitArrayNative( UINT8* data, const int dataLen, const char delim, float* retVals, const int retValsSize);
void ResetArray( char* arr, int len );
void InsertValueIntoArray_helper(CLR_RT_TypedArray_UINT8 array, void* value, INT32 offset, INT32 valueSize, HRESULT &hr);
void ExtractValueFromArray_helper(CLR_RT_TypedArray_UINT8 array, void* value, INT32 offset, INT32 valueSize, HRESULT &hr);

void Arrays::NativeInsertValue( CLR_RT_TypedArray_UINT8 bytes, INT32 offset, LPCSTR str, INT8 nullTerminate, HRESULT &hr )
{
	int length = hal_strlen_s(str);
	BYTE *buffer = bytes.GetBuffer();

	if(offset < 0 || 
		(length + offset + nullTerminate) > bytes.GetSize()
		)
		hr = CLR_E_INDEX_OUT_OF_RANGE;
	else
	{
		memcpy(buffer + offset, str, length);

		if(nullTerminate)
			buffer[length + offset] = NULL;
	}
}

void Arrays::NativeInsertValue( CLR_RT_TypedArray_UINT8 array, INT32 offset, float param2, HRESULT &hr )
{
	InsertValueIntoArray_helper(array, &param2, offset, sizeof(float), hr);
}

float Arrays::NativeExtractValue( CLR_RT_TypedArray_UINT8 array, INT32 offset, HRESULT &hr )
{
	float f;
	ExtractValueFromArray_helper(array, &f, offset, sizeof(f), hr);
	return f;
}

INT32 Arrays::NativeSplitToArray( CLR_RT_TypedArray_UINT8 line, INT32 length, CHAR delim, CLR_RT_TypedArray_float values, HRESULT &hr )
{
	int retVal = 0; 

	retVal = SplitArrayNative(line.GetBuffer(), length, delim, values.GetBuffer(), values.GetSize());

	return retVal;
}

void InsertValueIntoArray_helper(CLR_RT_TypedArray_UINT8 array, void* value, INT32 offset, INT32 valueSize, HRESULT &hr)
{
	if(offset >= 0 && (offset + valueSize) <= array.GetSize())
		memcpy(array.GetBuffer() + offset, value, valueSize);
	else
		hr = CLR_E_INDEX_OUT_OF_RANGE;
}

void ExtractValueFromArray_helper(CLR_RT_TypedArray_UINT8 array, void* value, INT32 offset, INT32 valueSize, HRESULT &hr)
{
	if(offset >= 0 && (offset + valueSize) <= array.GetSize())
		memcpy(value, array.GetBuffer() + offset, valueSize);
	else
		hr = CLR_E_INDEX_OUT_OF_RANGE;
}

int SplitArrayNative( UINT8* data, const int dataLen, const char delim, float* retVals, const int retValsSize)
{
	int i = 0;
	int iter = 0;
	char currByte = NULL;
	int nan = 1;
	bool number = false;
	bool letter = false;

	retValsLen = 0;

	for( i = 0; i < dataLen; i++ )
	{
		// grab our current byte to clean up the code, improve access times, and make it easier to push into a container.
		currByte = data[i];

		if(('0' <= currByte) && ('9' >= currByte) || '.' == currByte)
			number = true;
		else if (delim == currByte)
			nan = 1;
		else
			letter = true;

		if( delim == currByte )
		{
			currValue[currValueLen++] = '\0';

			// if number, process as number
			// Dont check every value, just the first to determine if it is a number, as a letter will just be one byte
			if( ('0' <= currValue[0] && '9' >= currValue[0] ) || '-' == currValue[0])
			{
				if(!letter && number)
					retVals[retValsLen++] = (float)atof(currValue);
				else
					retVals[retValsLen++] = 0.0/(nan-1);

				number = false;
				letter = false;
			}
			// else if letter, process as letter
			else if( 'A' <= currValue[0] && 'Z' >= currValue[0] && 2 == currValueLen)
			{
				if(!number && letter)
					retVals[retValsLen++] = currValue[0];
				else
					retVals[retValsLen++] = 0.0/(nan-1);

				number = false;
				letter = false;
			}
			else// if( currValueLen == 0 || currValueLen == 1 )
			{
				retVals[retValsLen++] = 0.0/(nan-1);

				number = false;
				letter = false;
			}

			// We are done processing. Clear the list so we can begin building a new value.
			ResetArray(currValue, 20);
			currValueLen = 0;

			continue;
		}

		// Build our current array to process into a value
		currValue[currValueLen++] = currByte;

		continue;
	}

	// Make sure we do not drop the last NaN...
	if( currValueLen == 0 || currValueLen == 1 )
	{
		retVals[retValsLen++] = 0.0/(nan-1);
	}

	// This is where we will fill everything out that we have just decode and mark that we are ready to process data.
	//for( iter = 0; iter < retValsSize; iter++)
	//{
	//	retVals[iter] = retVals[iter];
	//}

	// This is where we return the number of bytes that we have parsed.
	return retValsLen;
}

void ResetArray( char* arr, int len )
{
	int i = 0;

	for( i = 0; i < len; i++ )
	{
		arr[i] = 0;
	}
}

