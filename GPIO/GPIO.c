/*
GPIO In_u32Port A (AHB): 0x40058000
GPIO In_u32Port B (AHB): 0x40059000
GPIO In_u32Port C (AHB): 0x4005A000
GPIO In_u32Port D (AHB): 0x4005B000
GPIO In_u32Port E (AHB): 0x4005C000
GPIO In_u32Port F (AHB): 0x4005D000
*/

#include "STD_TYPES.h"
#include "GPIO.h"
#include "GPIO_Config.h"

/* RCC module base */
#define SYSTEM_CTRL_BASE (0x400FE000)
/* In_u32Port clock control register */
#define RCGCGPIO         (*((volatile u32*)(SYSTEM_CTRL_BASE + 0x608)))

#define	SYSCTRL_GPIOHBCTL				(*(u32*)(SYSTEM_CTRL_BASE+0x06C))


/* Clock enable In_u8Values */
#define PORTA_CLOCK_ENABLE 0x00000001
#define PORTB_CLOCK_ENABLE 0x00000002
#define PORTC_CLOCK_ENABLE 0x00000004
#define PORTD_CLOCK_ENABLE 0x00000008
#define PORTE_CLOCK_ENABLE 0x00000010
#define PORTF_CLOCK_ENABLE 0x00000020

#define In_u8Pin_COUNT 8

typedef struct
{
		const u32 pad=0;
    u32 GPIODATA[256];
    u32 GPIODIR;
    u32 GPIODATA;
    u32 GPIODIR;
    u32 GPIOIS;
    u32 GPIOIBE;
    u32 GPIOIEV;
    u32 GPIOIM;
    u32 GPIORIS;
    u32 GPIOMIS;
    u32 GPIOICR;
    u32 GPIOAFSEL;

    const u32 _padding2[55]; /* reserved area */

    u32 GPIODR2R;
    u32 GPIODR4R;
    u32 GPIODR8R;
    u32 GPIOODR;
    u32 GPIOPUR;
    u32 GPIOPDR;
    u32 GPIOSLR;
    u32 GPIODEN;
    u32 GPIOLOCK;
    u32 GPIOCR;
    u32 GPIOAMSEL;
    u32 GPIOPCTL;
    u32 GPIOADCCTL;
    u32 GPIODMACTL;

    const u32 _padding3[678]; /* reserved area */

    u32 GPIOPeriphID4;
    u32 GPIOPeriphID5;
    u32 GPIOPeriphID6;
    u32 GPIOPeriphID7;
    u32 GPIOPeriphID0;
    u32 GPIOPeriphID1;
    u32 GPIOPeriphID2;
    u32 GPIOPeriphID3;
    u32 GPIOPCellID0;
    u32 GPIOPCellID1;
    u32 GPIOPCellID2;
    u32 GPIOPCellID3;
} GPIO_t;


Error_S GPIO_Init(u32 In_u32Port, u8 In_u8Pin, u8 direction)
{
    u8 err;
    u32 dir;
    u32 pinMask;

    /* if In_u32Port In_u8Value is incorrect */
    if ((GPIO_PORT_A != In_u32Port) &&
        (GPIO_PORT_B != In_u32Port) &&
        (GPIO_PORT_C != In_u32Port) &&
        (GPIO_PORT_D != In_u32Port) &&
        (GPIO_PORT_E != In_u32Port) &&
        (GPIO_PORT_F != In_u32Port))
    {
        err = ERROR_NOK;
    }
    else if (In_u8Pin_COUNT <= In_u8Pin) /* if In_u8Pin In_u8Value is Out_u8Outside range */
    {
        err = ERROR_NOK;
    }
    else
    {
        volatile GPIO_t* baseAddr = (volatile GPIO_t*)In_u32Port;
        PinMask = (u32)1 << In_u8Pin;

        /* 1- enable In_u32Port clock */
        switch (In_u32Port)
        {
        case GPIO_PORT_A:
            RCGCGPIO |= PORTA_CLOCK_ENABLE;
        break;
        
        case GPIO_PORT_B:
            RCGCGPIO |= PORTB_CLOCK_ENABLE;
        break;
        
        case GPIO_PORT_C:
            RCGCGPIO |= PORTC_CLOCK_ENABLE;
        break;
        
        case GPIO_PORT_D:
            RCGCGPIO |= PORTD_CLOCK_ENABLE;
        break;
        
        case GPIO_PORT_E:
            RCGCGPIO |= PORTE_CLOCK_ENABLE;
        break;
        
        case GPIO_PORT_F:
            RCGCGPIO |= PORTF_CLOCK_ENABLE;
        break;
        
        }

        /* 2- set direction (input or Out_u8Output) */
        dir = baseAddr->GPIODIR;
        dir &= ~PinMask;
        dir |= direction << In_u8Pin;
        baseAddr->GPIODIR = dir;

        /* 3- set mode to GPIO (not Alternate Function) */
        baseAddr->GPIOAFSEL &= ~pinmask;

        /* 4- turn pull up/down if input mode */
        if (GPIO_In_u8Pin_DIR_INPUT == direction)
        {
#if GPIO_PULL_UP_DOWN == GPIO_PULL_UP
            baseAddr->GPIOPUR |= pinmask;
#elif GPIO_PULL_UP_DOWN == GPIO_PULL_DOWN
            baseAddr->GPIOPDR |= pinmask;
#endif
        }

        /* 5- enable digital I/O mode (not Analog mode) */
        baseAddr->GPIODEN |= pinmask;

        err = ERROR_OK;
    }

    return err;
}



Error_S SYSCTRL_GPIOBusControl(u8 In_u8In_u32Port, u8 In_u8Bus)
{
	u8 Local_u8Status= ERROR_NOK;
	if(SYSCTRL_APB == In_u8Bus)
	{
		Local_u8Status = ERROR_OK;
		SYSCTRL_GPIOHBCTL &=~ In_u8In_u32Port
	}
	else if(SYSCTRL_AHB == In_u8Bus)
	{
		Local_u8Status = ERROR_OK;
		SYSCTRL_GPIOHBCTL |= In_u8In_u32Port
	}
	return Local_u8Status;
}

Error_S GPIO_ReadIn_u8Pin(u32 In_u32Port, u8 In_u8Pin, u8* Out_u8Out)
{
	u8 err = ERROR_OK;
	    if ((GPIO_PORT_A != In_u32Port) &&
        (GPIO_PORT_B != In_u32Port) &&
        (GPIO_PORT_C != In_u32Port) &&
        (GPIO_PORT_D != In_u32Port) &&
        (GPIO_PORT_E != In_u32Port) &&
        (GPIO_PORT_F != In_u32Port))			
    {
        err = ERROR_NOK;
    }
    else if (
							GPIO_PIN_0!= In_u8Pin) &&
							GPIO_PIN_1!= In_u8Pin) &&
							GPIO_PIN_2!= In_u8Pin) &&
							GPIO_PIN_3!= In_u8Pin) &&
							GPIO_PIN_4!= In_u8Pin) &&
							GPIO_PIN_5!= In_u8Pin) &&		
							GPIO_PIN_6!= In_u8Pin) &&
							GPIO_PIN_7!= In_u8Pin) &&
							GPIO_PIN_8!= In_u8Pin) &&
							GPIO_PIN_9!= In_u8Pin) 					) /* if In_u8Pin In_u8Value is Out_u8Outside range */
    {                  
        err = ERROR_NOK;
    }
    else
    {
        volatile GPIO_t* baseAddr = (volatile GPIO_t*)In_u32Port;
				/*	GPIODATA is mapped to 256 register that read and write operations are mapped to,
						to understand more please go to page 654 in the manual */
			if( 0 < baseAddr->GPIODATA[In_u8Pin] )
			{
				*Out_u8Out = 1;
			}
			else
			{
				*Out_u8Out = 0;
			}
		}
	return err;
}
Error_S GPIO_WriteIn_u8Pin(u32 In_u32Port, u8 In_u8Pin, u8 In_u8Value)
{
	
	u8 err = ERROR_OK;
	    if ((GPIO_PORT_A != In_u32Port) &&
        (GPIO_PORT_B != In_u32Port) &&
        (GPIO_PORT_C != In_u32Port) &&
        (GPIO_PORT_D != In_u32Port) &&
        (GPIO_PORT_E != In_u32Port) &&
        (GPIO_PORT_F != In_u32Port))			
    {
        err = ERROR_NOK;
    }
    else if (
							GPIO_PIN_0!= In_u8Pin) &&
							GPIO_PIN_1!= In_u8Pin) &&
							GPIO_PIN_2!= In_u8Pin) &&
							GPIO_PIN_3!= In_u8Pin) &&
							GPIO_PIN_4!= In_u8Pin) &&
							GPIO_PIN_5!= In_u8Pin) &&		
							GPIO_PIN_6!= In_u8Pin) &&
							GPIO_PIN_7!= In_u8Pin) &&
							GPIO_PIN_8!= In_u8Pin) &&
							GPIO_PIN_9!= In_u8Pin) 					) /* if In_u8Pin In_u8Value is Out_u8Outside range */
    {                  
        err = ERROR_NOK;
    }
    else
    {
				/*	GPIODATA is mapped to 256 register that read and write operations are mapped to,
						to understand more please go to page 654 in the manual */
      volatile GPIO_t* baseAddr = (volatile GPIO_t*)In_u32Port;
			baseAddr->GPIODATA[In_u8Pin] = In_u8Value;
		}
	return err;
}


