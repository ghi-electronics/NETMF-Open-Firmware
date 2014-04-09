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
#include "Lib_GHI_Networking_EthernetENC28J60.h"

using namespace GHI::Networking;

bool ENC28J60Ethernet_Network_Interface_IsCableConnected();
void ENC28J60Ethernet_Netwrok_Interface_SetHalConfig(INT32 spi, INT32 chipSelect, INT32 externalInterrupt, INT32 clockRateKhz);

void EthernetENC28J60::NativeSetHalConfig( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
	ENC28J60Ethernet_Netwrok_Interface_SetHalConfig(Get_spi(pMngObj), Get_chipSelect(pMngObj), Get_externalInterrupt(pMngObj), Get_clockRate(pMngObj));
}

INT8 EthernetENC28J60::NativeIsCableConnected( CLR_RT_HeapBlock* pMngObj, HRESULT &hr )
{
    return ENC28J60Ethernet_Network_Interface_IsCableConnected();
}

