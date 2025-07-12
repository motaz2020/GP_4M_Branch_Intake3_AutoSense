/**
 * @file dcm_interface.h
 * @brief Header file for the Direct Current Motor (DCM) module.
 */


#ifndef HAL_DCM_DCM_INTERFACE_H_
#define HAL_DCM_DCM_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "../../MCAL/tmr/tmr_interface.h"
#include "dcm_config.h"

/**
 * @brief Initialize the DC motor.
 *
 * This function initializes the DC motor based on the provided configuration.
 *
 * @param dcmCfg Pointer to the configuration structure of the DC motor.
 *
 * @return The system state after initializing the DC motor.
 *         - #DCM_OK: DC motor initialization successful.
 *         - #DCM_NOK: DC motor initialization failed.
 */
EN_DCM_systemState_t HDCM_init(ST_DCM_cfg_t *dcmCfg);

/**
 * @brief Turn off the DC motor.
 *
 * This function turns off the DC motor.
 *
 * @param dcmCfg Pointer to the configuration structure of the DC motor.
 *
 * @return The system state after turning off the DC motor.
 *         - #DCM_OK: DC motor turned off successfully.
 *         - #DCM_NOK: Failed to turn off the DC motor.
 */
EN_DCM_systemState_t HDCM_turnOff(ST_DCM_cfg_t *dcmCfg);

/**
 * @brief Turn on the DC motor.
 *
 * This function turns on the DC motor.
 *
 * @param dcmCfg Pointer to the configuration structure of the DC motor.
 *
 * @return The system state after turning on the DC motor.
 *         - #DCM_OK: DC motor turned on successfully.
 *         - #DCM_NOK: Failed to turn on the DC motor.
 */
EN_DCM_systemState_t HDCM_turnOn(ST_DCM_cfg_t *dcmCfg);

/**
 * @brief Change the direction of the DC motor.
 *
 * This function changes the direction of the DC motor.
 *
 * @param dcmCfg Pointer to the configuration structure of the DC motor.
 * @param dcmDirection The new direction for the DC motor.
 *
 * @return The system state after changing the direction of the DC motor.
 *         - #DCM_OK: DC motor direction changed successfully.
 *         - #DCM_NOK: Failed to change the DC motor direction.
 */
EN_DCM_systemState_t HDCM_changeDirection(ST_DCM_cfg_t *dcmCfg, EN_DCM_direction_t dcmDirection);

/**
 * @brief Control the speed of the DC motor.
 *
 * This function controls the speed of the DC motor.
 *
 * @param copy_u8Speed The desired speed value for the DC motor.
 *
 * @return The system state after controlling the speed of the DC motor.
 *         - #DCM_OK: DC motor speed controlled successfully.
 *         - #DCM_NOK: Failed to control the DC motor speed.
 */
EN_DCM_systemState_t HDCM_controlSpeed(uint8_t copy_u8Speed);
#endif /* HAL_DCM_DCM_INTERFACE_H_ */
