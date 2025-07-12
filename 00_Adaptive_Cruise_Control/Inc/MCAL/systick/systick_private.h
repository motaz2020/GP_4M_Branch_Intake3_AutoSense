/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : systick_private.h                                  	     
// Date          : Sep 12, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

#define	 MSTK_PERIPHERAL_BASE_ADDR			(0xE000E010)


typedef struct
{

	vuint32_t MSTK_STK_CTRL;
	vuint32_t MSTK_STK_LOAD;
	vuint32_t MSTK_STK_VAL;
	vuint32_t MSTK_STK_CALIB;

}ST_MSTK_RegistersMap_t;

#define MSTK_ENABLE_BIT			0
#define MSTK_TICKINT_BIT		1
#define MSTK_CLKSOURCE_BIT		2
#define MSTK_COUNTFLAG_BIT		16

#define MSTK_PERIPHERAL 	((volatile ST_MSTK_RegistersMap_t *)MSTK_PERIPHERAL_BASE_ADDR)


#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
