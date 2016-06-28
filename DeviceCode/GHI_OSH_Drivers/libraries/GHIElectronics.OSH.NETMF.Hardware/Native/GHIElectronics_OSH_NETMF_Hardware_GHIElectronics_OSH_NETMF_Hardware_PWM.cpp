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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Portions Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "GHIElectronics_OSH_NETMF_Hardware.h"
#include "GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_PWM.h"

#include <GHI_OSH_Drivers\Include\GHI_OSH_HAL.h>

using namespace GHIElectronics::OSH::NETMF::Hardware;

void PWM::Dispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	if(Get_disposed(pMngObj) == FALSE)
	{
		Get_disposed(pMngObj) = TRUE;
		
		GHI_OSH_HAL_PWM_Uninit(Get_channel(pMngObj));

		GPIO_PIN pin = GHI_OSH_HAL_PWM_GetPin(Get_channel(pMngObj));
		if(pin != GPIO_PIN_NONE)
		{
			CPU_GPIO_ReservePin(pin, FALSE);
		}
	}
}

void PWM::Finalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	Dispose(pMngObj, hr);
}

void PWM::_ctor( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr )
{
	GPIO_PIN pin = GHI_OSH_HAL_PWM_GetPin(param0);
	if(pin != GPIO_PIN_NONE)
	{
		if(!CPU_GPIO_ReservePin(pin, TRUE))
		{
			hr = CLR_E_INVALID_OPERATION;
			return;
		}
	}

	if(hr = GHI_OSH_HAL_PWM_Init(param0))
	{
		if(pin != GPIO_PIN_NONE)
			CPU_GPIO_ReservePin(pin, FALSE);

		return;
	}

	Get_disposed(pMngObj) = FALSE;
	Get_channel(pMngObj) = param0;
}

void PWM::Set( CLR_RT_HeapBlock* pMngObj, INT32 param0, UINT8 param1, HRESULT &hr )
{
	if(Get_disposed(pMngObj))
	{
		hr = CLR_E_OBJECT_DISPOSED;
		return;
	}

	if(param0 < 0 || param1 > 100)
	{
		hr = CLR_E_OUT_OF_RANGE;
		return;
	}

	// in nano seconds
	UINT32 period = 0; 
	UINT32 highTime = 0; 

	if(param0)
		period = 1000000000 / param0;

	highTime = (UINT64)(period) * param1 / 100;

	SetPulse(pMngObj, period, highTime, hr);
}

void PWM::Set( CLR_RT_HeapBlock* pMngObj, INT8 param0, HRESULT &hr )
{
	if(Get_disposed(pMngObj))
	{
		hr = CLR_E_OBJECT_DISPOSED;
		return;
	}

	hr = GHI_OSH_HAL_PWM_Set(Get_channel(pMngObj), param0);
}

void PWM::SetPulse( CLR_RT_HeapBlock* pMngObj, UINT32 param0, UINT32 param1, HRESULT &hr )
{
	if(Get_disposed(pMngObj))
	{
		hr = CLR_E_OBJECT_DISPOSED;
		return;
	}

	if(param1 > param0)
	{
		hr = CLR_E_INVALID_PARAMETER;
		return;
	}

	hr = GHI_OSH_HAL_PWM_SetPulse(Get_channel(pMngObj), param0, param1);
}

