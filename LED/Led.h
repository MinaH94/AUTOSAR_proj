/************************************************/
/* Author : Amira Zaher                         */
/* Version : V01                                */
/* Date :23 Feb 2020                            */
/* File Name: Led.h                 */
/* Layer : HAL                                */
/************************************************/

#ifndef LED_H_
#define LED_H_

#define LED_DOOR  0

#define LED_STATE_ON  0
#define LED_STATE_OFF 1

#define LED_PIN_0 (u16)0x0001
#define LED_PIN_1 (u16)0x0002
#define LED_PIN_2 (u16)0x0004
#define LED_PIN_3 (u16)0x0008
#define LED_PIN_4 (u16)0x0010
#define LED_PIN_5 (u16)0x0020
#define LED_PIN_6 (u16)0x0040
#define LED_PIN_7 (u16)0x0080

#define LED_PORT_A (u16)0
#define LED_PORT_B (u16)1
#define LED_PORT_C (u16)2
#define LED_PORT_D (u16)3
#define LED_PORT_E (u16)4
#define LED_PORT_F (u16)5


Error_S HLED_Init (void);
Error_S HLED_writeLedState (u8 Lamp_Channel_Number);

#endif /* LED_H_ */
