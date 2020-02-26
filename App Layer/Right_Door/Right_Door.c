#include "STD_TYPES.h"
#include "Right_Door.h"
#include "SWITCH.h"

Error_S Right_DoorSystemInit (void)
{
    Error_S ErrorStatus = ERROR_OK;
    SWITCH_Init(SWITCH_RIGHT);
    return ErrorStatus;
}

Error_S Right_DoorSystem (u8* DoorState)
{
  Error_S ErrorStatus = ERROR_OK;
  u8 GetSwitchState;
  SWITCH_ReadState(RIGHT_DOOR,&GetSwitchState);
  *DoorState=GetSwitchState;
  
  return ErrorStatus;
}
