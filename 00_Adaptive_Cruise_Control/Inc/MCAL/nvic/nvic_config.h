/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : nvic_config.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_NVIC_NVIC_CONFIG_H_
#define MCAL_NVIC_NVIC_CONFIG_H_

#define POS_OF_FIRST_INT			0
#define POS_OF_LAST_INT				84

#define getIntRegNumber(IntNumber)		(IntNumber / 32)
#define getIntBitNumber(IntNumber)		(IntNumber % 32)


/**
 * @brief Enumeration for the system state of NVIC functions.
 */
typedef enum
{
    MNVIC_OK = 0,                 /**< Operation successful. */
    MNVIC_NOK,                    /**< Operation failed. */
    MNVIC_INVALID_PARAMTER        /**< Invalid parameter detected. */
} EN_MNVIC_systemState_t;

/**
 * @brief Enumeration for the priority grouping options in the NVIC.
 */
typedef enum
{
    GP_16_SP_00 = 0, /**< 16 priority levels, 0 subpriority levels. */
    GP_08_SP_02,     /**< 8 priority levels, 2 subpriority levels. */
    GP_04_SP_04,     /**< 4 priority levels, 4 subpriority levels. */
    GP_02_SP_08,     /**< 2 priority levels, 8 subpriority levels. */
    GP_00_SP_16      /**< 0 priority levels, 16 subpriority levels. */
} EN_MNVIC_priorityGrouping_t;


#endif /* MCAL_NVIC_NVIC_CONFIG_H_ */
