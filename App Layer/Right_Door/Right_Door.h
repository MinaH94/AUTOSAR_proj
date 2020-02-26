#ifndef RIGHT_DDOR_H_
#define RIGHT_DDOR_H_

#define RIGHT_DOOR 1

#define RIGHT_DOOR_CLOSED 0
#define RIGHT_DOOR_OPEN   1

Error_S Right_DoorSystemInit (void);
Error_S Right_DoorSystem (u8* DoorState);

#endif /* RIGHT_DDOR_H_ */
