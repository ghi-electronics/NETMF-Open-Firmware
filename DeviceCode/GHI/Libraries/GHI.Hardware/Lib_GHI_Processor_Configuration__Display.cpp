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
#include "Lib_GHI_Processor_Configuration__Display.h"
#include <..\DeviceCode\GHI\include\Configuration.h>

using namespace GHI::Processor;

void Configuration_Display::NativeGetLcdConfiguration( INT8* bootupMessages, UINT8* rotation, UINT32* Width, UINT32* Height, INT8* OutputEnableIsFixed, INT8* OutputEnablePolarity, INT8* HorizontalSyncPolarity, INT8* VerticalSyncPolarity, INT8* PixelPolarity, UINT8* HorizontalSyncPulseWidth, UINT8* HorizontalBackPorch, UINT8* HorizontalFrontPorch, UINT8* VerticalSyncPulseWidth, UINT8* VerticalBackPorch, UINT8* VerticalFrontPorch, UINT32* PixelClockRate, HRESULT &hr )
{
    *rotation = 0;
	*bootupMessages = 1;
	
	Configuration_LCD_Structure config;
	
	hr = Configuration_LCD_Get(&config);
	
	*Width = config.Width;
    *Height = config.Height;
    
	*OutputEnableIsFixed = config.OutputEnableIsFixed;
	*OutputEnablePolarity = config.OutputEnablePolarity;
    
	*HorizontalSyncPolarity = config.HorizontalSyncPolarity;
	*VerticalSyncPolarity = config.VerticalSyncPolarity;
	*PixelPolarity = config.PixelPolarity;
    
    *HorizontalSyncPulseWidth = config.HorizontalSyncPulseWidth;
    *HorizontalBackPorch = config.HorizontalBackPorch;
    *HorizontalFrontPorch = config.HorizontalFrontPorch;
    *VerticalSyncPulseWidth = config.VerticalSyncPulseWidth;
    *VerticalBackPorch = config.VerticalBackPorch;
    *VerticalFrontPorch = config.VerticalFrontPorch;
	
	*PixelClockRate = config.PixelClockRateKHz;
}

INT8 Configuration_Display::NativeSetLcdConfiguration( INT8 bootupMessages, UINT8 rotation, UINT32 Width, UINT32 Height, INT8 OutputEnableIsFixed, INT8 OutputEnablePolarity, INT8 HorizontalSyncPolarity, INT8 VerticalSyncPolarity, INT8 PixelPolarity, UINT8 HorizontalSyncPulseWidth, UINT8 HorizontalBackPorch, UINT8 HorizontalFrontPorch, UINT8 VerticalSyncPulseWidth, UINT8 VerticalBackPorch, UINT8 VerticalFrontPorch, UINT32 PixelClockRate, HRESULT &hr )
{
	BOOL didChange = FALSE;
	
	if (bootupMessages != TRUE || rotation != 0)
	{
		hr = CLR_E_NOT_SUPPORTED;
		return FALSE;
	}
	
	if (((Width * Height) > (800 * 600)) || (Width < 64) ||  (Height < 64))
	{
		hr = CLR_E_OUT_OF_RANGE;
		return FALSE;
	}

	Configuration_LCD_Structure config;

      config.PriorityEnable = TRUE;
	config.Width = Width;
    config.Height = Height;

	config.OutputEnableIsFixed = OutputEnableIsFixed;
	config.OutputEnablePolarity = OutputEnablePolarity;

	config.HorizontalSyncPolarity = HorizontalSyncPolarity;
	config.VerticalSyncPolarity = VerticalSyncPolarity;
	config.PixelPolarity = PixelPolarity;

    config.HorizontalSyncPulseWidth = HorizontalSyncPulseWidth;
    config.HorizontalBackPorch = HorizontalBackPorch;
    config.HorizontalFrontPorch = HorizontalFrontPorch;
    config.VerticalSyncPulseWidth = VerticalSyncPulseWidth;
    config.VerticalBackPorch = VerticalBackPorch;
    config.VerticalFrontPorch = VerticalFrontPorch;

	config.PixelClockRateKHz = PixelClockRate;

	config.Magic = 0xdeadbeef;

	config.reserved = 0x09;
	config.reserved2 = 0x15;

	hr = Configuration_LCD_Set(&config, &didChange);

	return didChange;
}

INT8 Configuration_Display::NativeSetSpiConfiguration( INT32 param0, INT32 param1, INT32 param2, INT32 param3, INT8 param4, INT8 param5, INT8 param6, INT32 param7, INT32 param8, INT32 param9, INT32 param10, INT32 param11, INT8 param12, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}
