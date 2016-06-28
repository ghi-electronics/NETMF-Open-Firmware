////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) GHI Electronics, LLC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <GHI_OSH_Drivers\Include\GHI_OSH_HAL.h>

#define MAX_PWM_PINS 3

#define PWM_MODE_REGISTER				(*(volatile unsigned long *)0xFFFC8000)
#define PWM_ENABLE_REGISTER				(*(volatile unsigned long *)0xFFFC8004)
#define PWM_DISABLE_REGISTER			(*(volatile unsigned long *)0xFFFC8008)
#define PWM_INTERUPT_ENABLE_REGISTER	(*(volatile unsigned long *)0xFFFC8010)
#define PWM_INTERUPT_DISABLE_REGISTER	(*(volatile unsigned long *)0xFFFC8014)

//#define PWM_CDTY0 (*(volatile unsigned long *)0xFFFC8204)
//#define PWM_CDTY1 (*(volatile unsigned long *)0xFFFC8224)
//#define PWM_CDTY2 (*(volatile unsigned long *)0xFFFC8244)
//
//#define PWM_CPRD0 (*(volatile unsigned long *)0xFFFC8208)
//#define PWM_CPRD1 (*(volatile unsigned long *)0xFFFC8228)
//#define PWM_CPRD2 (*(volatile unsigned long *)0xFFFC8248)

#define PWM_CMR0 (*(volatile unsigned long *)0xFFFC8200)
#define PWM_CMR1 (*(volatile unsigned long *)0xFFFC8220)
#define PWM_CMR2 (*(volatile unsigned long *)0xFFFC8240)


unsigned int PMW_PinTable[MAX_PWM_PINS] = {
	AT91_GPIO_Driver::PD14, 
	AT91_GPIO_Driver::PD15, 
	AT91_GPIO_Driver::PD16}; 

volatile unsigned long *PWM_ChannelModeRegister[MAX_PWM_PINS] = {
	(volatile unsigned long *)0xFFFC8200,	// PWM_CPRD0
	(volatile unsigned long *)0xFFFC8220,	// PWM_CPRD1
	(volatile unsigned long *)0xFFFC8240};	// PWM_CPRD2

volatile unsigned long *PWM_DutyRegister[MAX_PWM_PINS] = {
	(volatile unsigned long *)0xFFFC8204,	// PWM_CDTY0
	(volatile unsigned long *)0xFFFC8224,	// PWM_CDTY1
	(volatile unsigned long *)0xFFFC8244};	// PWM_CDTY2

volatile unsigned long *PWM_PeriodRegister[MAX_PWM_PINS] = {
	(volatile unsigned long *)0xFFFC8208,	// PWM_CPRD0
	(volatile unsigned long *)0xFFFC8228,	// PWM_CPRD1
	(volatile unsigned long *)0xFFFC8248};	// PWM_CPRD2


// PWM
GPAL_ERROR GHI_OSH_HAL_PWM_Init(BYTE channel)
{
	if(channel > MAX_PWM_PINS)
		return CLR_E_INVALID_PARAMETER;

	AT91_PMC &pmc = AT91::PMC();
	pmc.EnablePeriphClock(AT91C_ID_PWMC);

	PWM_MODE_REGISTER = (1 << 16);
	PWM_ENABLE_REGISTER = (1 << channel);
	PWM_INTERUPT_ENABLE_REGISTER = (1 << channel);

	*PWM_ChannelModeRegister[channel] = (volatile unsigned long)0x2;

	return GHI_OSH_HAL_PWM_Set(channel, FALSE);
}

void GHI_OSH_HAL_PWM_Uninit(BYTE channel)
{
	if(channel < MAX_PWM_PINS && (channel != 0))
		CPU_GPIO_DisablePin(PMW_PinTable[channel], RESISTOR_PULLUP, 0, GPIO_ALT_PRIMARY);
	PWM_DISABLE_REGISTER = (1 << channel);
	PWM_INTERUPT_DISABLE_REGISTER = (1 << channel);
}

GPIO_PIN GHI_OSH_HAL_PWM_GetPin(BYTE channel)
{
	if(channel < MAX_PWM_PINS)
		return PMW_PinTable[channel];

	return GPIO_PIN_NONE;
}

GPAL_ERROR GHI_OSH_HAL_PWM_SetPulse(BYTE channel, UINT32 period_ns, UINT32 highTime_ns)
{
	if(channel > MAX_PWM_PINS)
		return CLR_E_INVALID_PARAMETER;

	if(period_ns == 0 || highTime_ns == 0)
	{
		return GHI_OSH_HAL_PWM_Set(channel, FALSE);
	}
	else if(period_ns == highTime_ns)
	{
		return GHI_OSH_HAL_PWM_Set(channel, TRUE);
	}

	CPU_GPIO_DisablePin(PMW_PinTable[channel], RESISTOR_DISABLED, 0, GPIO_ALT_MODE_2);

	// 18M/M = 18 * period / 1000 to get legal value.
	//UINT32 periodTicks = (UINT64)((SYSTEM_CLOCK_HZ / 1000000)) * period_ns / 1000;
	//UINT32 highTicks = (UINT64)((SYSTEM_CLOCK_HZ / 1000000)) * highTime_ns / 1000;

	// re-scale with new frequency!
	//if((PWM1MR0 != periodTicks))
	//{
	//	// Reset Timer Counter
	//	PWM1TCR |= (1<<1);
	//	PWM1MR0=periodTicks;
	//	PWM1MCR=(1<<1);//reset on MAT0
	//	PWM1TCR=1;//enable
	//}

	//*MATCH_ADDRESSES[channel]= highTicks;	
	*PWM_PeriodRegister[channel] = (volatile unsigned long)(period_ns / 40);
	*PWM_DutyRegister[channel] = (volatile unsigned long)(highTime_ns / 40);
	return S_OK;
}

GPAL_ERROR GHI_OSH_HAL_PWM_Set(BYTE channel, BOOL state)
{
	if(channel > MAX_PWM_PINS)
		return CLR_E_INVALID_PARAMETER;

	GPIO_PIN pin = GHI_OSH_HAL_PWM_GetPin(channel);

	CPU_GPIO_EnableOutputPin(pin, state);

	return S_OK;
}

