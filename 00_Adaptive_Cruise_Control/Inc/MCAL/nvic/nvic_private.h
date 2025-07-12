/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : nvic_private.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_


#define	 MNVIC_PERIPHERAL_BASE_ADDR		(0xE000E100)


typedef struct
{

	vuint32_t MNVIC_ISERx[8];
	vuint32_t MNVIC_RESERVED0[24];
	vuint32_t MNVIC_ICERx[8];
	vuint32_t MNVIC_RESERVED1[24];
	vuint32_t MNVIC_ISPRx[8];
	vuint32_t MNVIC_RESERVED2[24];
	vuint32_t MNVIC_ICPRx[8];
	vuint32_t MNVIC_RESERVED3[24];
	vuint32_t MNVIC_IABRx[8];
	vuint32_t MNVIC_RESERVED4[56];
	vuint8_t MNVIC_IPRx[240];
	vuint32_t MNVIC_RESERVED5[580];
	vuint32_t MNVIC_STIR;

}ST_MNVIC_RegistersMap_t;


#define MNVIC_PERIPHERAL ((volatile ST_MNVIC_RegistersMap_t *)MNVIC_PERIPHERAL_BASE_ADDR)

#define	SCB_AIRCR		 *((volatile uint32_t *)(0xE000ED0C))

#define	MNVIC_VECTKEY		(0x05FA0000) /* Key to write to AIRCR register */


#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
