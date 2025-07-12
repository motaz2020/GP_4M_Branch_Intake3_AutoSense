/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : tmr_config.h                                  	     
// Date          : Oct 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_CONFIG_H_
#define MCAL_TMR_TMR_CONFIG_H_


/**
 * @brief Enumeration for Multi-Function Timer numbers.
 */
typedef enum
{
    MTMR2 = 0, /**< Multi-Function Timer 2. */
    MTMR3,     /**< Multi-Function Timer 3. */
    MTMR4,     /**< Multi-Function Timer 4. */
    MTMR5      /**< Multi-Function Timer 5. */
} EN_MTMR_number_t;

/**
 * @brief Enumeration for Multi-Function Timer channels.
 */
typedef enum
{
    MTMR_CH1 = 1, /**< Multi-Function Timer Channel 1. */
    MTMR_CH2,     /**< Multi-Function Timer Channel 2. */
    MTMR_CH3,     /**< Multi-Function Timer Channel 3. */
    MTMR_CH4      /**< Multi-Function Timer Channel 4. */
} EN_MTMR_channel_t;

/**
 * @brief Enumeration for selected modes of Multi-Function Timer.
 */
typedef enum
{
    MTMR_MODE_FROZEN = 0,        /**< Frozen mode. */
    MTMR_MODE_ACTIVE,            /**< Active mode. */
    MTMR_MODE_INACTIVE,          /**< Inactive mode. */
    MTMR_MODE_TOGGLE,            /**< Toggle mode. */
    MTMR_MODE_INACTIVE_FORCE,    /**< Inactive force mode. */
    MTMR_MODE_ACTIVE_FORCE,      /**< Active force mode. */
    MTMR_MODE_PWM_MODE1,         /**< PWM mode 1. */
    MTMR_MODE_PWM_MODE2          /**< PWM mode 2. */
} EN_MTMR_selectedMode_t;

/**
 * @brief Enumeration for Multi-Function Timer channel modes.
 */
typedef enum
{
    OUTPUT, /**< Output mode. */
    IC_T2,  /**< Input capture mode T2. */
    IC_T1,  /**< Input capture mode T1. */
    IC_TRC  /**< Input capture mode TRC. */
} CH_MODE_t;

/**
 * @brief Enumeration for Multi-Function Timer edge options.
 */
typedef enum
{
    RISIN,     /**< Rising edge. */
    FALLIN,    /**< Falling edge. */
    RESERVED,  /**< Reserved. */
    BOTH       /**< Both edges. */
} EDGE_t;
#endif /* MCAL_TMR_TMR_CONFIG_H_ */
