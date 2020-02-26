#ifndef LIGHTING_H_
#define LIGHTING_H_


/*
 * Led_State : LED_STATE_ON  1
 *             LED_STATE_OFF 0
 */

#define DOOR_LIGHT_ON  0xFF
#define DOOR_LIGHT_OFF 0

Error_S DoorLightingSystemInit (void);

/*
 * LedState
         DOOR_LIGHT_ON  1
       DOOR_LIGHT_OFF 0
 */
Error_S DoorLightingSystem (u8 LedState);

#endif /* LIGHTING_H_ */
