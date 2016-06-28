////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyhal.h>
#include <GHI_OSH_Drivers\Include\GHI_OSH_HAL.h>
#include <Targets\Native\AT91\DeviceCode\AT91.h>

//registers
#define TOUCHSCREEN_ADC_CONTROLLER_CHANNEL_SELECT						(*(volatile unsigned long *)0xFFFD0010) // TSADCC_CHER
#define TOUCHSCREEN_ADC_CONTROLLER_CHANNEL_DISABLE_REGISTER				(*(volatile unsigned long *)0xFFFD0014) // TSADCC_MR
#define TOUCHSCREEN_ADC_CONTROLLER_MODE_REGISTER						(*(volatile unsigned long *)0xFFFD0004) // TSADCC_MR
#define TOUCHSCREEN_ADC_CONTROLLER_TRIGGER_REGISTER						(*(volatile unsigned long *)0xFFFD0008) // TSADCC_TRGR
#define TOUCHSCREEN_ADC_CONTROLLER_CHANNEL_DATA_REGISTER_BASE_ADDRESS	0xFFFD0030 // TSADCC_TRGR


//pins
#define ANALOG_MAX_PINS 6
unsigned int AnalogPinTable[ANALOG_MAX_PINS] = {
	AT91_GPIO_Driver::PA17, 
	AT91_GPIO_Driver::PA18, 
	AT91_GPIO_Driver::PA19, 
	AT91_GPIO_Driver::PA20, 
	AT91_GPIO_Driver::PD6, 
	AT91_GPIO_Driver::PD7};


// AnalogIn
GPAL_ERROR GHI_OSH_HAL_AnalogIn_Init(BYTE channel)
{
	if(channel >= ANALOG_MAX_PINS)
		return CLR_E_INVALID_PARAMETER;
	// AT91_PMC &pmc = AT91::PMC();
 //   pmc.EnablePeriphClock(20);


	//CPU_GPIO_DisablePin( 5, RESISTOR_DISABLED, 0, GPIO_ALT_MODE_1 );
	
	AT91_PMC &pmc = AT91::PMC();
	pmc.EnablePeriphClock(AT91C_ID_TSADCC);
	if(channel >= 0 && channel <= ANALOG_MAX_PINS)
	{
		pmc.EnablePeriphClock(AT91C_ID_PIOA);

		CPU_GPIO_DisablePin(AnalogPinTable[channel], RESISTOR_DISABLED, 0, GPIO_ALT_MODE_1);

	}
	else
	{
		return CLR_E_PIN_UNAVAILABLE;
	}

	TOUCHSCREEN_ADC_CONTROLLER_CHANNEL_SELECT = (1 << (unsigned int)channel); // Selects the channel in the register
	// Explanation of the TOUCHSCREEN_ADC_CONTROLLER_MODE_REGISTER
	//
	// PENDET: Pen Detect Selection
	// 0: Disable the Touch screen pins as analog inputs
	// 1: enable the Touch screen pins as analog inputs
	//
	// PRESCAL: Prescaler Rate Selection
	//    ADCCLK = MCK / ( (PRESCAL+1) * 2 )   <-- MCK = 100 MHz
	//
	// SHTIM: Sample & Hold Time for ADC Channels
	//    Programming 0 for SHTIM gives a Sample & Hold Time equal to (2/ADCCLK).
	//       Sample & Hold Time = (SHTIM+1) / ADCCLK
	TOUCHSCREEN_ADC_CONTROLLER_MODE_REGISTER = (1 << 6) /*PENDET*/| (63 << 8) /*PRESCAL*/ | (0xf << 24) /*SHTIM*/;
	TOUCHSCREEN_ADC_CONTROLLER_TRIGGER_REGISTER = 6;

	return 0;
}

void GHI_OSH_HAL_AnalogIn_Uninit(BYTE channel)
{
	if(channel < ANALOG_MAX_PINS)
	{
		CPU_GPIO_DisablePin(AnalogPinTable[channel], RESISTOR_PULLUP, 0, GPIO_ALT_PRIMARY);
		TOUCHSCREEN_ADC_CONTROLLER_CHANNEL_DISABLE_REGISTER = (1 << (unsigned int)channel); // Disables the channel in the register
	}
}

BYTE GHI_OSH_HAL_AnalogIn_GetResolutionBits(BYTE channel)
{
	return 10;
}

GPAL_ERROR GHI_OSH_HAL_AnalogIn_Read(BYTE channel, UINT32 *value)
{
	*value = (*((UINT32*)(TOUCHSCREEN_ADC_CONTROLLER_CHANNEL_DATA_REGISTER_BASE_ADDRESS) + channel));
	return S_OK;
}

GPIO_PIN GHI_OSH_HAL_AnalogIn_GetPin(BYTE channel)
{
	if(channel < ANALOG_MAX_PINS)
		return AnalogPinTable[channel];
	return GPIO_PIN_NONE;
}

