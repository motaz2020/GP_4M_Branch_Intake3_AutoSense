/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : aeb_config.h                                  	     
// Date          : Oct 26, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Configuration file for Automatic Emergency Brake (AEB) application.
 */

#ifndef APPLICATION_AUTOMATIC_EMERGENCY_BRAKE_AEB_CONFIG_H_
#define APPLICATION_AUTOMATIC_EMERGENCY_BRAKE_AEB_CONFIG_H_

/**
 * @defgroup AEB_Configuration Automatic Emergency Brake (AEB) Configuration
 * @{
 */

/**
 * @brief Speed value to indicate stopping in the AEB system.
 * @details Define the speed at which the AEB system considers stopping.
 */
#define STOP_SPEED 1

/**
 * @brief Distance threshold for a dangerous zone in the AEB system.
 * @details Define the distance at which the AEB system considers a zone as dangerous.
 */
#define DANGEROUS_ZONE 10

/**
 * @brief Enumeration representing different zones for AEB action.
 */
typedef enum
{
    AAEB_SAFE_ZONE = 0,         /**< Safe zone where no AEB action is required. */
    AAEB_DANGEROUS_ZONE         /**< Dangerous zone where AEB action is needed. */
} EN_AAEB_zones_t;

/** @} */ // End of AEB_Configuration group

#endif /* APPLICATION_AUTOMATIC_EMERGENCY_BRAKE_AEB_CONFIG_H_ */
