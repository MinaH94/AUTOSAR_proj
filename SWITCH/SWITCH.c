
/********************************************************************************
 **  FILENAME     : SWITCH.c        			                                  **
 **  VERSION      : 1.0                                                        **
 **  DATE         : 24 Feb 2020                                                 **                                                                         **
 **  PLATFORM     : TivaC	                                                  **
 **  AUTHOR       : Nada Mohamed                                               **
 *******************************************************************************/

#include "SWITCH.h"
#include "SWITCH_Cfg.h"


u16 SWITCH_PIN[] ={SWITCH_LEFT_PIN,SWITCH_RIGHT_PIN};
u32 SWITCH_PORT[]={SWITCH_LEFT_PORT,SWITCH2_RIGHT_PORT };

/*******************************************************
 * Return Type :- Error_S  [E_OK: request accepted
 *                          E_NOT_OK: request not accepted ]
 *Input Argument :-
 *                Copy_u8SwitchNumber :- Switch number
 *                                       SWITCH_LEFT
 *                                       SWITCH_RIGHT
 *******************************************************/
Error_S SWITCH_Init(u8 SwitchNumber)
{
    Error_S State=Error_OK;

    GPIO_Init(SWITCH_PORT[SwitchNumber], SWITCH_PIN[SwitchNumber], GPIO_PIN_DIR_INPUT);
    GPIO_WritePin(SWITCH_PORT[SwitchNumber], SWITCH_PIN[SwitchNumber],GPIO_PIN_VALUE_HIGH);

    return State;
}


/**********************************************************************
 * Return Type :- Error_S  [E_OK: request accepted
                           E_NOT_OK: request not accepted ]
 *Input Argument :-
 *                Copy_u8SwitchNumber :- Switch number
 *                                       SWITCH_LEFT
 *                                       SWITCH_RIGHT
 *Output Argument :- GetPinVaule(pointer)
 **********************************************************************/
Error_S SWITCH_ReadState(u8 SwitchNumber, u8* GetPinValue)
{
    Error_S  State=Error_OK;
    u8 PinValue;

    GPIO_ReadPin(SWITCH_PORT[SwitchNumber],SWITCH_PIN[SwitchNumber],&PinValue);
    *GetPinValue=PinValue;

    return State;
}
