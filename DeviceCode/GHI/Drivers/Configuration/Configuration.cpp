#include <tinyhal.h>
#include <..\DeviceCode\GHI\include\Configuration.h>

#define CONFIGURATION_DRIVER_NAME		"HYDRA_CONFIG"
#define DEFAULT_VALUE						0xFF

Configurations_Structure Configurations;

BOOL Configuration_Read()
{
	return HAL_CONFIG_BLOCK::ApplyConfig(CONFIGURATION_DRIVER_NAME, &Configurations, sizeof(Configurations_Structure));
}

BOOL Configuration_Write()
{
	return HAL_CONFIG_BLOCK::UpdateBlockWithName(CONFIGURATION_DRIVER_NAME, &Configurations, sizeof(Configurations_Structure), TRUE);
}

GPAL_ERROR Configuration_LCD_Get(Configuration_LCD_Structure *config)
{
	if (Configuration_Read() == FALSE)
	{
		memset(&Configurations, 0xFF, sizeof(Configurations_Structure));
		Configurations.header.Enable = TRUE;
		Configuration_Write();
	}

	if (!Configuration_Read())
		return -1;

	memcpy(config, &Configurations.lcd, sizeof(Configuration_LCD_Structure));

	return S_OK;
}


GPAL_ERROR Configuration_LCD_Set(Configuration_LCD_Structure *config, BOOL *didChange)
{
	*didChange = FALSE;

	if(Configuration_Read() == FALSE)
	{
		memset(&Configurations, 0xFF, sizeof(Configurations_Structure));
		Configurations.header.Enable = TRUE;
		Configuration_Write();
	}

	if(!Configuration_Read())
		return -1;

	// did it change?
	if(memcmp(config, &Configurations.lcd, sizeof(Configuration_LCD_Structure)))
	{
		memcpy(&Configurations.lcd, config, sizeof(Configuration_LCD_Structure));

		if(!Configuration_Write())
			return -1;

		*didChange = TRUE;
	}

	return S_OK;
}
