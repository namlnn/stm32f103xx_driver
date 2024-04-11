/*
 * stm32f103xx_gpio_driver.h
 *
 *  Created on: Apr 5, 2024
 *      Author: ad
 */

#ifndef INC_STM32F103XX_GPIO_DRIVER_H_
#define INC_STM32F103XX_GPIO_DRIVER_H_

#include "stm32f103xx.h"


typedef struct
{
	uint8_t GPIO_PinNumber;	/*!<possible values from @GPIO_PIN_NUMBERS>*/
	uint8_t GPIO_PinMode;   /*!<possible values from @GPIO_PIN_MODES>*/
	uint8_t GPIO_PinSpeed;	/*!<possible values from @GPIO_PIN_SPEED>*/
	uint8_t GPIO_PinPuPdControl; /*!<possible values from @GPIO_PIN_INPUT>*/
	uint8_t GPIO_PinOPType; /*!<possible values from @GPIO_PIN_OUTPUT>*/
	uint8_t GPIO_PinALTFunMode;
}GPIO_PinConfig_t;


/*
 * this is a Handle structure for a GPIO pin
 */
typedef struct
{
	// pointer to hold the base addresses of GPIO peripheral
	GPIO_RegDef_t 	*pGPIOx;	/* hold the base address of GPIO port to which the pin belongs*/
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;
/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15

/*
 * @GPIO_PIN_MODES
 * GPIO PINS POSSIBLES MODES
 */
#define GPIO_MODE_IN 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT 	4
#define GPIO_MODE_IT_RT 	5
#define GPIO_MODE_IT_RFT 	6
/*
 * @GPIO_PIN_INPUT
 * GPIO possibles input types
 */
#define GPIO_IP_TYPE_ANALOG 0
#define GPIO_IP_TYPE_FLOAT	1
#define GPIO_IP_TYPE_PUPD	2
/*
 * @GPIO_PIN_OUTPUT
 * GPIO PIN POSSIBLE OUTPUT TYPES
 */
#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1
/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speeds
 */
#define GPIO_SPEED_2MHz			1
#define GPIO_SPEED_10MHz		2
#define GPIO_SPEED_50MHz		3



/*
 * GPIO pin pull up AND pull down configuration macros
 */
#define GPIO_NO_PUPD   		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2


/*******************************************************
 * APIs support for this driver
 */
/*
 * Initialize and de-initialize
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
/*
 * Peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
/*
 * data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value );
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_STM32F103XX_GPIO_DRIVER_H_ */
