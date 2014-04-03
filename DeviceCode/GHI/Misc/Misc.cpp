#include <GHI\Include\GHI_OSHW_HAL.h>

void OSHW_GHAL_Initialize_Startup()
{
	BYTE oem, model;
	UINT16 sku;

	OSHW_GHAL_GetOemModelSku(&oem, &model, &sku);
	
	OEM_Model_SKU.OEM = oem;
	OEM_Model_SKU.Model = model;
	OEM_Model_SKU.SKU = sku;
}
