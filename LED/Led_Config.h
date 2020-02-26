/*
 * Led_Config.h
 *
 *  Created on: Feb 23, 2020
 *      Author: Amira Zaher
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_


typedef struct
{
    u8 GPIO_Pin_Number;
    u32 GPIO_Port;
}LedMap_t;

#define LED_NUMBERS 1

const LedMap_t* HLED_GetLedConfigurations (void);

#endif /* LED_CONFIG_H_ */
