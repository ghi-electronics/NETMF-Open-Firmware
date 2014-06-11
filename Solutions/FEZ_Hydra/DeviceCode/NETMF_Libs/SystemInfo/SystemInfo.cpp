#include <GHI\Include\Common.h>
#include <GHI\Include\GHI_OSHW_HAL.h>

void OSHW_GHAL_GetOemModelSku(BYTE *oem, BYTE *model, UINT16 *sku)
{
	*oem = GHI_CONFIG_OEM_NUMBER;
	*model = GHI_HYDRA_MODEL;
	*sku = GHI_CONFIG_SKU_NUMBER;
}
void GHI_OSHW_ResetCLR()
{
	HAL_Initialize();
	HAL_Uninitialize();
}