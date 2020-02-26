#ifndef LIGHTING_H_
#define LIGHTING_H_

#define DOOR_LIGHT_ON  0
#define DOOR_LIGHT_OFF 1

Error_S DoorLightingSystemInit (void);
Error_S DoorLightingSystem (u8 LedState);

#endif /* LIGHTING_H_ */
