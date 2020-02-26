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

    return err;
}
