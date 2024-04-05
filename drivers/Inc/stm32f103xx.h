/*
 * stm332f103xx.h
 *
 *  Created on: Apr 4, 202
 *      Author: NamLuu
 */

#ifndef INC_STM332F103XX_H_
#define INC_STM332F103XX_H_
#include<stddef.h>
#include<stdint.h>
/*
 * base addresses of Flash and SRAM memories
 */
#define FLASH_BASEADDR   	0x08000000U
#define SRAM1_BASEADDR 	 	0x20000000U
#define ROM					0x1FFFF000U
#define SRAM SRAM1_BASEADDR
/*
 * AHBx and APBx Bus Peripheral base addresses
 */
#define PERIPH_BASE			0x40000000U
#define APB1PERI_BASEADDR		PERIPH_BASE
#define APB2PERI_BASEADDR		0x40010000U
#define AHBPERI_BASEADDR		0x40018000U
/*
 * Base addresses of peripherals which are hanging on APB2 Bus
 */
#define GPIOA_BASEADDR		(APB2PERI_BASEADDR + 0x0800)
#define GPIOB_BASEADDR		(APB2PERI_BASEADDR + 0x0C00)
#define GPIOC_BASEADDR		(APB2PERI_BASEADDR + 0x1000)
#define GPIOD_BASEADDR		(APB2PERI_BASEADDR + 0x1400)
#define GPIOE_BASEADDR		(APB2PERI_BASEADDR + 0x1800)
#define GPIOF_BASEADDR		(APB2PERI_BASEADDR + 0x1C00)
#define GPIOG_BASEADDR		(APB2PERI_BASEADDR + 0x2000)

#define EXTI_BASEADDR		(APB2PERI_BASEADDR + 0x0400)

#define ADC1_BASEADDR		(APB2PERI_BASEADDR + 0x2400)

#define ADC2_BASEADDR		(APB2PERI_BASEADDR + 0x2800)

#define TIM1_BASEADDR		(APB2PERI_BASEADDR + 0x2C00)

#define SPI1_BASEADDR		(APB2PERI_BASEADDR + 0x3000)

#define TIM8_BASEADDR		(APB2PERI_BASEADDR + 0x3400)

#define USART1_BASEADDR		(APB2PERI_BASEADDR + 0x3800)
#define ADC3_BASEADDR		(APB2PERI_BASEADDR + 0x3C00)
#define TIM9_BASEADDR		(APB2PERI_BASEADDR + 0x4C00)
#define TIM10_BASEADDR		(APB2PERI_BASEADDR + 0x5000)
#define TIM11_BASEADDR		(APB2PERI_BASEADDR + 0x5400)
/*
 * Base addresses of peripheral which are hanging on APB1 Bus
 */
#define TIM2_BASEADDR 		(APB1PERI_BASEADDR + 0x0000)
#define TIM3_BASEADDR 		(APB1PERI_BASEADDR + 0x0400)
#define TIM4_BASEADDR 		(APB1PERI_BASEADDR + 0x0800)
#define TIM5_BASEADDR 		(APB1PERI_BASEADDR + 0x0C00)
#define TIM6_BASEADDR 		(APB1PERI_BASEADDR + 0x1000)
#define TIM7_BASEADDR 		(APB1PERI_BASEADDR + 0x1400)
#define TIM12_BASEADDR 		(APB1PERI_BASEADDR + 0x1800)
#define TIM13_BASEADDR 		(APB1PERI_BASEADDR + 0x1C00)
#define TIM14_BASEADDR 		(APB1PERI_BASEADDR + 0x2000)
#define RTC_BASEADDR 		(APB1PERI_BASEADDR + 0x2800)
#define WWDG_BASEADDR 		(APB1PERI_BASEADDR + 0x2C00)
#define IWDG_BASEADDR 		(APB1PERI_BASEADDR + 0x0000)
#define SPI2_BASEADDR 		(APB1PERI_BASEADDR + 0x3800)
#define SPI3_BASEADDR 		(APB1PERI_BASEADDR + 0x3C00)
#define USART2_BASEADDR 	(APB1PERI_BASEADDR + 0x4400)
#define USART3_BASEADDR 	(APB1PERI_BASEADDR + 0x4800)
#define UART4_BASEADDR 		(APB1PERI_BASEADDR + 0x4C00)
#define UART5_BASEADDR 		(APB1PERI_BASEADDR + 0x5000)
#define I2C1_BASEADDR 	(APB1PERI_BASEADDR + 0x5400)
#define I2C2_BASEADDR 	(APB1PERI_BASEADDR + 0x5800)
#define DAC_BASEADDR 	(APB1PERI_BASEADDR + 0x7400)
#define PWR_BASEADDR 	(APB1PERI_BASEADDR + 0x7000)
#define BKP_BASEADDR 	(APB1PERI_BASEADDR + 0x6C00)
#define CAN1_BASEADDR 	(APB1PERI_BASEADDR + 0x6400)
#define CAN2_BASEADDR 	(APB1PERI_BASEADDR + 0x6800)
#define USB_BASEADDR 	(APB1PERI_BASEADDR + 0x5C00)
/*
 * Base addresses of peripheral which are hanging on AHB Bus
 */
#define SDIO_BASEADDR	 	(AHBPERI_BASEADDR + 0x0000)
#define DMA1_BASEADDR	 	(AHBPERI_BASEADDR + 0x8000)
#define DMA2_BASEADDR	 	(AHBPERI_BASEADDR + 0x8400)
#define RCC_BASEADDR	 	(AHBPERI_BASEADDR + 0x9000)
//#define FLASH_BASEADDR	 	(AHBPERI_BASEADDR + 0xA000)
#define CRC_BASEADDR	 	(AHBPERI_BASEADDR + 0xB000)
#define ETHERNET_BASEADDR 	(AHBPERI_BASEADDR + 0xB000)
//#define USBOTG_BASEADDR 	(AHBPERI_BASEADDR + 0x0000)
//#define FSMC_BASEADDR 		(AHBPERI_BASEADDR + 0x0000)

/*
 * peripheral register definition structures
 * look up register map in Reference manual
 */
typedef struct
{
	volatile uint32_t CRL;	/*!< GPIO Port configuration register low 	Address offset: 0x00*/
	volatile uint32_t CRH;	/*!< GPIO Port configuration register high 	Address offset: 0x04*/
	volatile uint32_t IDR;	/*!< GPIO Port input data register 			Address offset: 0x08h*/
	volatile uint32_t ODR;	/*!< GPIO Port output data register 		Address offset: 0x0C*/
	volatile uint32_t BSRR;	/*!< GPIO Port bit set/reset register 		Address offset: 0x10*/
	volatile uint32_t BRR;	/*!< GPIO Port bit reset register 			Address offset: 0x14*/
	volatile uint32_t LCKR;	/*!< GPIO Port configuration lock register 	Address offset: 0x18*/


}GPIO_RegDef_t;


typedef struct
{
	volatile uint32_t CR;		/*!< Clock control register 				Address offset: 0x000*/
	volatile uint32_t CFGR;		/*!<  Clock configuration register 			Address offset: 0x004*/
	volatile uint32_t CIR;		/*!< Clock interrupt register 				Address offset: 0x008*/
	volatile uint32_t APB2RSTR;	/*!< APB2 peripheral reset register 		Address offset: 0x00C*/
	volatile uint32_t APB1RSTR;	/*!< APB1 peripheral reset register 		Address offset: 0x010*/
	volatile uint32_t AHBENR;	/*!< AHB Peripheral Clock enable register 	Address offset: 0x014*/
	volatile uint32_t APB2ENR;	/*!< APB2 peripheral clock enable register 	Address offset: 0x018*/
	volatile uint32_t APB1ENR;	/*!< APB1 peripheral clock enable register 	Address offset: 0x01C*/
	volatile uint32_t BDCR;		/*!< Backup domain control register 		Address offset: 0x020*/
	volatile uint32_t CSR;		/*!< Control/status register 				Address offset: 0x024*/
	volatile uint32_t AHBSTR;	/*!< AHB peripheral clock reset register 	Address offset: 0x028*/
	volatile uint32_t CFGR2;	/*!< Clock configuration register2 			Address offset: 0x02C*/


}RCC_RegDef_t;

/*
 * peripheral definitions (peripheral base addresses type casted to xxx_RegDef_t)
 */
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)

#define RCC ((RCC_RegDef_t*)RCC_BASEADDR)
/*
 * Clock enable Macros for GPIOx peripheral
 */
#define GPIOA_PCLK_EN()	( RCC->APB2ENR |= (1 << 2) )
#define GPIOB_PCLK_EN()	( RCC->APB2ENR |= (1 << 3) )
#define GPIOC_PCLK_EN()	( RCC->APB2ENR |= (1 << 4) )
#define GPIOD_PCLK_EN()	( RCC->APB2ENR |= (1 << 5) )
#define GPIOE_PCLK_EN()	( RCC->APB2ENR |= (1 << 6) )
#define GPIOF_PCLK_EN()	( RCC->APB2ENR |= (1 << 7) )
#define GPIOG_PCLK_EN()	( RCC->APB2ENR |= (1 << 8) )
/*
 * clock enable macros for I2Cx
 */
#define I2C1_PCLK_EN() ( RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() ( RCC->APB1ENR |= (1 << 22))
/*
 * clock enable macros for SPIx
 */
#define SPI1_PCLK_EN() ( RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() ( RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() ( RCC->APB1ENR |= (1 << 15))
/*
 * clock enable macros for USARTx
 */
#define USART1_PCLK_EN() ( RCC->APB2ENR |= (1 << 14))
#define USART2_PCLK_EN() ( RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() ( RCC->APB1ENR |= (1 << 18))
/*
 * clock enable macros for UARTx
 */
#define UART4_PCLK_EN() ( RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN() ( RCC->APB1ENR |= (1 << 20))


#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET   		DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET  RESET
#endif /* INC_STM332F103XX_H_ */
