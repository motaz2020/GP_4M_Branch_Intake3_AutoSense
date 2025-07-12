/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : aeb_interface.h                                  	     
// Date          : Oct 26, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Interface for Automatic Emergency Brake (AEB) application.
 */

#ifndef APPLICATION_AUTOMATIC_EMERGENCY_BRAKE_AEB_INTERFACE_H_
#define APPLICATION_AUTOMATIC_EMERGENCY_BRAKE_AEB_INTERFACE_H_

#include "../../HAL/dcm/dcm_interface.h"
#include "../../HAL/hc05/hc05_interface.h"
#include "aeb_config.h"

/**
 * @defgroup AEB_Interface Automatic Emergency Brake (AEB) Interface
 * @{
 */

/**
 * @brief Check if the AEB system is ready.
 * @details This function checks the readiness of the AEB system.
 *          It may perform any necessary initialization checks.
 */
void AAEB_vIsReady(void);

/**
 * @brief Check for obstacles and determine the AEB action.
 * @details This function checks for obstacles and determines the appropriate
 *          action to be taken by the AEB system.
 *
 * @param PS_uddtRightDcm Pointer to the configuration structure for the right DC motor.
 * @param PS_uddtLeftDcm Pointer to the configuration structure for the left DC motor.
 * @param copy_u32CurrentDistance Current distance from the front obstacle.
 * @return Enumeration representing the AEB action zones.
 */
EN_AAEB_zones_t AAEB_uddtCheckForObstacles(ST_DCM_cfg_t *PS_uddtRightDcm,
                                          ST_DCM_cfg_t *PS_uddtLeftDcm,
                                          uint32_t copy_u32CurrentDistance);

/** @} */ // End of AEB_Interface group

#endif /* APPLICATION_AUTOMATIC_EMERGENCY_BRAKE_AEB_INTERFACE_H_ */
