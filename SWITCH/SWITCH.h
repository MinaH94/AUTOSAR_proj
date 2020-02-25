
/********************************************************************************
**  FILENAME     : SWITCH.H         			                              **
**  VERSION      : 1.0                                                        **
**  DATE         : 24 Feb 2020                                                **                                                                         **
**  PLATFORM     : TivaC		                                                  **
**  AUTHOR       : Nada Mohamed                                               **
*******************************************************************************/


#ifndef SWITCH_H_
#define SWITCH_H_

#include "STD_TYPES.h"
#include "GPIO.h"





#define SWITCH_LEFT               0
#define SWITCH_RIGHT              1


/*******************************************************
 * Return Type :- Error_S  [E_OK: request accepted
 *                          E_NOT_OK: request not accepted ]
 *Input Argument :-
 *                SwitchNumber :- Switch number
 *                                       SWITCH_LEFT
 *                                       SWITCH_RIGHT
 **********************************************************/
Error_S SWITCH_Init(u8 SwitchNumber);

/**********************************************************************
 * Return Type :- Error_S  [E_OK: request accepted
                           E_NOT_OK: request not accepted ]
 *Input Argument :-
 *               SwitchNumber :- Switch number
 *                                       SWITCH_LEFT
 *                                       SWITCH_RIGHT
 *Output Argument :- GetPinVaule(pointer)
 **********************************************************************/
Error_S SWITCH_ReadState(u8 SwitchNumber, u8* GetPinValue);


#endif /* SWITCH_H_ */
