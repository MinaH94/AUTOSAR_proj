/*
 * Led_Config.c
 *
 *  Created on: Feb 23, 2020
 *      Author: Amira Zaher
 */
#include "STD_TYPES.h"
#include "Led.h"
#include "Led_Config.h"


const LedMap_t Led_Configuration[LED_NUMBERS] = {
	{LED_PIN_4, LED_PORT_B}
};

const LedMap_t* HLED_GetLedConfigurations (void)
{
	return Led_Configuration;
}
