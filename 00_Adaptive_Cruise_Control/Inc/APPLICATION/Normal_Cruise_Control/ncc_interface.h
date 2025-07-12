/**
 * @file
 * @brief Interface for Normal Cruise Control (NCC) in the Adaptive Cruise Control project.
 *
 * @author Sherif Ashraf Khadr
 * @date Oct 18, 2023
 * @see https://github.com/sherifkhadr
 */

#ifndef APPLICATION_NORMAL_CRUISE_CONTROL_NCC_INTERFACE_H_
#define APPLICATION_NORMAL_CRUISE_CONTROL_NCC_INTERFACE_H_

#include "../../HAL/dcm/dcm_interface.h"
#include "../../HAL/hc05/hc05_interface.h"
#include "ncc_config.h"

/**
 * @defgroup NCC_Interface Normal Cruise Control (NCC) Interface
 * @{
 */

/**
 * @brief Speed value to indicate stopping in the NCC system.
 * @details Define the speed at which the NCC system considers stopping.
 */
#define STOP_SPEED 1

/**
 * @brief Start the Normal Cruise Control (NCC) system.
 *
 * @param leftdcm Pointer to the configuration structure for the left DC motor.
 * @param rightdcm Pointer to the configuration structure for the right DC motor.
 * @param copy_u8Speed Speed to be set for the NCC system.
 */
void ANCC_vStartNcc(ST_DCM_cfg_t *leftdcm, ST_DCM_cfg_t *rightdcm, uint8_t copy_u8Speed);

/**
 * @brief Stop the Normal Cruise Control (NCC) system.
 *
 * @param leftdcm Pointer to the configuration structure for the left DC motor.
 * @param rightdcm Pointer to the configuration structure for the right DC motor.
 */
void ANCC_vStopNcc(ST_DCM_cfg_t *leftdcm, ST_DCM_cfg_t *rightdcm);

/**
 * @brief Change the Normal Cruise Control (NCC) speed limit.
 *
 * @param copy_u8SpeedAction Action to determine the speed limit change.
 * @return New speed limit after the change.
 */
uint8_t ANCC_vChangeNccSpeedLimit(uint8_t copy_u8SpeedAction);

/** @} */ // End of NCC_Interface group

#endif /* APPLICATION_NORMAL_CRUISE_CONTROL_NCC_INTERFACE_H_ */
