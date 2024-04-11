/*
 * 001led_toggle.c
 *
 *  Created on: Apr 9, 2024
 *      Author: ad
 */


#include "stm32f103xx.h"
#include "stm32f103xx_gpio_driver.h"


void delay(void)
{
	for(uint32_t i = 0 ; i < 500000/16 ; i ++);
}


int main(void)
{

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_2MHz;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOC,ENABLE);
	 GPIO_Init(&GpioLed);
	while(1)
	{
		GPIO_ToggleOutputPin(GPIOC,GPIO_PIN_NO_13);
		delay();
	}
	return 0;
}
