//-----------------------------------------------------------------------------
// Software that is described herein is for illustrative purposes only  
// which provides customers with programming information regarding the  
// products. This software is supplied "AS IS" without any warranties.  
// NXP Semiconductors assumes no responsibility or liability for the 
// use of the software, conveys no license or title under any patent, 
// copyright, or mask work right to the product. NXP Semiconductors 
// reserves the right to make changes in the software without 
// notification. NXP Semiconductors also make no representation or 
// warranty that such application will be suitable for the specified 
// use without further testing or modification. 
//-----------------------------------------------------------------------------

#include <tinyhal.h>
#include "..\LPC24XX.h"

// these routines depend on which platform is being used
extern void Initialize_SyncOn();
extern void BootstrapCode_Clocks();
extern void BootstrapCode_Pins();
extern void BootstrapCode_Ext_SRAM();
extern void BootstrapCode_Ext_SDRAM();
extern void BootstrapCode_Ext_Flash();



#pragma arm section code = "SectionForBootstrapOperations"

// Dummy function force code generation for the following bootstrap functions
//void __section(SectionForBootstrapOperations) BootstrapCode_Dummy()
//{
//}

extern "C"
{
void __section(SectionForBootstrapOperations) BootstrapCode()
{
    // Clocks, Pins and Memory init done in board specefic bootstrap code
	 // Disconnect the PLL if already connected
    if ((LPC24XX::SYSCON().PLLSTAT & LPC24XX_SYSCON::CNCTD ))
    {
        LPC24XX::SYSCON().PLLCON  = LPC24XX_SYSCON::PLLE;
        LPC24XX::SYSCON().PLLFEED = 0xAA;
        LPC24XX::SYSCON().PLLFEED = 0x55;
    }
    
    // Disable the PLL
    LPC24XX::SYSCON().PLLCON  = 0x0;
    LPC24XX::SYSCON().PLLFEED = 0xAA;
    LPC24XX::SYSCON().PLLFEED = 0x55;
    
    // Enable the Oscillator and wait for it to be stable
    LPC24XX::SYSCON().SCS = (LPC24XX::SYSCON().SCS | LPC24XX_SYSCON::OSCEN);
    while ( ((LPC24XX::SYSCON().SCS & LPC24XX_SYSCON::READY) == 0) )
    {
    }
    
    // Select Main Oscillator as the PLL clock source
    LPC24XX::SYSCON().CLKSRCSEL = LPC24XX_SYSCON::OSC;
    
    // See platform_USBizi_selector.h
    LPC24XX::SYSCON().PLLCFG  = (((PLL_NVAL-1) << 16) | (PLL_MVAL-1));
    LPC24XX::SYSCON().PLLCON  = LPC24XX_SYSCON::PLLE;
    LPC24XX::SYSCON().PLLFEED = 0xAA;
    LPC24XX::SYSCON().PLLFEED = 0x55;
   
    // Wait while PLL locks
    while ( (LPC24XX::SYSCON().PLLSTAT & LPC24XX_SYSCON::LOCKD) == 0x0 )
    {
    }
    
    // Enable MAM
    LPC24XX::SYSCON().MAMTIM = 3;
    LPC24XX::SYSCON().MAMCR = 2;

    // Set CCLK and USB clock divider
    LPC24XX::SYSCON().CCLKCFG = (CCLK_DIVIDER-1);
    LPC24XX::SYSCON().USBCLKCFG = (USB_DIVIDER-1);
    
    // PLL locked now connect it
    LPC24XX::SYSCON().PLLCON = (LPC24XX_SYSCON::PLLC | LPC24XX_SYSCON::PLLE);
    LPC24XX::SYSCON().PLLFEED = 0xAA;
    LPC24XX::SYSCON().PLLFEED = 0x55;

    // See LPC24XX_prestackinit.s


    //enable EMAC so we can use its ram
    LPC24XX::SYSCON().PCONP =0xffffffff;
    
    
    // Implement bootstrap code
    PrepareImageRegions();

    	//set UART 0 and 1 to be clock/1
	LPC24XX::SYSCON().PCLKSEL0 |= (1<<6) | (1<<8);
}
}

#pragma arm section code


///////////////////////////////////////////////////////////////////////////////
