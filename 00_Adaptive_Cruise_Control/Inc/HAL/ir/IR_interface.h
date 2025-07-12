/**
 * @file IR_interface.h
 * @brief Header file for the Infrared Sensor (HIR) module.
 */

#ifndef HAL_IR_IR_INTERFACE_H_
#define HAL_IR_IR_INTERFACE_H_

#include "../../../Inc/COMMON/std_types.h"
#include "../../../Inc/MCAL/gpio/gpio_interface.h"
#include "IR_config.h"

/**
 * @brief Initialize the Human Interface Receiver (HIR) module.
 *
 * This function initializes the HIR module based on the provided configuration.
 *
 * @param PS_uddtIrInstance Pointer to the configuration structure for the HIR module.
 *
 * @return The system state after initializing the HIR module.
 *         - #HIR_OK: HIR module initialization successful.
 *         - #HIR_NOK: HIR module initialization failed.
 *         - #HIR_PTR_NULL: Null pointer encountered during the operation.
 */
EN_HIR_systemState_t HIR_uddtInit(ST_HIR_cfg_t *PS_uddtIrInstance);

/**
 * @brief Read data from the Human Interface Receiver (HIR) module.
 *
 * This function reads data from the HIR module and provides the surface state.
 *
 * @param PS_uddtIrInstance Pointer to the configuration structure for the HIR module.
 * @param copy_uddtRetOfIrRead Pointer to store the retrieved surface state.
 *
 * @return The system state after reading data from the HIR module.
 *         - #HIR_OK: Data reading successful.
 *         - #HIR_NOK: Data reading failed.
 *         - #HIR_PTR_NULL: Null pointer encountered during the operation.
 */
EN_HIR_systemState_t HIR_uddtReadData(ST_HIR_cfg_t *PS_uddtIrInstance, EN_HIR_surfaceState_t *copy_uddtRetOfIrRead);
#endif /* HAL_IR_IR_INTERFACE_H_ */
