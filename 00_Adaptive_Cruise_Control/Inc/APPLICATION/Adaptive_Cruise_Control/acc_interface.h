/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : acc_interface.h                                  	     
// Date          : Oct 23, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Interfacing file for Adaptive Cruise Control (ACC) in the application.
 */

#ifndef ACC_INTERFACE_H_
#define ACC_INTERFACE_H_

#include "../../HAL/dcm/dcm_interface.h"
#include "../../HAL/hc05/hc05_interface.h"

#include "acc_config.h"

/**
 * @defgroup AACC_Module Accelerated Adaptive Cruise Control (AACC) Module
 * @{
 */

/**
 * @brief Set speed limit for the AACC.
 *
 * @param rightdcm Pointer to the configuration structure for the right DC motor.
 * @param leftdcm Pointer to the configuration structure for the left DC motor.
 * @param copy_u8SpeedLimit Speed limit to be set.
 */
void AACC_vSetSpeedLimit(ST_DCM_cfg_t *rightdcm, ST_DCM_cfg_t *leftdcm, uint8_t copy_u8SpeedLimit);

/**
 * @brief Control the car using AACC based on the current distance.
 *
 * @param rightdcm Pointer to the configuration structure for the right DC motor.
 * @param leftdcm Pointer to the configuration structure for the left DC motor.
 * @param copy_u32CurrentDistance Current distance from the front obstacle.
 */
void AACC_vControlingCar(ST_DCM_cfg_t *rightdcm, ST_DCM_cfg_t *leftdcm, uint32_t copy_u32CurrentDistance);

/**
 * @brief Stop the acceleration in the AACC.
 *
 * @param rightdcm Pointer to the configuration structure for the right DC motor.
 * @param leftdcm Pointer to the configuration structure for the left DC motor.
 */
void AACC_vStopAcc(ST_DCM_cfg_t *rightdcm, ST_DCM_cfg_t *leftdcm);

/**
 * @brief Change the AACC acceleration speed limit.
 *
 * @param copy_u8SpeedAction Action to determine the speed limit change.
 * @return New speed limit after the change.
 */
uint8_t AACC_vChangeAccSpeedLimit(uint8_t copy_u8SpeedAction);

/** @} */ // End of ACC_INTERFACE_H_ group

#endif
