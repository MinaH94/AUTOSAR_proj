#include "STD_TYPES.h"
#include "Left_Door.h"
#include "Right_Door.h"
#include "Lighting.h"

#include "GPIO.h"

//#define GPIO_O_DEN              *((volatile u32*) 0x4000451C)
/**
 * main.c
 */
int main(void)
{
    u8 leftSate;
    u8 rightSate;


    SYSCTRL_GPIOBusControl(2, SYSCTRL_AHB );


    Left_DoorSystemInit();
    Right_DoorSystemInit();
    DoorLightingSystemInit();
//    GPIO_O_DEN = 0xFFFF;

    while (1)
    {
        Left_DoorSystem(&leftSate);
        Right_DoorSystem(&rightSate);


        if ((leftSate == LEFT_DOOR_OPEN) || (rightSate == RIGHT_DOOR_OPEN))
        {
            DoorLightingSystem(DOOR_LIGHT_ON);
        }
        else
        {
            DoorLightingSystem(DOOR_LIGHT_OFF);
        }
    }

	return 0;
}
