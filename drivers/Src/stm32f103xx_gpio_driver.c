/*
 * stm32f103xx_gpio_driver.c
 *
 *  Created on: Apr 5, 2024
 *      Author: ad
 */


#include "stm32f103xx_gpio_driver.h"

/*
 * Initialize and de-initialize
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0;

	//1. configure the mode of gpio pin
	uint8_t temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
	uint8_t temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
	if(temp1 < 1)
	{
		//the non interrupt mode
		temp =(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (4 * temp2));//left shift to the location with the value "2*pin number"
		pGPIOHandle->pGPIOx->CRL |= temp;
		temp = 0;
	}else
	{
		temp =(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (4 * temp2));
		pGPIOHandle->pGPIOx->CRH |= temp;
	}
	//2. configure the speed
		temp = 0;
		if(temp1 < 1)
			{

				temp =(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ((4 * temp2)+2));//left shift to the location with the value "2*pin number"
				pGPIOHandle->pGPIOx->CRL |= temp;
				temp = 0;
			}else
			{
				temp =(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ((4 * temp2)+2));
				pGPIOHandle->pGPIOx->CRH |= temp;
			}

	//3. configure the pupd settings
	//4. configure the opttype
	//5. configure the alt functionality
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();
			}else if(pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();
			}else if(pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();
			}else if(pGPIOx == GPIOD)
			{
				GPIOD_REG_RESET();
			}else if(pGPIOx == GPIOE)
			{
				GPIOE_REG_RESET();
			}
}
/*
 * Peripheral clock setup
 *
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]	      - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi )
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}


	} else
	{
		//todo
	}
}
/*
 * data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint8_t value;
	value = (uint8_t)pGPIOx->IDR;
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value )
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= ( 1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~( 1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= ( 1 << PinNumber);
}
/*
 * IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);
