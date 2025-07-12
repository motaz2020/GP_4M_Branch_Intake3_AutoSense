/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : LKA_interface.h                                  	     
// Date          : Nov 7, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Interface for Lane Keep Assistant (LKA) in the application.
 */

#ifndef APPLICATION_LANE_KEEP_ASSISTANT_LKA_INTERFACE_H_
#define APPLICATION_LANE_KEEP_ASSISTANT_LKA_INTERFACE_H_

#include "../../../Inc/COMMON/std_types.h"
#include "../../../Inc/HAL/ir/IR_interface.h"
#include "../../../Inc/HAL/dcm/dcm_interface.h"
#include "LKA_config.h"

/**
 * @defgroup LKA_Interface Lane Keep Assistant (LKA) Interface
 * @{
 */

/**
 * @brief Get the lane position using IR sensors.
 * @details This function retrieves the lane position based on IR sensor readings.
 *
 * @param PS_uddtRightIr Pointer to the configuration structure for the right IR sensor.
 * @param PS_uddtLeftIr Pointer to the configuration structure for the left IR sensor.
 * @return Enumeration representing the system state based on lane position.
 */
EN_ALKA_systeamState_t ALKA_uddtGetLanePosition(ST_HIR_cfg_t *PS_uddtRightIr, ST_HIR_cfg_t *PS_uddtLeftIr);

/**
 * @brief Set the car in lanes based on IR sensor readings and DC motor configurations.
 * @details This function sets the car within lanes based on IR sensor readings and DC motor configurations.
 *
 * @param PS_uddtRightIr Pointer to the configuration structure for the right IR sensor.
 * @param PS_uddtLeftIr Pointer to the configuration structure for the left IR sensor.
 * @param PS_uddtRightDcm Pointer to the configuration structure for the right DC motor.
 * @param PS_uddtLeftDcm Pointer to the configuration structure for the left DC motor.
 * @return Enumeration representing the system state after setting the car in lanes.
 */
EN_ALKA_systeamState_t ALKA_uddtSetCarInLanes(ST_HIR_cfg_t *PS_uddtRightIr, ST_HIR_cfg_t *PS_uddtLeftIr,
                                              ST_DCM_cfg_t *PS_uddtRightDcm, ST_DCM_cfg_t *PS_uddtLeftDcm);

/**
 * @brief Move the car forward based on IR sensor readings and DC motor configurations.
 * @details This function moves the car forward based on IR sensor readings and DC motor configurations.
 *
 * @param PS_uddtRightIr Pointer to the configuration structure for the right IR sensor.
 * @param PS_uddtLeftIr Pointer to the configuration structure for the left IR sensor.
 * @param PS_uddtRightDcm Pointer to the configuration structure for the right DC motor.
 * @param PS_uddtLeftDcm Pointer to the configuration structure for the left DC motor.
 * @return Enumeration representing the system state after moving the car forward.
 */
EN_ALKA_systeamState_t ALKA_forward(ST_HIR_cfg_t *PS_uddtRightIr, ST_HIR_cfg_t *PS_uddtLeftIr,
                                    ST_DCM_cfg_t *PS_uddtRightDcm, ST_DCM_cfg_t *PS_uddtLeftDcm);

/**
 * @brief Move the car to the right based on IR sensor readings and DC motor configurations.
 * @details This function moves the car to the right based on IR sensor readings and DC motor configurations.
 *
 * @param PS_uddtRightIr Pointer to the configuration structure for the right IR sensor.
 * @param PS_uddtLeftIr Pointer to the configuration structure for the left IR sensor.
 * @param PS_uddtRightDcm Pointer to the configuration structure for the right DC motor.
 * @param PS_uddtLeftDcm Pointer to the configuration structure for the left DC motor.
 * @return Enumeration representing the system state after moving the car to the right.
 */
EN_ALKA_systeamState_t ALKA_right(ST_HIR_cfg_t *PS_uddtRightIr, ST_HIR_cfg_t *PS_uddtLeftIr,
                                  ST_DCM_cfg_t *PS_uddtRightDcm, ST_DCM_cfg_t *PS_uddtLeftDcm);

/**
 * @brief Move the car to the left based on IR sensor readings and DC motor configurations.
 * @details This function moves the car to the left based on IR sensor readings and DC motor configurations.
 *
 * @param PS_uddtRightIr Pointer to the configuration structure for the right IR sensor.
 * @param PS_uddtLeftIr Pointer to the configuration structure for the left IR sensor.
 * @param PS_uddtRightDcm Pointer to the configuration structure for the right DC motor.
 * @param PS_uddtLeftDcm Pointer to the configuration structure for the left DC motor.
 * @return Enumeration representing the system state after moving the car to the left.
 */
EN_ALKA_systeamState_t ALKA_left(ST_HIR_cfg_t *PS_uddtRightIr, ST_HIR_cfg_t *PS_uddtLeftIr,
                                 ST_DCM_cfg_t *PS_uddtRightDcm, ST_DCM_cfg_t *PS_uddtLeftDcm);

/** @} */ // End of LKA_Interface group

#endif /* APPLICATION_LANE_KEEP_ASSISTANT_LKA_INTERFACE_H_ */
