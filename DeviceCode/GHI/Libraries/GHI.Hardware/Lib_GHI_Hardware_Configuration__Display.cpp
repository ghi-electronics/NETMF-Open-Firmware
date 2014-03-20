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
#include "Lib_GHI_Hardware_Configuration__Display.h"
#include <..\DeviceCode\GHI\include\Configuration.h>

using namespace GHI::Hardware;

INT8 Configuration_Display::NativeGetBootupMessage( HRESULT &hr )
{
    INT8 retVal = 0; 
    return retVal;
}

INT8 Configuration_Display::NativeSetBootupMessage( INT8 param0, HRESULT &hr )
{
    INT8 retVal = 0; 
    return retVal;
}

UINT8 Configuration_Display::NativeGetRotation( HRESULT &hr )
{
    UINT8 retVal = 0; 
    return retVal;
}

INT8 Configuration_Display::NativeSetRotation( UINT8 param0, HRESULT &hr )
{
    INT8 retVal = 0; 
    return retVal;
}

void Configuration_Display::NativeGetConfiguration( UINT32* Width, UINT32* Height, INT8* OutputEnableIsFixed, INT8* OutputEnablePolarity, INT8* HorizontalSyncPolarity, INT8* VerticalSyncPolarity, INT8* PixelPolarity, UINT8* HorizontalSyncPulseWidth, UINT8* HorizontalBackPorch, UINT8* HorizontalFrontPorch, UINT8* VerticalSyncPulseWidth, UINT8* VerticalBackPorch, UINT8* VerticalFrontPorch, UINT32* PixelClockRate, HRESULT &hr )
{
}

INT8 Configuration_Display::NativeSetConfiguration( UINT32 Width, UINT32 Height, INT8 OutputEnableIsFixed, INT8 OutputEnablePolarity, INT8 HorizontalSyncPolarity, INT8 VerticalSyncPolarity, INT8 PixelPolarity, UINT8 HorizontalSyncPulseWidth, UINT8 HorizontalBackPorch, UINT8 HorizontalFrontPorch, UINT8 VerticalSyncPulseWidth, UINT8 VerticalBackPorch, UINT8 VerticalFrontPorch, UINT32 PixelClockRateKHz, HRESULT &hr )
{
	BOOL didChange;

	if (((Width * Height) > (800 * 600)) || (Width < 64) ||  (Height < 64))
	{
		hr = CLR_E_OUT_OF_RANGE;
		return FALSE;
	}

	Configuration_LCD_Structure config;

	config.Width = Width;
    config.Height = Height;

	//config.PriorityEnable = PriorityEnable; // Not implemented Used to determine if LCD Config is present in config sector

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

	config.PixelClockRateKHz = PixelClockRateKHz;

	config.Magic = 0xdeadbeef;

	config.reserved = 0x09;
	config.reserved2 = 0x15;

	hr = Configuration_LCD_Set(&config, &didChange);

	return didChange;
}

