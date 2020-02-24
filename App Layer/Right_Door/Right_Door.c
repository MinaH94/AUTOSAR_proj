#include "Right_Door.h"
#include "SWITCH.h"

Error_s Right_DoorSystem (u8* DoorState)
{
  Error_s ErrorStatus = Error_Ok;
  
  u8 GetSwitchState;
  SWITCH_ReadState(RIGHT_DOOR,&GetSwitchState);
  *DoorState=GetSwitchState;
  
  return ErrorStatus;
}