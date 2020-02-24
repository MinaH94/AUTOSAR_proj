
/********************************************************************************
**  FILENAME     : SWITCH.H         			                              **
**  VERSION      : 1.0                                                        **
**  DATE         : 24 Feb 2020                                                **                                                                         **
**  PLATFORM     : TivaC		                                                  **
**  AUTHOR       : Nada Mohamed                                               **
*******************************************************************************/


#ifndef SWITCH_H_
#define SWITCH_H_

#include "GPIO.h"

/*  SWITCH_PULL -> PULL UP =0   && PULL DOWN =1   */
#define SWITCH_PULLUP            1



#define SWITCH_LEFT               0
#define SWITCH_RIGHT              1



/*******************************************************
 * Initialize switch pins
 * Return Type :-    Error_S      : Error_OK  & Error_NOK
 * Input Argument :- SWITCH_LEFT  :- left Switch
 *                   SWITCH_RIGHT :- right switch
 *******************************************************/
Error_S SWITCH_Init(u8 SWITCH_NUM);
/*******************************************************************
 * Return Type :- u8
 *                SWITCH_PRESSED     -> if switch is pressed
 *                SWITCH_NOTPRESSED  -> if if switch not pressed
 *
 *Input Argument :-
 *                Copy_u8SwitchNumber :- Switch number
 *                                       switch1
 *                                       switch2
 *******************************************************************/
Error_S SWITCH_ReadState(u8 SwitchNumber, u8* GetPinValue);


#endif /* SWITCH_H_ */
