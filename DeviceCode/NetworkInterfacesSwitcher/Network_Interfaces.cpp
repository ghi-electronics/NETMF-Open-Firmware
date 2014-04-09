#include <tinyhal.h>
#include "net_decl_lwip.h"
extern "C"
{
#include "netif\etharp.h"
#include "lwip\dhcp.h"
#include "lwip\tcpip.h"
#include "lwip\dns.h"
}
extern NETWORK_CONFIG g_NetworkConfig;

#define INTERFACE_INDEX_BUILT_IN_ETHERNET 0
#define INTERFACE_INDEX_ENC28j60_ETHERNET 1
#define INTERFACE_INDEX_RS9110_WIFI       2
#define INTERFACE_INDEX_PPP_SERIAL_MODEM  3

// void  BuiltInEthernet_Network_Interface_SetAsDefaultInterfaces(int index);
// void  BuiltInEthernet_Network_Interface_ForceUpdateActivationStatus(bool activate);
// BOOL  BuiltInEthernet_Network_Interface_Bind(int index);
// int   BuiltInEthernet_Network_Interface_Open(int index);
// BOOL  BuiltInEthernet_Network_Interface_Close(int index);

void ENC28J60_Network_Interface_SetAsDefaultInterfaces(int index);
void ENC28J60_Network_Interface_ForceUpdateActivationStatus(bool activate);
BOOL ENC28J60_Network_Interface_Bind(int index);
int  ENC28J60_Network_Interface_Open(int index);
BOOL ENC28J60_Network_Interface_Close(int index);

// void RS9110_Network_Interface_SetAsDefaultInterfaces(int index);
// void RS9110_Network_Interface_ForceUpdateActivationStatus(bool activate);
// BOOL RS9110_Network_Interface_Bind(int index);
// int  RS9110_Network_Interface_Open(int index);
// BOOL RS9110_Network_Interface_Close(int index);

volatile int debug_nw_cnt=0;
void Network_Interface_SetAsDefauiltInterfaces(int index)
{
	switch (index)
	{
		case -1:
			netif_set_default(NULL);
		break;
		case INTERFACE_INDEX_BUILT_IN_ETHERNET:
			// Not support
		break;

		case INTERFACE_INDEX_ENC28j60_ETHERNET:
			ENC28J60_Network_Interface_SetAsDefaultInterfaces(index);
		break;

		case INTERFACE_INDEX_RS9110_WIFI:
			// Not support
		break;
		case INTERFACE_INDEX_PPP_SERIAL_MODEM:
			
		break;

		default:
			
		break;
	}

}
BOOL Network_Interface_Bind(int index)
{
	switch (index)
	{
		case INTERFACE_INDEX_BUILT_IN_ETHERNET:
			return false;
		break;

		case INTERFACE_INDEX_ENC28j60_ETHERNET:
			return ENC28J60_Network_Interface_Bind(index);
		break;

		case INTERFACE_INDEX_RS9110_WIFI:
			return false;
		break;
		case INTERFACE_INDEX_PPP_SERIAL_MODEM:
			return false;
		break;

		default:
			return false;
		break;
	}

   return false;
}
int  Network_Interface_Open(int index)
{
   switch (index)
	{
		case INTERFACE_INDEX_BUILT_IN_ETHERNET:
			return false;
		break;

		case INTERFACE_INDEX_ENC28j60_ETHERNET:
			return ENC28J60_Network_Interface_Open(index);
		break;

		case INTERFACE_INDEX_RS9110_WIFI:
			return false;
		break;
		case INTERFACE_INDEX_PPP_SERIAL_MODEM:
			return SOCK_SOCKET_ERROR;
		break;

		default:
			return SOCK_SOCKET_ERROR;
		break;
	}
   return SOCK_SOCKET_ERROR;
}
BOOL Network_Interface_Close(int index)
{
	switch (index)
	{
		case INTERFACE_INDEX_BUILT_IN_ETHERNET:
			return false;
		break;
		
		case INTERFACE_INDEX_ENC28j60_ETHERNET:
			return ENC28J60_Network_Interface_Close(index);
		break;

		case INTERFACE_INDEX_RS9110_WIFI:
			return false;
		break;	
		
		case INTERFACE_INDEX_PPP_SERIAL_MODEM:
			return false;
		break;

		default:
			return false;
		break;
	}
	return false;
 }


bool Network_Interface_IsActivated(int index)
{
	bool res = false;
	if(SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE == (g_NetworkConfig.NetworkInterfaces[index].flags & SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE))
		res = true;
	return res;
}

//GHI specific
void Network_Interface_ForceUpdateActivationStatus(int index, bool activate)
{
	switch (index)
	{
		case INTERFACE_INDEX_BUILT_IN_ETHERNET:
			
		break;

		case INTERFACE_INDEX_ENC28j60_ETHERNET:
			ENC28J60_Network_Interface_ForceUpdateActivationStatus(activate);
		break;

		case INTERFACE_INDEX_RS9110_WIFI:
			
		break;
		case INTERFACE_INDEX_PPP_SERIAL_MODEM:
			
		break;

		default:
			
		break;
	}
}
void Network_Interface_Activate(int index)
{
	g_NetworkConfig.NetworkInterfaces[index].flags|=SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE;
	Network_Interface_ForceUpdateActivationStatus(index,true);
	HAL_SOCK_CONFIGURATION_UpdateAdapterConfiguration(index, SOCK_NETWORKCONFIGURATION_UPDATE_DHCP | SOCK_NETWORKCONFIGURATION_UPDATE_DNS, &g_NetworkConfig.NetworkInterfaces[index]);
}

//void SOCKETS_CloseConnections();
void Network_Interface_Deactivate(int index)
{
	//SOCKETS_CloseConnections();
	g_NetworkConfig.NetworkInterfaces[index].flags &= ~SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE;
	Network_Interface_ForceUpdateActivationStatus(index,false);
}

UINT8 Network_Interface_GetActivatedInterfaces()
{
    UINT8 retVal = 0;
	for(int i =0; i < g_NetworkConfig.NetworkInterfaceCount; i++)
	{
		if(Network_Interface_IsActivated(i))
			retVal|=1<<i;	
	}
    return retVal;
}

void Network_Interface_SaveNetworkConfigurations( )
{
    HAL_CONFIG_BLOCK::UpdateBlockWithName(g_NetworkConfig.GetDriverName(), &g_NetworkConfig, sizeof(g_NetworkConfig), true);
}

void Network_Interface_UpdateMacAddressConfig(int index,UINT8* mac)
{
	memcpy(g_NetworkConfig.NetworkInterfaces[index].macAddressBuffer, mac, 6); 
	
}