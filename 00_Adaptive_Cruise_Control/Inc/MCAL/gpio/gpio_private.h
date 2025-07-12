/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : gpio_private.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_


#define	 MGPIOA_PERIPHERAL_BASE_ADDR		(0x40020000)
#define  MGPIOB_PERIPHERAL_BASE_ADDR		(0x40020400)
#define  MGPIOC_PERIPHERAL_BASE_ADDR		(0x40020800)
#define  MGPIOD_PERIPHERAL_BASE_ADDR		(0x40020C00)
#define  MGPIOE_PERIPHERAL_BASE_ADDR		(0x40021000)
#define  MGPIOH_PERIPHERAL_BASE_ADDR		(0x40021C00)


typedef struct
{

	vuint32_t	MGPIOx_MODER;
	vuint32_t	MGPIOx_OTYPER;
	vuint32_t	MGPIOx_OSPEEDR;
	vuint32_t	MGPIOx_PUPDR;
	vuint32_t	MGPIOx_IDR;
	vuint32_t	MGPIOx_ODR;
	vuint32_t	MGPIOx_BSRR;
	vuint32_t	MGPIOx_LCKR;
	vuint32_t	MGPIOx_AFRL;
	vuint32_t	MGPIOx_AFRH;


}ST_MGPIOx_RegistersMap_t;




#define MGPIOA_PERIPHERAL (( ST_MGPIOx_RegistersMap_t *)MGPIOA_PERIPHERAL_BASE_ADDR)
#define MGPIOB_PERIPHERAL (( ST_MGPIOx_RegistersMap_t *)MGPIOB_PERIPHERAL_BASE_ADDR)




#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
