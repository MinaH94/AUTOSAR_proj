#include "STD_TYPES.h"
#include "Lighting.h"
#include "GPIO.h"
#include "Led.h"

Error_S DoorLightingSystemInit (void)
{
    Error_S err = ERROR_OK;
    HLED_Init();
    return err;
}

Error_S DoorLightingSystem (u8 LedState)
{
    Error_S err = ERROR_OK;
    HLED_writeLedState(LedState);

    /*u8 leftLight;
    u8 rightLight;

    Left_DoorSystem(LedState);
    Right_DoorSystem(LedState);

    if (*LedState == GPIO_PIN_VALUE_HIGH)
    {

    }
    else
    {

    }*/

    return err;
}
