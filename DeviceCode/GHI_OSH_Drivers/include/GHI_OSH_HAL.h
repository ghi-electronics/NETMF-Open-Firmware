////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GHI_OSH_HAL_H_
#define _GHI_OSH_HAL_H_

#include <tinyhal.h>

typedef UINT32 GPAL_ERROR;

// PWM
GPAL_ERROR GHI_OSH_HAL_PWM_Init(BYTE channel);
void GHI_OSH_HAL_PWM_Uninit(BYTE channel);
GPIO_PIN GHI_OSH_HAL_PWM_GetPin(BYTE channel);
GPAL_ERROR GHI_OSH_HAL_PWM_SetPulse(BYTE channel, UINT32 period_ns, UINT32 highTime_ns);
GPAL_ERROR GHI_OSH_HAL_PWM_Set(BYTE channel, BOOL state);


// AnalogIn
GPAL_ERROR GHI_OSH_HAL_AnalogIn_Init(BYTE channel);
void GHI_OSH_HAL_AnalogIn_Uninit(BYTE channel);
BYTE GHI_OSH_HAL_AnalogIn_GetResolutionBits(BYTE channel);
GPAL_ERROR GHI_OSH_HAL_AnalogIn_Read(BYTE channel, UINT32 *value);
GPIO_PIN GHI_OSH_HAL_AnalogIn_GetPin(BYTE channel);

// Software I2C
typedef struct
{
	GPIO_PIN sda;
	GPIO_PIN scl;
	UINT32 clockSpeed; // currently ignored
	BYTE address;	   // 7 bit address
	
} GHI_OSH_HAL_SoftwareI2C;

BOOL GHI_OSH_HAL_SoftwareI2C_WriteRead(GHI_OSH_HAL_SoftwareI2C *i2c, BYTE *writeBuffer, UINT32 writeLength, BYTE *readBuffer, UINT32 readLength, UINT32 *numWritten, UINT32 *numRead);

// StorageDev
GPAL_ERROR GHI_OSH_Mount(UINT32 ClockFrequencyInKHz);
void GHI_OSH_Unmount();

#endif
