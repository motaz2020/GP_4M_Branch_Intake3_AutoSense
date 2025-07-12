/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : exti_config.h                                  	     
// Date          : Sep 11, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_



/**
 * @brief Enumeration for the system state of EXTI functions.
 */
typedef enum
{
    MEXTI_OK = 0,                 /**< Operation successful. */
    MEXTI_NOK,                    /**< Operation failed. */
    MEXTI_INVALID_PARAMTER        /**< Invalid parameter detected. */
} EN_MEXTI_systemState_t;


typedef enum
{
	MEXTI_RISING_EDGE = 0,
	MEXTI_FALLING_EDGE,
	MEXTI_ON_CHANGE
}EN_MEXTI_triggerOptions_t;


typedef enum
{
	MEXTI_LINE0 = 0,
	MEXTI_LINE1,
	MEXTI_LINE2,
	MEXTI_LINE3,
	MEXTI_LINE4,
	MEXTI_LINE5,
	MEXTI_LINE6,
	MEXTI_LINE7,
	MEXTI_LINE8,
	MEXTI_LINE9,
	MEXTI_LINE10,
	MEXTI_LINE11,
	MEXTI_LINE12,
	MEXTI_LINE13,
	MEXTI_LINE14,
	MEXTI_LINE15,
	MEXTI_LINE16,
	MEXTI_LINE17,
	MEXTI_LINE18,
	MEXTI_LINE19,
	MEXTI_LINE20,
	MEXTI_LINE21,
	MEXTI_LINE22
}EN_MEXTI_lines_t;


typedef enum
{
	MEXTI_PORTA = 0,
	MEXTI_PORTB,
	MEXTI_PORTC,
	MEXTI_PORTD,
	MEXTI_PORTE,
	MEXTI_PORTH
}EN_MEXTI_port_t;

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
