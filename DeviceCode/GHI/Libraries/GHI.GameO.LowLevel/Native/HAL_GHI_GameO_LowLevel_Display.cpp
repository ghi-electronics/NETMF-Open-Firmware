#include "HAL.h"
#include "HAL_GHI_GameO_LowLevel_Display.h"
#include "..\..\..\Drivers\FSMC\FT1505_LCD\LCD.h"

using namespace GHI::GameO::LowLevel;

#define ORIENTATION_ROT_0 0
#define ORIENTATION_ROT_90 1
#define ORIENTATION_ROT_180 2
#define ORIENTATION_ROT_270 3

#define PERIPH_BB_BASE ((UINT32)0x42000000) /*!< Peripheral base address in the bit-band region */
#define PERIPH_BASE ((UINT32)0x40000000) /*!< Peripheral base address in the alias region */
#define APB1PERIPH_BASE PERIPH_BASE
#define PWR_BASE (APB1PERIPH_BASE + 0x7000)
#define PWR_OFFSET (PWR_BASE - PERIPH_BASE)
#define CSR_OFFSET (PWR_OFFSET + 0x04)
#define EWUP_BIT_NUMBER 0x08
#define CSR_EWUP_BB (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (EWUP_BIT_NUMBER * 4))

extern INT32 g_SpecialDisplayConfigOrientation; //Defined in STM32F4_Display.cpp

static void DrawImage(UINT16* u16, UINT16 xDst, UINT16 yDst, UINT16 xSrc, UINT16 ySrc, UINT16 imageWidth, UINT16 imageHeight, UINT16 drawWidth, UINT16 drawHeight)
{
	UINT16 SCREEN_WIDTH = LCD_GetWidth() * 2;
	UINT16 SCREEN_HEIGHT = LCD_GetHeight() * 2;
	
	switch ((g_SpecialDisplayConfigOrientation + 3) % 4)
	{
		case ORIENTATION_ROT_0:
			LCD_SetDrawingWindow(xDst, yDst, drawWidth, drawHeight);

			for (int a = 0, i = ySrc; a < drawHeight; a++, i++)
				for (int b = 0, j = xSrc; b < drawWidth; b++, j++)
					LCD_WriteData(u16[i * imageWidth + j]);

			break;

		case ORIENTATION_ROT_90:
			LCD_SetDrawingWindow(yDst, SCREEN_WIDTH - xDst - drawWidth, drawHeight, drawWidth);
		
			for (int a = 0, i = xSrc + drawWidth - 1; a < drawWidth; a++, i--)
				for (int b = 0, j = ySrc; b < drawHeight; b++, j++)
					LCD_WriteData(u16[j * imageWidth + i]);

			break;

		case ORIENTATION_ROT_180:
			LCD_SetDrawingWindow(SCREEN_WIDTH - xDst - drawWidth, SCREEN_HEIGHT - yDst - drawHeight, drawWidth, drawHeight);
		
			for (int a = 0, i = ySrc + drawHeight - 1; a < drawHeight; a++, i--)
				for (int b = 0, j = xSrc + drawWidth - 1; b < drawWidth; b++, j--)
					LCD_WriteData(u16[i * imageWidth + j]);

			break;

		case ORIENTATION_ROT_270:
			LCD_SetDrawingWindow(SCREEN_HEIGHT - yDst - drawHeight, xDst, drawHeight, drawWidth);
		
			for (int a = 0, i = xSrc; a < drawWidth; a++, i++)
				for (int b = 0, j = ySrc + drawHeight - 1; b < drawHeight; b++, j--)
					LCD_WriteData(u16[j * imageWidth + i]);

			break;
	}
}

void Display::Initialize( HRESULT &hr )
{
	LCD_PinConfig();
	LCD_Init();
	*(volatile UINT32*)CSR_EWUP_BB = (UINT32)TRUE; //Power wake up pin
}

void Display::WriteRaw( UINT16 data, HRESULT &hr )
{
	LCD_WriteData(data);
}

void Display::WriteRaw( CLR_RT_TypedArray_UINT8 data, INT32 offset, INT32 count, HRESULT &hr )
{
	for (INT32 i = offset; i < offset + count; i += 2)
		LCD_WriteData((data[i] << 8) | data[i + 1]);
}

void Display::WriteRaw( CLR_RT_TypedArray_UINT16 data, INT32 offset, INT32 count, HRESULT &hr )
{
	for (INT32 i = offset; i < offset + count; i++)
		LCD_WriteData(data[i]);
}

void Display::SetRegister( UINT16 reg, HRESULT &hr )
{
   LCD_SetRegister(reg);
}

void Display::WriteRegister( UINT16 reg, UINT16 value, HRESULT &hr )
{
	LCD_WriteRegister(reg, value);
}

void Display::SetDrawWindow( UINT16 x, UINT16 y, UINT16 width, UINT16 height, HRESULT &hr )
{
	LCD_SetDrawingWindow(x, y, width, height);
}

void Display::DrawImage( CLR_RT_TypedArray_UINT8 data, UINT16 xDst, UINT16 yDst, UINT16 xSrc, UINT16 ySrc, UINT16 imageWidth, UINT16 imageHeight, UINT16 drawWidth, UINT16 drawHeight, HRESULT &hr )
{
	::DrawImage((UINT16*)data.GetBuffer(), xDst, yDst, xSrc, ySrc, imageWidth, imageHeight, drawWidth, drawHeight);
}

void Display::DrawImage( CLR_RT_TypedArray_UINT16 data, UINT16 xDst, UINT16 yDst, UINT16 xSrc, UINT16 ySrc, UINT16 imageWidth, UINT16 imageHeight, UINT16 drawWidth, UINT16 drawHeight, HRESULT &hr )
{
	::DrawImage(data.GetBuffer(), xDst, yDst, xSrc, ySrc, imageWidth, imageHeight, drawWidth, drawHeight);
}
