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
#include "Lib_GHI_IO_SignalCapture.h"

using namespace GHI::IO;

INT32 _Read(UINT32 pin, UINT8 currentState, UINT32* buffer, INT32 count, INT32 timeout)
{
	INT32 retVal = 0;

	UINT64 start = HAL_Time_CurrentTime() / 10000;
	UINT64 startPinTime = HAL_Time_CurrentTime() / 10;
	UINT64 endPinTime;

	while(retVal < count)
	{	
		if(CPU_GPIO_GetPinState(pin) != currentState)
		{
			endPinTime = HAL_Time_CurrentTime() / 10;

			buffer[retVal] = endPinTime - startPinTime;

			startPinTime = endPinTime;

			currentState = !currentState;

			retVal++;
		}

		if(timeout > -1)
		{
			if( ((HAL_Time_CurrentTime() / 10000) - start) > timeout)
				break;
		}
	}

	return retVal;
}

INT32 SignalCapture::NativeRead( UINT32 pin, INT8 * initialState, CLR_RT_TypedArray_UINT32 buffer, INT32 offset, INT32 count, INT32 timeout, HRESULT &hr )
{
	if( (timeout < -1) || (offset < 0) || (count < 0) || ((offset + count) > buffer.GetSize()) )
	{
		hr = CLR_E_INDEX_OUT_OF_RANGE;
		return 0;
	}

	*initialState = CPU_GPIO_GetPinState(pin);

    return _Read(pin, *initialState, buffer.GetBuffer() + offset, count, timeout);
}

INT32 SignalCapture::NativeRead( UINT32 pin, INT8 waitForState, CLR_RT_TypedArray_UINT32 buffer, INT32 offset, INT32 count, INT32 timeout, HRESULT &hr )
{
	if( (timeout < -1) || (offset < 0) || (count < 0) || ((offset + count) > buffer.GetSize()))
	{
		hr = CLR_E_INDEX_OUT_OF_RANGE;
		return 0;
	}

	UINT64 start = HAL_Time_CurrentTime() / 10000;
	UINT64 end = start;

	while(TRUE)
	{
		if(CPU_GPIO_GetPinState(pin) == waitForState)
			break;

		if(timeout > -1)
		{
			end = HAL_Time_CurrentTime() / 10000;
			if( (end - start) > timeout)
				return 0;
		}
	}

	if(timeout > -1)
	{
		UINT32 t = end-start;
		timeout = (timeout > t) ? (timeout - t) : (0);
	}

	return _Read(pin, waitForState, buffer.GetBuffer() + offset, count, timeout);
}

