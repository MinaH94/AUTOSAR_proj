/************************************************/
/* Author : Amira Zaher                         */
/* Version : V01                                */
/* Date :23 Feb 2020                            */
/* File Name: Led.h                 */
/* Layer : HAL                                */
/************************************************/

#ifndef LED_H_
#define LED_H_

#include "GPIO.h"

#define LED_DOOR  0

#define LED_STATE_ON   GPIO_PIN_VALUE_HIGH
#define LED_STATE_OFF  GPIO_PIN_VALUE_LOW
#define Led_Channel_Number  0

#define LED_PIN_0  GPIO_PIN_0
#define LED_PIN_1  GPIO_PIN_1
#define LED_PIN_2  GPIO_PIN_2
#define LED_PIN_3  GPIO_PIN_3
#define LED_PIN_4  GPIO_PIN_4
#define LED_PIN_5  GPIO_PIN_5
#define LED_PIN_6  GPIO_PIN_6
#define LED_PIN_7  GPIO_PIN_7

#define LED_PORT_A GPIO_PORT_A
#define LED_PORT_B GPIO_PORT_B
#define LED_PORT_C GPIO_PORT_C
#define LED_PORT_D GPIO_PORT_D
#define LED_PORT_E GPIO_PORT_E
#define LED_PORT_F GPIO_PORT_F


Error_S HLED_Init (void);
Error_S HLED_writeLedState (u8 Lamp_Channel_Number);

#endif /* LED_H_ */
