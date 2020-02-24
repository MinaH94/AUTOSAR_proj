/************************************************/
/* Author : Amira Zaher                         */
/* Version : V01                                */
/* Date :23 Feb 2020                            */
/* File Name: Led.h                 */
/* Layer : HAL                                */
/************************************************/

#define LED_DOOR  0

#define LED_STATE_ON 0
#define LED_STATE_OFF 1

#define LED_NUMBERS 2

#define LED_PIN_0 (uint16_t)0x0001
#define LED_PIN_1 (uint16_t)0x0002
#define LED_PIN_2 (uint16_t)0x0004
#define LED_PIN_3 (uint16_t)0x0008
#define LED_PIN_4 (uint16_t)0x0010
#define LED_PIN_5 (uint16_t)0x0020
#define LED_PIN_6 (uint16_t)0x0040
#define LED_PIN_7 (uint16_t)0x0080

#define LED_PORT_A (uint16_t)0
#define LED_PORT_B (uint16_t)1
#define LED_PORT_C (uint16_t)2
#define LED_PORT_D (uint16_t)3
#define LED_PORT_E (uint16_t)4
#define LED_PORT_F (uint16_t)5


Error_s HLED_Init (void);
Error_s HLED_writeLedState (uint8_t Lamp_Channel_Number);

