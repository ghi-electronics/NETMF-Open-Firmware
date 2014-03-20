#ifndef _HYDRA_RTC_H_
#define _HYDRA_RTC_H_

#include <tinyhal.h>

#define AT91_RTC_TIMR_AM		(0x0)
#define AT91_RTC_TIMR_PM		(0x1)
//#define S_OK					0x00
//#define CLR_E_OUT_OF_RANGE		0x01
#define AT91C_PMC_CSS			(0x3 << 0)

// Real Time Clock Register
#define AT91C_BASE_RTC			0xFFFFFE00//// Real TIme Clock (RTC) Base Address
#define RTC_CR					(*(volatile unsigned long *)(AT91C_BASE_RTC + 0x00))
#define RTC_TIMR				(*(volatile unsigned long *)(AT91C_BASE_RTC + 0x08))
#define RTC_CALR				(*(volatile unsigned long *)(AT91C_BASE_RTC + 0x0C))
#define RTC_SR					(*(volatile unsigned long *)(AT91C_BASE_RTC + 0x18))
#define RTC_SCCR				(*(volatile unsigned long *)(AT91C_BASE_RTC + 0x1C))
#define RTC_VER					(*(volatile unsigned long *)(AT91C_BASE_RTC + 0x2C))

//Slow Clock Configuration Register
#define AT91C_BASE_SCKCR		0xFFFFFD50//// Slow Clock Configuration Register (SCKCR) Base Address
//#define AT91C_BASE_CKGR			0xFFFFFC1C
#define AT91C_PMC_CSS_SLOW_CLK	(0x0)// (PMC) Slow Clock is selected
#define AT91C_PMC_PRES_CLK_64	(0x6 << 2)// (PMC) Selected clock divided by 64
#define AT91C_PMC_MDIV_2		(0x1 << 8)// (PMC) The processor clock is twice as fast as the master clock
#define AT91C_PMC_MCKRDY		(0x1 << 3)// (PMC) Master Clock Status/Enable/Disable/Mask
#define AT91C_CKGR_MOSCEN		(0x1 << 0)// (PMC) Main Oscillator Enable
#define TIMEOUT					10000000
#define AT91C_CKGR_OSCOUNT		(0xFF << 8)// (PMC) Main Oscillator Start-up Time
#define AT91C_PMC_LOCKA			(0x1 << 1)// (PMC) PLL A Status/Enable/Disable/Mask
#define AT91C_SLCKSEL_OSCSEL	(0x1 << 3)// (SYS) OSC Selection

//Power Manager Control Register
#define AT91C_BASE_PMC			0xFFFFFC00//// Slow Clock Configuration Register (SCKCR) Base Address
#define PMC_MCKR				(*(volatile unsigned long *)(AT91C_BASE_PMC + 0x0030))
#define PMC_SR					(*(volatile unsigned long *)(AT91C_BASE_PMC + 0x0068))

#define SCKCR					(*(volatile unsigned long *)(AT91C_BASE_SCKCR + 0x00))
#define CKGR_PLLAR				(*(volatile unsigned long *)(AT91C_BASE_CKGR + 0x00000028))
#define CKGR_MOR				(*(volatile unsigned long *)(AT91C_BASE_CKGR + 0x00000020))

#endif // _OSH_GPAL_CONFIG_H_
