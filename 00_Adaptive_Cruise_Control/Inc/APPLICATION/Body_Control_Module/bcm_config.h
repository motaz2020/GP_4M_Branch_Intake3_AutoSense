/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Body_Control_Module
// File          : bcm_config.h
// Date          : Oct 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Configuration file for Body Control Module (BCM) in the application.
 */

#ifndef APPLICATION_BODY_CONTROL_MODULE_BCM_CONFIG_H_
#define APPLICATION_BODY_CONTROL_MODULE_BCM_CONFIG_H_

/**
 * @defgroup BCM_Configuration Body Control Module (BCM) Configuration
 * @{
 */

/**
 * @brief Enumeration representing different states of the car in BCM.
 */
typedef enum
{
    ABCM_CAR_STANDBY = 0,       /**< Car in standby state. */
    ABCM_CAR_ON,                /**< Car turned on. */
    ABCM_CAR_NCC_ACTIVE,        /**< Car with NCC (Non-Collision Control) active. */
    ABCM_CAR_ACC_SET,           /**< Car with ACC (Adaptive Cruise Control) speed set. */
    ABCM_CAR_ACC_ACTIVE,        /**< Car with ACC (Adaptive Cruise Control) active. */
    ABCM_CAR_GET_FAULT,         /**< Car checking for faults. */
    ABCM_CAR_NCC_OFF,           /**< Car with NCC (Non-Collision Control) turned off. */
    ABCM_CAR_ACC_OFF,           /**< Car with ACC (Adaptive Cruise Control) turned off. */
    ABCM_CAR_IDLE,              /**< Car in idle state. */
    ABCM_UPDATE_FIRMWARE,       /**< Car updating firmware. */
    ABCM_CHANGE_SPEED_LIMIT     /**< Car changing speed limit. */
} EN_ABCM_carStates_t;

/**
 * @brief Enumeration representing different fault codes in BCM.
 */
typedef enum
{
    ABCM_FAULT_CAR_IS_ALREADY_ON = 1,
    ABCM_FAULT_NCC_IS_ALREADY_ACTIVE,
    ABCM_FAULT_ACC_IS_ALREADY_ACTIVE,
    ABCM_FAULT_CAR_IS_ALREADY_OFF,
    ABCM_FAULT_ACC_IS_ALREADY_OFF,
    ABCM_FAULT_NCC_IS_ALREADY_OFF,
    ABCM_FAULT_SPEED_RANGE_INVALID,
    ABCM_FAULT_ACC_NOR_NCC_IS_WORKING,
    ABCM_NO_FIRMWARE
} EN_ABCM_faultCodes_t;

/** @} */ // End of BCM_Configuration group

#endif /* APPLICATION_BODY_CONTROL_MODULE_BCM_CONFIG_H_ */
