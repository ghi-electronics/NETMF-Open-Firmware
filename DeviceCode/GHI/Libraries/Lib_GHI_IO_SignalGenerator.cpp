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
#include "Lib_GHI_IO_SignalGenerator.h"

using namespace GHI::IO;

// output compare
struct OC
{
	UINT32 *buffer;
	UINT32 BUFFER_MAX_SIZE;
	UINT32 bufferIndex;
	UINT32 bufferSize;
	GPIO_PIN pin;
	UINT8 repeat;
	UINT8 currentState;
	UINT8 isActive;
};

INT32 carrierFrequency_hz_latency = -1;

INT8 SignalGenerator::NativeConstructor(  CLR_RT_HeapBlock* pMngObj, INT8 param1, HRESULT &hr )
{
	UINT8 param0 = Get_pin(pMngObj);
	
	OC *oc = (OC*)private_malloc(sizeof(OC));

	if(!oc)
	{
		private_free(oc);
		hr = CLR_E_OUT_OF_MEMORY;
		return 0;
	}

	CPU_GPIO_EnableOutputPin(param0, param1);

	oc->pin = param0;
	oc->buffer = NULL;
	oc->bufferSize = 0;
	oc->isActive = FALSE;

	Get_nativePointer(pMngObj) = (UINT32)oc;
	Get_disposed(pMngObj) = FALSE;

	// calculate carrierFrequency_hz_latency
	if(carrierFrequency_hz_latency == -1)
	{
		GLOBAL_LOCK(irq);

		UINT64 start, end, a;

		start = HAL_Time_CurrentTime();
		end = HAL_Time_CurrentTime();
		a = end - start;

		start = HAL_Time_CurrentTime();
		CPU_GPIO_SetPinState(oc->pin, param1);
		HAL_Time_Sleep_MicroSeconds_InterruptEnabled(10);
		end = HAL_Time_CurrentTime();

		carrierFrequency_hz_latency = end - start - a - 100;
		if(carrierFrequency_hz_latency < 0)
			carrierFrequency_hz_latency = 0;

		// round
		if((carrierFrequency_hz_latency % 10) >= 5)
			carrierFrequency_hz_latency = (carrierFrequency_hz_latency+1) / 10;
		else
			carrierFrequency_hz_latency /= 10;
	}
	
	return 1;
}

void SignalGenerator::NativeDispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	GLOBAL_LOCK(irq);

	OC *oc = (OC*)Get_nativePointer(pMngObj);
	if(!oc)
		return;

	CPU_GPIO_DisablePin(oc->pin, RESISTOR_PULLUP, 0, GPIO_ALT_PRIMARY);

	if (oc->buffer)
		private_free(oc->buffer);

	private_free(oc);
	
	oc = NULL;
}

INT8 SignalGenerator::NativeIsActive( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	if(Get_disposed(pMngObj))
	{
		hr = CLR_E_OBJECT_DISPOSED;
		return FALSE;
	}

	OC *oc = (OC*)Get_nativePointer(pMngObj);
	if(!oc)
	{
		hr = CLR_E_ARGUMENT_NULL;
		return FALSE;
	}

	return oc->isActive;
}

void SignalGenerator::NativeSet( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr )
{
	GLOBAL_LOCK(irq);

	if(Get_disposed(pMngObj))
	{
		hr = CLR_E_OBJECT_DISPOSED;
		return;
	}

	OC *oc = (OC*)Get_nativePointer(pMngObj);
	if(!oc)
	{
		hr = CLR_E_ARGUMENT_NULL;
		return;
	}

	oc->isActive = FALSE;

	CPU_GPIO_SetPinState(oc->pin, param0);
}

INT8 SignalGenerator::NativeSet( CLR_RT_HeapBlock* pMngObj, INT8 param0, CLR_RT_TypedArray_UINT32 param1, INT32 param2, INT32 param3, INT8 param4, HRESULT &hr )
{
    hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

void SignalGenerator::NativeSet( CLR_RT_HeapBlock* pMngObj, INT8 initialValue, CLR_RT_TypedArray_UINT32 timingsBuffer_us, INT32 offset, INT32 count, UINT32 lastBitHoldTime_us, INT8 disableInterrupts, UINT32 carrierFrequency_hz, HRESULT &hr )
{
	if( (offset < 0) || (count < 0) || ((offset + count) > timingsBuffer_us.GetSize()) )
	{
		hr = CLR_E_OUT_OF_RANGE;
		return;
	}

	OC *oc = (OC*)Get_nativePointer(pMngObj);
	if(!oc)
	{
		hr = CLR_E_ARGUMENT_NULL;
		return;
	}

	{
		GLOBAL_LOCK(irq);

		oc->isActive = FALSE;
	}

	int i;
	int f, fCount;
	int wasInterrptEnabled;
	UINT32 *buffer = timingsBuffer_us.GetBuffer() + offset;

	// carrierFrequency_hz
	if(carrierFrequency_hz)
	{
		carrierFrequency_hz = ((UINT32)1000000 / 2 / (carrierFrequency_hz));

		// avoids dividing by 0 for little values
		if(carrierFrequency_hz <= carrierFrequency_hz_latency)
			carrierFrequency_hz = carrierFrequency_hz_latency + 1;
		else
			carrierFrequency_hz -= carrierFrequency_hz_latency;
	}

	if(disableInterrupts)
	{
		wasInterrptEnabled = INTERRUPTS_ENABLED_STATE();
		if(wasInterrptEnabled)
		{
			DISABLE_INTERRUPTS();
		}
	}

	CPU_GPIO_SetPinState(oc->pin, initialValue);

	for(i = 0; i < count; i++)
	{
		if(!(initialValue && carrierFrequency_hz))
		{
			HAL_Time_Sleep_MicroSeconds_InterruptEnabled(buffer[i]);
		}
		else
		{
			fCount = (buffer[i] / (carrierFrequency_hz + carrierFrequency_hz_latency));
			for(f = 0; f < fCount; f += 2)
			{
				CPU_GPIO_SetPinState(oc->pin, TRUE);
				HAL_Time_Sleep_MicroSeconds_InterruptEnabled(carrierFrequency_hz);

				CPU_GPIO_SetPinState(oc->pin, FALSE);
				HAL_Time_Sleep_MicroSeconds_InterruptEnabled(carrierFrequency_hz);
			}
		}

		initialValue = !initialValue;
		CPU_GPIO_SetPinState(oc->pin, initialValue);
	}

	if(lastBitHoldTime_us)
	{
		if(!(initialValue && carrierFrequency_hz))
		{
			HAL_Time_Sleep_MicroSeconds_InterruptEnabled(lastBitHoldTime_us);
		}
		else
		{
			fCount = (lastBitHoldTime_us / (carrierFrequency_hz + carrierFrequency_hz_latency));
			for(f = 0; f < fCount; f += 2)
			{
				CPU_GPIO_SetPinState(oc->pin, TRUE);
				HAL_Time_Sleep_MicroSeconds_InterruptEnabled(carrierFrequency_hz);

				CPU_GPIO_SetPinState(oc->pin, FALSE);
				HAL_Time_Sleep_MicroSeconds_InterruptEnabled(carrierFrequency_hz);
			}

			CPU_GPIO_SetPinState(oc->pin, TRUE);
		}
	}

	if(disableInterrupts)
	{
		if(wasInterrptEnabled)
		{
			ENABLE_INTERRUPTS();
		}
	}
}

