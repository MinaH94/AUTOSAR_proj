/*
 * Led.c
 *
 *  Created on: Feb 23, 2020
 *      Author: Amira Zaher
 */


#include "STD_TYPES.h"
#include "GPIO.h"
#include "Led.h"
#include "Led_Config.h"


Error_S HLED_Init (void)
{
	Error_S Error_Status = ERROR_OK;

	u8 Leds_Counter = 0;
	const LedMap_t* Led_Config = HLED_GetLedConfigurations();

    GPIO_Init (Led_Config[Leds_Counter].GPIO_Port, Led_Config[Leds_Counter].GPIO_Pin_Number, GPIO_PIN_DIR_OUTPUT);

	return Error_Status;
}

/*
 * Led_State : LED_STATE_ON
 *             LED_STATE_OFF
 */
Error_S HLED_writeLedState (u8 Led_State)
{
	Error_S Error_Status = ERROR_OK;

	const LedMap_t* Led_Config = HLED_GetLedConfigurations();
	GPIO_WritePin (Led_Config[Led_Channel_Number].GPIO_Port, Led_Config[Led_Channel_Number].GPIO_Pin_Number, Led_State);

	return Error_Status;
}
