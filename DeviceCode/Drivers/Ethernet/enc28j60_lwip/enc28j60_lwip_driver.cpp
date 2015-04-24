#include <tinyhal.h>
#include "net_decl_lwip.h"
#include "enc28j60_lwip.h"

extern "C"
{
#include "netif\etharp.h"
#include "lwip\dhcp.h"
#include "lwip\tcpip.h"
#include "lwip\dns.h"
}

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section zidata = "g_ENC28J60_LWIP_Driver"
#endif

static ENC28J60_LWIP_Driver g_ENC28J60_LWIP_Driver;
static struct netif         g_ENC28J60_NetIF;

HAL_CONTINUATION    enc28j60_InterruptTaskContinuation;
HAL_COMPLETION      enc28j60_LwipUpTimeCompletion;
static UINT32       enc28j60_LwipNetworkStatus = 0;
static UINT32       enc28j60_LwipLastIpAddress = 0;

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section zidata
#endif

extern ENC28J60_HAL_CONFIG   g_enc28j60_hal_config;
extern NETWORK_CONFIG                g_NetworkConfig;
const SOCK_NetworkConfiguration *g_enc28j60_iface;
static int g_enc28j60_index = -1;

extern unsigned short enc28j60_lwip_read_phy_register(SPI_CONFIGURATION *spiConf, UINT8 registerAddress);
extern BOOL enc28j60_get_link_status(SPI_CONFIGURATION* spiConf);
bool enc28j60_WasRaisedCableConnectionEvent = false;

void enc28j60_status_callback(struct netif *netif)
{
//    if(enc28j60_LwipLastIpAddress != netif->ip_addr.addr)
//    {
//        Network_PostEvent( NETWORK_EVENT_TYPE_ADDRESS_CHANGED, 0 | ((1<< g_enc28j60_index)<<1));
//        enc28j60_LwipLastIpAddress = netif->ip_addr.addr;
//    }
    // TQD I separated to many cases that can raise an event.
    BOOL raiseEvent = FALSE;
    UINT32 connectionStatus = enc28j60_get_link_status(&g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config);
    if (g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_DHCP) // DHCP is enable
    {
        if (connectionStatus == FALSE) // Not connect
        {
            if (enc28j60_LwipLastIpAddress != netif->ip_addr.addr && enc28j60_LwipLastIpAddress!=0)
            {
                raiseEvent = TRUE;
            }
        }
        else // connected
        {
            if (enc28j60_LwipLastIpAddress != netif->ip_addr.addr && enc28j60_LwipLastIpAddress==0)
            {
                 raiseEvent = TRUE;
            }
        }
    }
    else // staticIP is enable
    {
        if (enc28j60_LwipNetworkStatus!=connectionStatus /*&& connectionStatus == TRUE*/) // Only raise event when connected if staticIP
        {
            raiseEvent = TRUE;
        }
    }
	if (enc28j60_WasRaisedCableConnectionEvent == false && raiseEvent)  // Incase event is raised internally, not from completion, we want the cable connection is raised 
    {
      if (EMAC_LwipNetworkStatus == 0 && connectionStatus == 1)
      {
          Network_PostEvent( NETWORK_EVENT_TYPE__AVAILABILITY_CHANGED, NETWORK_EVENT_FLAGS_IS_AVAILABLE  | ((1<< g_enc28j60_index)<<1));          
      }
    } 
    if (raiseEvent)
    {
        Network_PostEvent( NETWORK_EVENT_TYPE_ADDRESS_CHANGED, 0 | ((1<< g_enc28j60_index)<<1));
        enc28j60_LwipLastIpAddress = netif->ip_addr.addr;
    }
     enc28j60_LwipNetworkStatus = connectionStatus;

#if defined(_DEBUG)
    lcd_printf("\f\n\n\n\n\n\nLink Update: %s\n", (netif_is_up(netif) ? "UP  " : "DOWN") );
    lcd_printf("        IP: %d.%d.%d.%d\n", (netif->ip_addr.addr >>  0) & 0xFF, 
                                             (netif->ip_addr.addr >>  8) & 0xFF,
                                             (netif->ip_addr.addr >> 16) & 0xFF,
                                             (netif->ip_addr.addr >> 24) & 0xFF);
    lcd_printf("        SM: %d.%d.%d.%d\n", (netif->netmask.addr >>  0) & 0xFF, 
                                             (netif->netmask.addr >>  8) & 0xFF,
                                             (netif->netmask.addr >> 16) & 0xFF,
                                             (netif->netmask.addr >> 24) & 0xFF);    
    lcd_printf("        GW: %d.%d.%d.%d\n", (netif->gw.addr >>  0) & 0xFF, 
                                             (netif->gw.addr >>  8) & 0xFF,
                                             (netif->gw.addr >> 16) & 0xFF,
                                             (netif->gw.addr >> 24) & 0xFF);
    debug_printf("IP Address: %d.%d.%d.%d\n", (netif->ip_addr.addr >>  0) & 0xFF, 
                                             (netif->ip_addr.addr >>  8) & 0xFF,
                                             (netif->ip_addr.addr >> 16) & 0xFF,
                                             (netif->ip_addr.addr >> 24) & 0xFF);
#if LWIP_DNS
    if(netif->flags & NETIF_FLAG_DHCP)
    {
        struct ip_addr dns1 = dns_getserver(0);
        struct ip_addr dns2 = dns_getserver(1);
        
        lcd_printf("         dns1: %d.%d.%d.%d\n",(dns1.addr >>  0) & 0xFF, 
                                                  (dns1.addr >>  8) & 0xFF,
                                                  (dns1.addr >> 16) & 0xFF,
                                                  (dns1.addr >> 24) & 0xFF);
        
        lcd_printf("         dns2: %d.%d.%d.%d\n",(dns2.addr >>  0) & 0xFF, 
                                                  (dns2.addr >>  8) & 0xFF,
                                                  (dns2.addr >> 16) & 0xFF,
                                                  (dns2.addr >> 24) & 0xFF);
    }
#endif
#endif
}

err_t   enc28j60_ethhw_init( netif * myNetIf) 
{ 
    myNetIf->mtu = ETHERSIZE;

    myNetIf->flags = NETIF_FLAG_IGMP | NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET;

    /* ethhw_init() is user-defined */
    /* use ip_input instead of ethernet_input for non-ethernet hardware */
    /* (this function is assigned to netif.input and should be called by the hardware driver) */

    /* Assign the xmit routine to the stack's netif and call the driver's Open */
    myNetIf->output = etharp_output;
    myNetIf->linkoutput = enc28j60_lwip_xmit;
    myNetIf->status_callback = enc28j60_status_callback;

    enc28j60_lwip_open( myNetIf );

    return ERR_OK; 
}

void lwip_interrupt_continuation( )
{
    //NATIVE_PROFILE_PAL_NETWORK();
    GLOBAL_LOCK(irq);
    
    if(!enc28j60_InterruptTaskContinuation.IsLinked())
    {
        enc28j60_InterruptTaskContinuation.Enqueue();
    }
}

void lwip_network_uptime_completion(void *arg)
{
    //NATIVE_PROFILE_PAL_NETWORK(); // G120 is not happy with this	
		
   UINT32 status = enc28j60_get_link_status(&g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config);
	if(g_enc28j60_iface !=NULL)
	{
		if(status != enc28j60_LwipNetworkStatus)
		{
			struct netif* pNetIf = (struct netif*)arg;
        
			if(status)
			{
				if(SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE == (g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE))
				{
					if(g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_DHCP)
					{
						netif_set_addr(pNetIf, 0, 0, 0);
						BOOL fDhcpStarted = (0 != (pNetIf->flags & NETIF_FLAG_DHCP));
						if(!fDhcpStarted)
							dhcp_start( pNetIf );
					}
					tcpip_timeout(100, (sys_timeout_handler)netif_set_link_up, (void*)pNetIf);
					tcpip_timeout(100, (sys_timeout_handler)netif_set_up, (void*)pNetIf);
				}
				enc28j60_WasRaisedCableConnectionEvent = true;
				Network_PostEvent( NETWORK_EVENT_TYPE__AVAILABILITY_CHANGED, NETWORK_EVENT_FLAGS_IS_AVAILABLE| ((1<< g_enc28j60_index)<<1) );
			}
			else
			{
				
				if(SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE == (g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE))
				{
					tcpip_callback((sys_timeout_handler)netif_set_link_down, (void*)pNetIf);
					tcpip_callback((sys_timeout_handler)netif_set_down, (void*)pNetIf);
					if(g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_DHCP)
					{
						netif_set_addr(pNetIf, 0, 0, 0); // This is important for some DHCP servers that do not accpet DHCP requests from IPs other than 0.0.0.0
					}
				}

				Network_PostEvent( NETWORK_EVENT_TYPE__AVAILABILITY_CHANGED, 0| ((1<< g_enc28j60_index)<<1));
			}

			Events_Set(SYSTEM_EVENT_FLAG_SOCKET);
			Events_Set(SYSTEM_EVENT_FLAG_NETWORK);

			//enc28j60_LwipNetworkStatus = status; // TQD => We will update in callback function
			if(SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE == (g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE))
			{
                                enc28j60_status_callback(pNetIf);
                        }
                        else // TQD Do we need it? this is called after netif.Open() so it is alway active, but I still keep it here for sure
                        {
                              enc28j60_LwipNetworkStatus = status;
                        }
		}
      
	}

    enc28j60_LwipUpTimeCompletion.EnqueueDelta64( 2000000 );
    
}

void  ENC28J60_Network_Interface_ForceUpdateActivationStatus(bool activate)
{
#if 0	// TQD Do we need these? I use completion + callback to control the status network - All event should be raise after netif.Open().
    NATIVE_PROFILE_PAL_NETWORK();

    UINT16 phyStat = 0;
    
    {
        GLOBAL_LOCK(irq);

        phyStat = enc28j60_lwip_read_phy_register(&g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config, ENC28J60_PHSTAT2);
    }

    // linkstatus bit
    UINT32 status = ((phyStat >> ENC28J60_PHSTAT2_LSTAT_BIT) & 1);

	if(g_enc28j60_iface != NULL)
	{
		struct netif* pNetIf = &g_ENC28J60_NetIF;

		if(activate && status)
		{
			if(g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_DHCP)
			{
				netif_set_addr(pNetIf, 0, 0, 0);
				BOOL fDhcpStarted = (0 != (pNetIf->flags & NETIF_FLAG_DHCP));
				if(!fDhcpStarted)
					dhcp_start( pNetIf );
			}
			tcpip_timeout(100, (sys_timeout_handler)netif_set_link_up, (void*)pNetIf);
			tcpip_timeout(100, (sys_timeout_handler)netif_set_up, (void*)pNetIf);
		}
		else
		{
			tcpip_callback((sys_timeout_handler)netif_set_link_down, (void*)pNetIf);
			tcpip_callback((sys_timeout_handler)netif_set_down, (void*)pNetIf);
			netif_set_addr(pNetIf, 0, 0, 0); // This is important for some DHCP servers that do not accpet DHCP requests from IPs other than 0.0.0.0
		}
		Events_Set(SYSTEM_EVENT_FLAG_SOCKET);
		Events_Set(SYSTEM_EVENT_FLAG_NETWORK);
	}
#endif
        enc28j60_LwipUpTimeCompletion.EnqueueDelta64( 2000000 ); // TQD Start completion for next 2 seconds
}

void InitContinuations( struct netif* pNetIf )
{
    enc28j60_InterruptTaskContinuation.InitializeCallback( (HAL_CALLBACK_FPN)enc28j60_lwip_interrupt, &g_ENC28J60_NetIF );

    enc28j60_LwipUpTimeCompletion.InitializeForUserMode( (HAL_CALLBACK_FPN)lwip_network_uptime_completion, pNetIf );
    
    //enc28j60_LwipUpTimeCompletion.EnqueueDelta64( 2000000 ); // TQD should not start completion here, should start after netif.Open() so easier to control event
}

void ENC28J60_Network_Interface_SetAsDefaultInterfaces(int index)
{
	netif_set_default( &g_ENC28J60_NetIF );
}

BOOL ENC28J60_Network_Interface_Bind(int index)
{
    NATIVE_PROFILE_HAL_DRIVERS_ETHERNET();
    return g_ENC28J60_LWIP_Driver.Bind(&g_enc28j60_hal_config.DeviceConfigs[0], index); //We support only one ENC28J60 interface [0]
}
int  ENC28J60_Network_Interface_Open(int index)
{
    NATIVE_PROFILE_HAL_DRIVERS_ETHERNET();
	       
    HAL_CONFIG_BLOCK::ApplyConfig( ENC28J60_HAL_CONFIG::GetDriverName(), &g_enc28j60_hal_config, sizeof(g_enc28j60_hal_config) );// This needs to be replace with something more dynamic that is independant from Config
    return g_ENC28J60_LWIP_Driver.Open(&g_enc28j60_hal_config.DeviceConfigs[0], index); //We support only one ENC28J60 interface [0]
	
}
BOOL ENC28J60_Network_Interface_Close(int index)
{
    NATIVE_PROFILE_HAL_DRIVERS_ETHERNET();
	return g_ENC28J60_LWIP_Driver.Close(&g_enc28j60_hal_config.DeviceConfigs[0], index); //We support only one ENC28J60 interface [0]
}

int ENC28J60_LWIP_Driver::Open(ENC28J60_LWIP_DRIVER_CONFIG* config, int index )
{
    NATIVE_PROFILE_HAL_DRIVERS_ETHERNET();

    /* Network interface variables */
    struct ip_addr ipaddr, netmask, gw;
    struct netif *pNetIF;
    int len;
	if(config == NULL) return -1;

    enc28j60_LwipLastIpAddress = 0; // Reset IP
    enc28j60_LwipNetworkStatus = 0; // Reset connection   
	enc28j60_WasRaisedCableConnectionEvent = false;
    /* Apply network configuration */
    g_enc28j60_index = index;
    g_enc28j60_iface = &g_NetworkConfig.NetworkInterfaces[index];

    if(0 == (g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_DHCP))
    {
        ipaddr.addr  = g_enc28j60_iface->ipaddr;
        gw.addr      = g_enc28j60_iface->gateway;
        netmask.addr = g_enc28j60_iface->subnetmask;
    }
    else
    {
        /* Set network address variables - this will be set by either DHCP or when the configuration is applied */
        IP4_ADDR(&gw     ,   0,   0,   0, 0);
        IP4_ADDR(&ipaddr ,   0,   0,   0, 0);
        IP4_ADDR(&netmask, 255, 255, 255, 0);
    }


    len = g_ENC28J60_NetIF.hwaddr_len;

    if(len == 0 || g_enc28j60_iface->macAddressLen < len)
    {
        len = g_enc28j60_iface->macAddressLen;
        g_ENC28J60_NetIF.hwaddr_len = len;
    }
   
    memcpy(g_ENC28J60_NetIF.hwaddr, g_enc28j60_iface->macAddressBuffer, len);

    g_ENC28J60_NetIF.flags = NETIF_FLAG_IGMP | NETIF_FLAG_BROADCAST;
        
    pNetIF = netif_add( &g_ENC28J60_NetIF, &ipaddr, &netmask, &gw, NULL, enc28j60_ethhw_init, ethernet_input );
       
    /* Enable the INTERRUPT pin */                            
    if (CPU_GPIO_EnableInputPin2(config->INT_Pin, 
                                 FALSE,                                                         /* Glitch filter enable */
                                 (GPIO_INTERRUPT_SERVICE_ROUTINE) &enc28j60_lwip_pre_interrupt, /* ISR                  */
                                 &g_ENC28J60_NetIF,                                             /* minor number         */
                                 GPIO_INT_EDGE_LOW ,                                            /* Interrupt edge       */
                                 RESISTOR_PULLUP) == FALSE)                                     /* Resistor State       */
    {
        return -1;
    }

//	UINT16 phyStat = 0;
//	 {
//        GLOBAL_LOCK(irq);
//
//        phyStat = enc28j60_lwip_read_phy_register(&g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config, ENC28J60_PHSTAT2);
//	}
//	 enc28j60_LwipNetworkStatus = ((phyStat >> ENC28J60_PHSTAT2_LSTAT_BIT) & 1); => TQD removed => This will fix bug if the cable connected at the second time, event won't be raised because status connection is same
//	
//	 
//	if(SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE == (g_enc28j60_iface->flags & SOCK_NETWORKCONFIGURATION_FLAGS_ACTIVE_INTERFACE))
//	{
//		
//		netif_set_default( pNetIF );
//		// if (enc28j60_LwipNetworkStatus)  // TQD let completion handle that => should not in initialize
//		// {
//			// netif_set_up( pNetIF );
//			// netif_set_link_up( pNetIF );
//		// }
//	}
	
    /* Enable the CHIP SELECT pin */
    if (CPU_GPIO_EnableInputPin (config->SPI_Config.DeviceCS, 
                            FALSE, 
                            NULL,
                            GPIO_INT_NONE,
                            RESISTOR_PULLUP) == FALSE)
    {
        return -1;                          
    }
    
    /* Initialize the continuation routine for the driver interrupt and receive */    
    InitContinuations( pNetIF );
    
    return g_ENC28J60_NetIF.num;
    
}

BOOL ENC28J60_LWIP_Driver::Close( ENC28J60_LWIP_DRIVER_CONFIG* config, int index )
{
    NATIVE_PROFILE_HAL_DRIVERS_ETHERNET();
	g_enc28j60_index = -1;
    if(config == NULL) return FALSE;

	if( g_ENC28J60_NetIF.num >0)
	{
    enc28j60_LwipUpTimeCompletion.Abort();
	netif_set_link_down( &g_ENC28J60_NetIF );
    netif_set_down( &g_ENC28J60_NetIF );
    netif_remove( &g_ENC28J60_NetIF );

    /* Disable the INTERRUPT pin */     
	 if(config->INT_Pin !=GPIO_PIN_NONE)
    CPU_GPIO_EnableInputPin2(config->INT_Pin, 
                              FALSE,                         /* Glitch filter enable */
                              NULL,                          /* ISR                  */
                              0,                             /* minor number         */
                              GPIO_INT_NONE,                 /* Interrupt edge       */
                              RESISTOR_PULLUP);              /* Resistor State       */

    enc28j60_InterruptTaskContinuation.Abort();

    
    
    enc28j60_lwip_close( &g_ENC28J60_NetIF );
	 }
    enc28j60_LwipNetworkStatus = 0;

    memset(&g_ENC28J60_NetIF, 0, sizeof(g_ENC28J60_NetIF));
    enc28j60_LwipLastIpAddress = 0; // Reset IP
    enc28j60_LwipNetworkStatus = 0; // Reset connection  
    return TRUE;

}

BOOL  ENC28J60_LWIP_Driver::Bind  ( ENC28J60_LWIP_DRIVER_CONFIG* config, int index )
{
    NATIVE_PROFILE_HAL_DRIVERS_ETHERNET();

    return TRUE;    
}

    

bool ENC28J60Ethernet_Network_Interface_IsCableConnected()
{

	UINT16 phyStat = 0;
    
    {
        GLOBAL_LOCK(irq);

        phyStat = enc28j60_lwip_read_phy_register(&g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config, ENC28J60_PHSTAT2);
    }

    // linkstatus bit
    UINT32 status = ((phyStat >> ENC28J60_PHSTAT2_LSTAT_BIT) & 1);

	if(status)
		return true;
	else
		return false;

}
void ENC28J60Ethernet_Netwrok_Interface_SetHalConfig(INT32 spi, INT32 chipSelect, INT32 externalInterrupt, INT32 clockRateKhz)
{
	g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config.SPI_mod = spi;
	g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config.Clock_RateKHz = clockRateKhz;
	g_enc28j60_hal_config.DeviceConfigs[0].SPI_Config.DeviceCS = (GPIO_PIN)chipSelect;
	g_enc28j60_hal_config.DeviceConfigs[0].INT_Pin = (GPIO_PIN)externalInterrupt;
}
