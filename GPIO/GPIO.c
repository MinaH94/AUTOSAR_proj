/*
GPIO Port A (AHB): 0x40058000
GPIO Port B (AHB): 0x40059000
GPIO Port C (AHB): 0x4005A000
GPIO Port D (AHB): 0x4005B000
GPIO Port E (AHB): 0x4005C000
GPIO Port F (AHB): 0x4005D000
*/

#include "GPIO.h"
#include "GPIO_Config.h"

/* RCC module base */
#define SYSTEM_CTRL_BASE (0x400FE000)
/* Port clock control register */
#define RCGCGPIO         (*((volatile u32*)(SYSTEM_CTRL_BASE + 0x608)))

/* Clock enable values */
#define PORTA_CLOCK_ENABLE 0x00000001
#define PORTB_CLOCK_ENABLE 0x00000002
#define PORTC_CLOCK_ENABLE 0x00000004
#define PORTD_CLOCK_ENABLE 0x00000008
#define PORTE_CLOCK_ENABLE 0x00000010
#define PORTF_CLOCK_ENABLE 0x00000020

#define PIN_COUNT 8

typedef struct
{
    u32 GPIODATA;

    const u32 _padding1[255]; /* reserved area */

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


Error_S GPIO_Init(u32 port, u8 pin, u8 direction)
{
    u8 err;
    u32 dir;
    u32 pinMask;

    /* if port value is incorrect */
    if ((GPIO_PORT_A != port) &&
        (GPIO_PORT_B != port) &&
        (GPIO_PORT_C != port) &&
        (GPIO_PORT_D != port) &&
        (GPIO_PORT_E != port) &&
        (GPIO_PORT_F != port))
    {
        err = ERROR_NOK;
    }
    else if (PIN_COUNT <= pin) /* if pin value is outside range */
    {
        err = ERROR_NOK;
    }
    else
    {
        volatile GPIO_t* baseAddr = (volatile GPIO_t*)port;
        pinMask = (u32)1 << pin;

        /* 1- enable port clock */
        switch (port)
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

        /* 2- set direction (input or output) */
        dir = baseAddr->GPIODIR;
        dir &= ~pinMask;
        dir |= direction << pin;
        baseAddr->GPIODIR = dir;

        /* 3- set mode to GPIO (not Alternate Function) */
        baseAddr->GPIOAFSEL &= ~pinMask;

        /* 4- turn pull up/down if input mode */
        if (GPIO_PIN_DIR_INPUT == direction)
        {
#if GPIO_PULL_UP_DOWN == GPIO_PULL_UP
            baseAddr->GPIOPUR |= pinMask;
#elif GPIO_PULL_UP_DOWN == GPIO_PULL_DOWN
            baseAddr->GPIOPDR |= pinMask;
#endif
        }

        /* 5- enable digital I/O mode (not Analog mode) */
        baseAddr->GPIODEN |= pinMask;

        err = ERROR_OK;
    }

    return err;
}





