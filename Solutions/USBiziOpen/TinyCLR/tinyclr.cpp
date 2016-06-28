////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <tinyclr_application.h>
#include <tinyhal.h>

////////////////////////////////////////////////////////////////////////////////

//#define UGLY_LCD_FIX 1
#if defined(UGLY_LCD_FIX)
#include "..\DeviceCode\Display\TFT-G240320LTSW-118W.h"
#include "..\..\DeviceCode\Targets\Native\LPC24XX\DeviceCode\LCDC\LPC24XX_LCDC.h"
extern G240320LTSW_Driver g_G240320LTSW_Driver;
#endif


extern int  s_CLR_RT_fTrace_Errors;
extern int  s_CLR_RT_fTrace_Exceptions;
//extern int  s_CLR_RT_fTrace_Instructions;
//extern int  s_CLR_RT_fTrace_Memory;
//extern int  s_CLR_RT_fTrace_MemoryStats;
//extern int  s_CLR_RT_fTrace_StopOnFAILED;
////extern int  s_CLR_RT_fTrace_GC;
//extern int  s_CLR_RT_fTrace_GC_Depth;
//extern int  s_CLR_RT_fTrace_SimulateSpeed;
////extern int  s_CLR_RT_fTrace_AssemblyOverhead;


void ApplicationEntryPoint()
{
    CLR_SETTINGS clrSettings;

    memset(&clrSettings, 0, sizeof(CLR_SETTINGS));

    clrSettings.MaxContextSwitches         = 50;
    clrSettings.WaitForDebugger            = false;
    clrSettings.EnterDebuggerLoopAfterExit = true;

#if defined(UGLY_LCD_FIX)
    LPC24XX_LCDC & LCDC = *(LPC24XX_LCDC *)LPC24XX_LCDC::c_LCDC_Base;

    /*LCDC.LCD_CTRL &= ~CLCDC_LCDCTRL_ENABLE;
    debug_printf("DISABLING and REENABLING THE LCD NOW\r\n");
    Events_WaitForEventsInternal(0, 1*1000);
    LCDC.LCD_CTRL |= CLCDC_LCDCTRL_ENABLE;*/
    debug_printf("DISABLE and REENABLE THE LCD NOW\r\n");
    Events_WaitForEvents(0, 5*1000);

    G240320LTSW_Driver::Display_Init( g_G240320LTSW_Config.LcdConfig );
#endif

    ClrStartup( clrSettings );

 s_CLR_RT_fTrace_Errors = 4; // To see errors?
 s_CLR_RT_fTrace_Exceptions = 4; // To see exceptions?
// s_CLR_RT_fTrace_Instructions = 4; // To see ??
//// s_CLR_RT_fTrace_GC = 4; // To see Garbage Collector
//s_CLR_RT_fTrace_GC_Depth = 4; // To see ??
//// s_CLR_RT_fTrace_AssemblyOverhead = 4; //To see assemblies

#if !defined(BUILD_RTM)
    debug_printf( "Exiting.\r\n" );
#else
    ::CPU_Reset();
#endif
}


BOOL Solution_GetReleaseInfo(MfReleaseInfo& releaseInfo)
{
    MfReleaseInfo::Init(releaseInfo,
                        VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD, VERSION_REVISION,
                        OEMSYSTEMINFOSTRING, hal_strlen_s(OEMSYSTEMINFOSTRING)
                        );
    return TRUE; // alternatively, return false if you didn't initialize the releaseInfo structure.
}

