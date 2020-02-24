/*
 * Led_Config.c
 *
 *  Created on: Feb 23, 2020
 *      Author: Amira Zaher
 */
#include "Led.h"
#include "Led_Config.h"

const LedMap_t Led_Configuration[LED_NUMBERS] = {
	{LED_PIN_1,LED_PORT_B, LED_STATE_ON},
	{LED_PIN_6,LED_PORT_A, LED_STATE_OFF}
};

LedMap_t* HLED_GetLedConfigurations (void)
{
	return Led_Configuration;
}
