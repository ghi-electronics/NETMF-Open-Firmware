#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <..\DeviceCode\GHI\include\GHI_OSHW_HAL.h>
// LCD //
struct Configuration_LCD_Structure
{
	UINT32 Width;
    UINT32 Height;

	UINT32 PriorityEnable; 

	UINT32 OutputEnableIsFixed;
	UINT32 OutputEnablePolarity;

	UINT32 HorizontalSyncPolarity;
	UINT32 VerticalSyncPolarity;
	UINT32 PixelPolarity;

    UINT8 HorizontalSyncPulseWidth;
    UINT8 HorizontalBackPorch;
    UINT8 HorizontalFrontPorch;
    UINT8 VerticalSyncPulseWidth;
    UINT8 VerticalBackPorch;
    UINT8 VerticalFrontPorch;
	UINT8 reserved;		// not currently used but keeps it aligned
	UINT8 reserved2;		// not currently used but keeps it aligned
	
	UINT32 PixelClockRateKHz;

	UINT32 Magic; //If not 0xdeadbeef, configuration will not load

	

};

#define Configurations_Structure_SIZE	128

struct Configurations_Structure
{
	HAL_DRIVER_CONFIG_HEADER header; // 4 Bytes

	Configuration_LCD_Structure lcd; // 40 bytes 44 bytes with Magic // Now 48 with new PixelClockRateKHz and extra reserved byte.

	UINT8 resserved[76]; // substact from this when you add to keep at 128 // Was 80 without the added 4 bytes.
};

extern Configurations_Structure		Configurations;
extern Configuration_LCD_Structure	Configuration_LCD;
//////////

void OSHW_Configuration_Initialize();
BOOL Configuration_Read();
BOOL Configuration_Write();

GPAL_ERROR Configuration_LCD_Set(Configuration_LCD_Structure *config, BOOL *didChange);
GPAL_ERROR Configuration_LCD_Get(Configuration_LCD_Structure *config);

#endif // _OSH_GPAL_CONFIG_H_