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
#include "GHIElectronics_OSH_NETMF_Hardware_GHIElectronics_OSH_NETMF_Hardware_AnalogIn.h"

#include <GHI_OSH_Drivers\Include\GHI_OSH_HAL.h>

using namespace GHIElectronics::OSH::NETMF::Hardware;

void AnalogIn::Dispose( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	if(Get_disposed(pMngObj) == FALSE)
	{
		Get_disposed(pMngObj) = TRUE;
		
		GHI_OSH_HAL_AnalogIn_Uninit(Get_channel(pMngObj));

		GPIO_PIN pin = GHI_OSH_HAL_AnalogIn_GetPin(Get_channel(pMngObj));
		if(pin != GPIO_PIN_NONE)
		{
			CPU_GPIO_ReservePin(pin, FALSE);
		}
	}
}

void AnalogIn::Finalize( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	Dispose(pMngObj, hr);
}

void AnalogIn::_ctor( CLR_RT_HeapBlock* pMngObj, UINT8 param0, HRESULT &hr )
{
	GPIO_PIN pin = GHI_OSH_HAL_AnalogIn_GetPin(param0);
	if(pin != GPIO_PIN_NONE)
	{
		if(!CPU_GPIO_ReservePin(pin, TRUE))
		{
			hr = CLR_E_INVALID_OPERATION;
			return;
		}
	}

	if(hr = GHI_OSH_HAL_AnalogIn_Init(param0))
	{
		if(pin != GPIO_PIN_NONE)
			CPU_GPIO_ReservePin(pin, FALSE);

		return;
	}

	Get_disposed(pMngObj) = FALSE;
	Get_channel(pMngObj) = param0;
	Get_min(pMngObj) = 0;
	Get_max(pMngObj) = 0;
}

void AnalogIn::SetLinearScale( CLR_RT_HeapBlock* pMngObj, INT32 param0, INT32 param1, HRESULT &hr )
{
	Get_min(pMngObj) = param0;
	Get_max(pMngObj) = param1;
}

INT32 AnalogIn::Read( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
    INT32 value = 0; 

	if(Get_disposed(pMngObj))
	{
		hr = CLR_E_OBJECT_DISPOSED;
		return value;
	}

	if(hr = GHI_OSH_HAL_AnalogIn_Read(Get_channel(pMngObj), (UINT32*)&value))
	{
		return value;
	}

	INT32 min = Get_min(pMngObj);
	INT32 max = Get_max(pMngObj);

	if(min || max)
	{
		INT32 resMax = (1 << GHI_OSH_HAL_AnalogIn_GetResolutionBits(Get_channel(pMngObj))) - 1;
		value = (value * (max - min)) / resMax + min;
	}

    return value;
}

