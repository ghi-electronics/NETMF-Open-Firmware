#include <tinyhal.h>
#include <enc28j60_lwip_driver.h>

//--//


#define ENC28J60_INT                   GPIO_PIN_NONE//26 // Since we are using dynamic Networking interfaces then this is not important
#define ENC28J60_CS                    GPIO_PIN_NONE//2 // Since we are using dynamic Networking interfaces then this is not important
#define ENC28J60_CS_ACTIVE             FALSE
#define ENC28J60_MSK_IDLE              FALSE
#define ENC28J60_MSK_SAMPLE_EDGE       TRUE
#define ENC28J60_16BIT_OP              FALSE
#define ENC28J60_CLOCK_RATE_KHZ        8000 //25000
#define ENC28J60_CS_SETUP_USEC         0
#define ENC28J60_CS_HOLD_USEC          0
#define ENC28J60_MODULE                0  // Since we are using dynamic Networking interfaces then this is not important
#define ENC28J60_BUSYPIN               GPIO_PIN_NONE
#define ENC28J60_BUSYPIN_ACTIVESTATE   FALSE

//--//

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rwdata = "g_enc28j60_hal_config"
#endif


ENC28J60_HAL_CONFIG g_enc28j60_hal_config =
{
    {
        {                                   // ENC28J60_DRIVER_CONFIG

      		{                               // SPI_CONFIGURATION
                ENC28J60_CS,
                ENC28J60_CS_ACTIVE,
                ENC28J60_MSK_IDLE,
                ENC28J60_MSK_SAMPLE_EDGE,
                ENC28J60_16BIT_OP,
                ENC28J60_CLOCK_RATE_KHZ,
                ENC28J60_CS_SETUP_USEC,
                ENC28J60_CS_HOLD_USEC,
                ENC28J60_MODULE,
				//GPIO_PIN_NONE,
                {
                    ENC28J60_BUSYPIN,
                    ENC28J60_BUSYPIN_ACTIVESTATE,
                },
            },
            
            ENC28J60_INT,                    // Interrupt Pin
        },
    }
};

#if defined(ADS_LINKER_BUG__NOT_ALL_UNUSED_VARIABLES_ARE_REMOVED)
#pragma arm section rwdata
#endif


