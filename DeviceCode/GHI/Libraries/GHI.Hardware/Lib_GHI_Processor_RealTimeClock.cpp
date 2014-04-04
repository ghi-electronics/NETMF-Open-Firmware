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
#include "Lib_GHI_Processor_RealTimeClock.h"
#include<..\DeviceCode\GHI\Include\RTC.h>

using namespace GHI::Processor;

void SLCK_SetSlowClockMode()
{
	UINT32 oldPll;
	UINT32 oldMck;
	UINT32 timeout = 0;
	UINT32 timeInSlowClockMode = 10;
	oldPll = CKGR_PLLAR;
	oldMck = PMC_MCKR;
	timeout = 0;

	while (0 == (PMC_SR & AT91C_PMC_MCKRDY) && timeout++ < TIMEOUT) ;
	// Stop PLL A
	// MULA: PLL A Multiplier 0 = The PLL A is deactivated.
	CKGR_PLLAR = 0x00003f00;
	// Stop Main Oscillator
	CKGR_MOR = (CKGR_MOR & (~AT91C_CKGR_MOSCEN));
	// Wait a while. The clock is at 500Hz...
	while ((timeInSlowClockMode--) > 0) ;
	// End !  
	CKGR_MOR = (CKGR_MOR | (AT91C_CKGR_OSCOUNT & (0x32 << 8)));
	CKGR_MOR = (CKGR_MOR | AT91C_CKGR_MOSCEN);

	CKGR_PLLAR = oldPll;
	timeout = 0;
	while (0 == (PMC_SR & AT91C_PMC_LOCKA) && timeout++ < TIMEOUT) ;

	PMC_MCKR = oldMck;
	timeout = 0;

	while (0 == (PMC_SR & AT91C_PMC_MCKRDY) && timeout++ < TIMEOUT) ;
}

bool SLCK_Is32k()
{
	return ((SCKCR & AT91C_SLCKSEL_OSCSEL) != 0);
}

bool InitializeCrystal_32768()
{
	UINT32 tmp;
	tmp = PMC_MCKR;

	if ((tmp & AT91C_PMC_CSS) == 0)
	{
		//Debug.Print("The master clock use the slow clock. ");
		return true;
	}

	if (SLCK_Is32k())
	{
		//Debug.Print("The slow clock is already the external 32.768kHz crystal. ");
		return true;
	}

	tmp = SCKCR;
	//Page 270
	//Enable the 32,768 Hz oscillator by setting the bit OSC32EN to 1.
	SCKCR |= (1 << 1);
	//Wait 32,768 Hz Startup Time for clock stabilization (software loop).
	HAL_Time_Sleep_MicroSeconds(100000);
	//Switch from internal RC to 32,768 Hz oscillator by setting the bit OSCSEL to 1.
	SCKCR |= (1 << 3);
	//Wait 5 slow clock cycles for internal resynchronization.
	HAL_Time_Sleep_MicroSeconds(100000);
	//Disable the RC oscillator by setting the bit RCEN to 0.
	SCKCR &= ~(1 << 0);

	tmp = SCKCR;
	tmp = PMC_SR;
	SLCK_SetSlowClockMode();
	return true;
}

void BinaryCodedDecimalExtract(UINT32 ValueToConvert, UINT32 &tens, UINT32 &ones)
{
	tens = ValueToConvert / 10;
	ones = ValueToConvert % 10;
}

UINT32 BinaryCodedDecimalCombine(UINT32 tens, UINT32 ones)
{
	UINT32 CombinedBinaryCodedDecimal = 0;
	CombinedBinaryCodedDecimal = tens * 10;
	CombinedBinaryCodedDecimal += ones;
	return CombinedBinaryCodedDecimal;
}

bool RealTimeClock_IsTimeValid()
{
    if (RTC_VER > 0)
        return false;
    return true;
}
void RealTimeClock::NativeSetTime( INT32 year, INT32 month, INT32 day, INT32 dayOfWeek, INT32 hour, INT32 minute, INT32 second, INT32 millisecond, HRESULT &hr )
{
	if ((PMC_MCKR & AT91C_PMC_CSS) != 0)
	{
		InitializeCrystal_32768();
	}
	
	UINT32 CalenderRegister = 0;
	UINT32 TimeRegister = 0;
	UINT32 LowerHundredYears = 0;
	UINT32 Tens = 0;
	UINT32 Ones = 0;

	RTC_CR = 0x2; // Sets the Calander to write mode.
	while ((RTC_SR & 0x1) == 0); // Checks to see if the calander mode is ready to write.
	
	
	RTC_SCCR = 0x1; // Once acknowledged, the acknowledge bit is cleared.
	
	
	while ((RTC_SR & 0x4) == 0);

	if ((year < 1900) || (year > 2099) || (month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		hr = CLR_E_OUT_OF_RANGE;
		return;
	}

	if (year < 2000)
	{
		CalenderRegister |= ((0x1 << 4) | 0x9);
		LowerHundredYears = year - 1900;
	}
	else
	{
		CalenderRegister |= ((0x2 << 4) | 0x0);
		LowerHundredYears = year - 2000;
	}

	// Add year
	BinaryCodedDecimalExtract(LowerHundredYears, Tens, Ones);
	CalenderRegister |= (UINT32)((Tens << 12) | (Ones << 8));
	// Add month
	BinaryCodedDecimalExtract(month, Tens, Ones);
	CalenderRegister |= (UINT32)((Tens << 20) | (Ones << 16));
	// Add dayOfWeek
	CalenderRegister |= (UINT32)(((dayOfWeek + 1 ) << 21)); // NetMF uses 0~6 for Sun through Sat, Atmel uses 1~7.
	// Add day
	BinaryCodedDecimalExtract(day, Tens, Ones);
	CalenderRegister |= (UINT32)((Tens << 28) | (Ones << 24));
	HAL_Time_Sleep_MicroSeconds(500000);

	// Write Calender to register
	RTC_CALR = CalenderRegister;

	
	while ((RTC_SR & 0x4) == 0);
	RTC_SCCR = 0x4; // Clears the flag that the proper time has passed.
	
	
	//HAL_Time_Sleep_MicroSeconds(1000000);
	TimeRegister = 0;
	RTC_CR = 0x1;
	while ((TimeRegister & 0x1) == 0)
	{
		TimeRegister = RTC_SR;
	}
	while (TimeRegister != 0)
	{
		TimeRegister = RTC_TIMR;
		RTC_TIMR = 0;
	}
	// Add hour
	BinaryCodedDecimalExtract(hour, Tens, Ones);
	TimeRegister = (UINT32)((AT91_RTC_TIMR_AM << 22) | (Tens << 20) | (Ones << 16));
	RTC_TIMR = TimeRegister;
	// Add minute
	BinaryCodedDecimalExtract(minute, Tens, Ones);
	TimeRegister = (UINT32)((Tens << 12) | (Ones << 8));
	RTC_TIMR |= TimeRegister;
	// Add second
	BinaryCodedDecimalExtract(second, Tens, Ones);
	TimeRegister = (UINT32)((Tens << 4) | Ones);
	RTC_TIMR |= TimeRegister;
	// Clear Status Register
	RTC_SCCR |= (1 << 2);
	RTC_CR &= ~((1 << 0) | (1 << 1));
	hr = S_OK;
}

void RealTimeClock::NativeGetTime( INT32* year, INT32* month, INT32* day, INT32* hour, INT32* minute, INT32* second, INT32* millisecond, HRESULT &hr )
{
	UINT32 CalenderRegister = 0;
	UINT32 TimeRegister = 0;
	UINT32 FullYear = 0;
	UINT32 HundredYear = 0;
	UINT32 Hour = 0;
	CalenderRegister = RTC_CALR;
	TimeRegister = RTC_TIMR;

	if (RealTimeClock_IsTimeValid() == false)
	{
		*year = 1977;
		*month = 1;
		*day = 1;
		*hour = 1;
		*minute = 1;
		*second = 1;
		*millisecond = 1;
	}
	else
	{
		if ((CalenderRegister & 0x7F) == 0x19)
			FullYear = 1900;
		else if ((CalenderRegister & 0x7F) == 0x20)
			FullYear = 2000;
		HundredYear = BinaryCodedDecimalCombine((((CalenderRegister & (0xFF << 8)) >> 8) >> 4), (((CalenderRegister & (0xFF << 8)) >> 8) & 0xF));
		*year = (UINT32)(FullYear + HundredYear);
		*month = (UINT32)BinaryCodedDecimalCombine((((CalenderRegister & (0x1F << 16)) >> 16) >> 4), (((CalenderRegister & (0x1F << 16)) >> 16) & 0xF));
		*day = (UINT32)BinaryCodedDecimalCombine((((CalenderRegister & (0x3F << 24)) >> 24) >> 4), (((CalenderRegister & (0x3F << 24)) >> 24) & 0xF));
		Hour = BinaryCodedDecimalCombine((((TimeRegister & (0x3F << 16)) >> 16) >> 4), (((TimeRegister & (0x3F << 16)) >> 16) & 0xF));

		if (((TimeRegister & 0x400000) >> 22) == AT91_RTC_TIMR_PM)
			*hour = (UINT32)Hour + 12;
		else
			*hour = (UINT32)Hour;

		*minute = (UINT32)BinaryCodedDecimalCombine((((TimeRegister & (0x7F << 8)) >> 8) >> 4), (((TimeRegister & (0x7F << 8)) >> 8) & 0xF));
		*second = (UINT32)BinaryCodedDecimalCombine(((TimeRegister & 0x7F) >> 4), ((TimeRegister & 0x7F) & 0xF));
		*millisecond = 1;
	}
	hr = S_OK;
}

void RealTimeClock::NativeSetAlarm( INT32 param0, INT32 param1, INT32 param2, INT32 param3, INT32 param4, INT32 param5, INT32 param6, INT32 param7, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
}

