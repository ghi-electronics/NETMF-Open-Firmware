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
#include "Lib_GHI_Processor_Display.h"
#include <..\DeviceCode\GHI\include\Configuration.h>

using namespace GHI::Processor;

void Display::NativeGetLcdConfiguration( INT8* bootupMessages, UINT8* rotation, UINT32* Width, UINT32* Height, INT8* OutputEnableIsFixed, INT8* OutputEnablePolarity, INT8* HorizontalSyncPolarity, INT8* VerticalSyncPolarity, INT8* PixelPolarity, UINT8* HorizontalSyncPulseWidth, UINT8* HorizontalBackPorch, UINT8* HorizontalFrontPorch, UINT8* VerticalSyncPulseWidth, UINT8* VerticalBackPorch, UINT8* VerticalFrontPorch, UINT32* PixelClockRate, HRESULT &hr )
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

INT8 Display::NativeSetLcdConfiguration( INT8 bootupMessages, UINT8 rotation, UINT32 Width, UINT32 Height, INT8 OutputEnableIsFixed, INT8 OutputEnablePolarity, INT8 HorizontalSyncPolarity, INT8 VerticalSyncPolarity, INT8 PixelPolarity, UINT8 HorizontalSyncPulseWidth, UINT8 HorizontalBackPorch, UINT8 HorizontalFrontPorch, UINT8 VerticalSyncPulseWidth, UINT8 VerticalBackPorch, UINT8 VerticalFrontPorch, UINT32 PixelClockRate, HRESULT &hr )
{
	BOOL didChange = FALSE;
	
	if (bootupMessages != TRUE || rotation != 0)
	{
		hr = CLR_E_NOT_SUPPORTED;
		return FALSE;
	}
	
	if (((Width * Height) > (800 * 600)))
	{
		hr = CLR_E_OUT_OF_RANGE;
		return FALSE;
	}

	if (Width < 64 || Height < 64)
	{
		Width = 64;
		Height = 64;
		PixelClockRate = 0;
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

INT8 Display::NativeSetSpiConfiguration(INT32 bpp, INT32 rotation, INT32 controlPin, INT32 backlightPin, INT32 resetPin, INT32 width, INT32 height, INT32 chipSelectPin, INT8 chipSelectActiveState, INT32 chipSelectSetupTime, INT32 chipSelectHoldTime, INT8 clockIdleState, INT8 clockEdge, INT32 clockRateKHz, INT32 spiModule, HRESULT &hr)
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}

INT8 Display::NativeSetTouchPins( UINT32 yu, UINT32 xl, UINT32 yd, UINT32 xr, UINT32 ya, UINT32 xa, HRESULT &hr )
{
	hr = CLR_E_NOT_SUPPORTED;
	
    return 0;
}
