#include "STD_TYPES.h"
#include "Left_Door.h"
#include "SWITCH.h"


Error_S Left_DoorSystem (u8* DoorState)
{
  Error_S ErrorStatus = ERROR_OK;
  SWITCH_Init(SWITCH_LEFT);
  u8 GetSwitchState;
  SWITCH_ReadState(LEFT_DOOR,&GetSwitchState);
  *DoorState=GetSwitchState;
  
  return ErrorStatus;
}
