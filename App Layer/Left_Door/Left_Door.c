#include "Left_Door.h"
#include "SWITCH.h"

Error_s Left_DoorSystem (u8* DoorState)
{
  Error_s ErrorStatus = Error_Ok;
  
  u8 GetSwitchState;
  SWITCH_ReadState(LEFT_DOOR,&GetSwitchState);
  *DoorState=GetSwitchState;
  
  return ErrorStatus;
}