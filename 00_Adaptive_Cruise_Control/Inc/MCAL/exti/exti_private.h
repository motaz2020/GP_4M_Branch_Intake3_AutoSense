/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : exti_private.h                                  	     
// Date          : Sep 11, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_PRIVATE_H_



#define	 MEXTI_PERIPHERAL_BASE_ADDR			(0x40013C00)
#define	 MSYSCFG_PERIPHERAL_BASE_ADDR		(0x40013800)


#define   EXTI_CONFG_MASK1                0xFFFFFFF0UL
#define   EXTI_CONFG_MASK2                0xFFFFFF0FUL
#define   EXTI_CONFG_MASK3                0xFFFFF0FFUL
#define   EXTI_CONFG_MASK4                0xFFFF0FFFUL

typedef struct
{

	vuint32_t MEXTI_IMR;
	vuint32_t MEXTI_EMR;
	vuint32_t MEXTI_RTSR;
	vuint32_t MEXTI_FTSR;
	vuint32_t MEXTI_SWIER;
	vuint32_t MEXTI_PR;

}ST_MEXTI_RegistersMap_t;


typedef struct
{
	vuint32_t MSYSCFG_MEMRMP;
	vuint32_t MSYSCFG_PMC;
	vuint32_t MSYSCFG_EXTICR1;
	vuint32_t MSYSCFG_EXTICR2;
	vuint32_t MSYSCFG_EXTICR3;
	vuint32_t MSYSCFG_EXTICR4;
	vuint32_t MSYSCFG_CMPCR;
}ST_MSYSCFG_RegistersMap_t;


#define MEXTI_PERIPHERAL 	((volatile ST_MEXTI_RegistersMap_t *)MEXTI_PERIPHERAL_BASE_ADDR)
#define MSYSCFG_PERIPHERAL  ((volatile ST_MSYSCFG_RegistersMap_t *)MSYSCFG_PERIPHERAL_BASE_ADDR)


#endif /* MCAL_EXTI_PRIVATE_H_ */
