/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : systick_config.h                                  	     
// Date          : Sep 12, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_SYSTICK_SYSTICK_CONFIG_H_
#define MCAL_SYSTICK_SYSTICK_CONFIG_H_


#define MIN_VAL_OF_U32				0
#define MAX_VAL_OF_U32				0xFFFFFFFF

#define MSTK_IntervalSingle			0
#define MSTK_IntervalPeriodic		1


/**
 * @brief Enumeration for the system state of SysTick functions.
 */
typedef enum
{
    MSTK_OK = 0,                 /**< Operation successful. */
    MSTK_NOK,                    /**< Operation failed. */
    MSTK_INVALID_PARAMTER        /**< Invalid parameter detected. */
} EN_MSTK_systemState_t;

/**
 * @brief Enumeration for the clock source options in SysTick.
 */
typedef enum
{
    MSTK_CLK_AHB_8 = 0,			/**< SysTick clock source is AHB/8. */
    MSTK_CLK_PROCESSOR_AHB 		/**< SysTick clock source is the processor clock (AHB). */
} EN_MSTK_clkSourceOptions_t;

/**
 * @brief Enumeration for the interrupt states in SysTick.
 */
typedef enum
{
    MSTK_INTERRUPT_ENABLED = 0, /**< SysTick interrupt is enabled. */
    MSTK_INTERRUPT_DISABLED     /**< SysTick interrupt is disabled. */
} EN_MSTK_interruptStates_t;

#endif /* MCAL_SYSTICK_SYSTICK_CONFIG_H_ */
