/*
 * Led.c
 *
 *  Created on: Feb 23, 2020
 *      Author: Amira Zaher
 */


#include <stdint.h>
#include "Led.h"
#include "Led_Config.h"
#include "GPIO.h"

typedef struct
{
	uint8_t GPIO_Pin_Number;
	uint8_t GPIO_Port;
	uint8_t LED_State;
}LedMap_t;


Error_s HLED_Init (void)
{
	Error_s Error_Status = ERROR_OK;

	uint8_t Leds_Counter = 0;
	LedMap_t* Led_Config = HLED_GetLedConfigurations();

	for ( Leds_Counter =0 ; Leds_Counter < LED_NUMBERS ; Leds_Counter++)
	{
		//GPIO_Init (Led_Config[Leds_Counter]);
		GPIO_Init (Led_Config[Leds_Counter].GPIO_Port, Led_Config[Leds_Counter].GPIO_Pin_Number, GPIO_PIN_DIR_OUTPUT);
	}
	return Error_Status;
}

Error_s HLED_writeLedState (uint8_t Led_Channel_Number)
{
	Error_s Error_Status = ERROR_OK;

	LedMap_t* Led_Config = HLED_GetLedConfigurations();
	GPIO_WritePin (Led_Config[Led_Channel_Number].GPIO_Port, Led_Config[Led_Channel_Number].GPIO_Pin_Number, GPIO_PIN_DIR_OUTPUT);

	return Error_Status;
}
