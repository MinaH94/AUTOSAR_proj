
/********************************************************************************
**  FILENAME     : SWITCH_Cfg.h         			                           **
**  VERSION      : 1.0                                                         **
**  DATE         : 24 Feb 2020                                                 **                                                                         **
**  PLATFORM     : TivaC		                                                   **
**  AUTHOR       : Nada Mohamed                                                **
*********************************************************************************/

#ifndef SWITCH_CFG_H
#define SWITCH_CFG_H


#include "GPIO.h"

/* SWITCH PORTS may be one of
        GPIO_PORT_A
        GPIO_PORT_B
        GPIO_PORT_C
        GPIO_PORT_D
        GPIO_PORT_E
        GPIO_PORT_F
  SWITCH PINS may be one of
    Pin number: [0 - 7]
        GPIO_PIN_0
        GPIO_PIN_1
        GPIO_PIN_2
        GPIO_PIN_3
        GPIO_PIN_4
        GPIO_PIN_5
        GPIO_PIN_6
        GPIO_PIN_7

 */
#define SWITCH_LEFT_PIN        GPIO_PIN_5
#define SWITCH_LEFT_PORT       GPIO_PORT_B

#define SWITCH_RIGHT_PIN       GPIO_PIN_0
#define SWITCH2_RIGHT_PORT     GPIO_PORT_B





#endif
