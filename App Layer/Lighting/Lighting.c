#include "Lighting.h"

Error_s DoorLightingSystem (u8 *LedState)
{
  Left_DoorSystem(&LedState);
  Right_DoorSystem(&LedState);
  if (LedState==HIGH)
  {
    HLED_writeLedState(LED_DOOR);
  }
  else
  {}
}