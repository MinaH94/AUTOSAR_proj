#ifndef GPIO_H_
#define GPIO_H_

/* Pin direction: input or output */
#define GPIO_PIN_DIR_OUTPUT 1
#define GPIO_PIN_DIR_INPUT  0
/* ****************************** */

/* Port select: [A - F] */
#define GPIO_PORT_A 0x40058000
#define GPIO_PORT_B 0x40059000
#define GPIO_PORT_C 0x4005A000
#define GPIO_PORT_D 0x4005B000
#define GPIO_PORT_E 0x4005C000
#define GPIO_PORT_F 0x4005D000
/* ****************************** */

/* Pin number: [0 - 7] */
#define GPIO_PIN_0 0x1
#define GPIO_PIN_1 0x2
#define GPIO_PIN_2 0x4
#define GPIO_PIN_3 0x8
#define GPIO_PIN_4 0x10
#define GPIO_PIN_5 0x20
#define GPIO_PIN_6 0x40
#define GPIO_PIN_7 0x80
/* ****************************** */

/* Pin value: HIGH or LOW */
#define GPIO_PIN_VALUE_HIGH 0xFF
#define GPIO_PIN_VALUE_LOW  0x0
/* ****************************** */

/* Port bus select */
#define SYSCTRL_APB 0
#define SYSCTRL_AHB 1
/* ****************************** */

Error_S GPIO_Init(u32 port, u8 pin, u8 direction);
Error_S GPIO_ReadPin(u32 port, u8 pin, u8* out);
Error_S GPIO_WritePin(u32 port, u8 pin, u8 value);
Error_S SYSCTRL_GPIOBusControl(u8 In_u8In_u32Port, u8 In_u8Bus);

#endif /* GPIO_H_ */
