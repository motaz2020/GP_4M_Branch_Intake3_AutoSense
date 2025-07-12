/**
 * @file exti_interface.h
 *
 * @brief Header file for the EXTI (External Interrupt) module interface.
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "exti_private.h"
#include "exti_config.h"

/**
 * @brief Enable the EXTI line for a specific GPIO pin.
 *
 * This function enables the EXTI line for a specified GPIO pin.
 *
 * @param copy_uddtLineNum The EXTI line number to enable.
 *        Possible values are:
 *        - #EN_MEXTI_LINE0
 *        - #EN_MEXTI_LINE1
 *        - ...
 *        - #EN_MEXTI_LINE15
 *
 * @return The system state after enabling the EXTI line.
 *         - #EN_MEXTI_OK: EXTI line enabling successful.
 *         - #EN_MEXTI_NOK: EXTI line enabling failed.
 *         - #EN_MEXTI_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MEXTI_systemState_t MEXTI_enableEXTI(EN_MEXTI_lines_t copy_uddtLineNum);

/**
 * @brief Disable the EXTI line for a specific GPIO pin.
 *
 * This function disables the EXTI line for a specified GPIO pin.
 *
 * @param copy_uddtLineNum The EXTI line number to disable.
 *        Possible values are:
 *        - #EN_MEXTI_LINE0
 *        - #EN_MEXTI_LINE1
 *        - ...
 *        - #EN_MEXTI_LINE15
 *
 * @return The system state after disabling the EXTI line.
 *         - #EN_MEXTI_OK: EXTI line disabling successful.
 *         - #EN_MEXTI_NOK: EXTI line disabling failed.
 *         - #EN_MEXTI_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MEXTI_systemState_t MEXTI_disableEXTI(EN_MEXTI_lines_t copy_uddtLineNum);

/**
 * @brief Generate a software interrupt on the specified EXTI line.
 *
 * This function generates a software interrupt on the specified EXTI line.
 *
 * @param copy_uddtLineNum The EXTI line number to trigger.
 *        Possible values are:
 *        - #EN_MEXTI_LINE0
 *        - #EN_MEXTI_LINE1
 *        - ...
 *        - #EN_MEXTI_LINE15
 *
 * @return The system state after triggering the software interrupt.
 *         - #EN_MEXTI_OK: Software interrupt triggering successful.
 *         - #EN_MEXTI_NOK: Software interrupt triggering failed.
 *         - #EN_MEXTI_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MEXTI_systemState_t MEXTI_softwareInterrupt(EN_MEXTI_lines_t copy_uddtLineNum);

/**
 * @brief Set the trigger source for the specified EXTI line.
 *
 * This function sets the trigger source for the specified EXTI line.
 *
 * @param copy_uddtLineNum The EXTI line number to configure.
 *        Possible values are:
 *        - #EN_MEXTI_LINE0
 *        - #EN_MEXTI_LINE1
 *        - ...
 *        - #EN_MEXTI_LINE15
 * @param copy_uddtTriggerOption The trigger source option.
 *        Possible values are:
 *        - #EN_MEXTI_TRIGGER_RISING_EDGE
 *        - #EN_MEXTI_TRIGGER_FALLING_EDGE
 *        - #EN_MEXTI_TRIGGER_BOTH_EDGES
 *
 * @return The system state after setting the trigger source.
 *         - #EN_MEXTI_OK: Trigger source setting successful.
 *         - #EN_MEXTI_NOK: Trigger source setting failed.
 *         - #EN_MEXTI_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MEXTI_systemState_t MEXTI_setTriggerSource(EN_MEXTI_lines_t copy_uddtLineNum, EN_MEXTI_triggerOptions_t copy_uddtTriggerOption);

/**
 * @brief Set the EXTI configuration for the specified GPIO pin.
 *
 * This function sets the EXTI configuration for the specified GPIO pin.
 *
 * @param copy_uddtLineNum The EXTI line number to configure.
 *        Possible values are:
 *        - #EN_MEXTI_LINE0
 *        - #EN_MEXTI_LINE1
 *        - ...
 *        - #EN_MEXTI_LINE15
 * @param copy_uddtPortNum The GPIO port number.
 *        Possible values are:
 *        - #EN_MEXTI_PORTA
 *        - #EN_MEXTI_PORTB
 *        - #EN_MEXTI_PORTC
 *        - ...
 *        - #EN_MEXTI_PORTH
 *
 * @return The system state after setting the EXTI configuration.
 *         - #EN_MEXTI_OK: EXTI configuration setting successful.
 *         - #EN_MEXTI_NOK: EXTI configuration setting failed.
 *         - #EN_MEXTI_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MEXTI_systemState_t MEXTI_setExtiConfig(EN_MEXTI_lines_t copy_uddtLineNum, EN_MEXTI_port_t copy_uddtPortNum);

/**
 * @brief Set the callback function for the specified EXTI line.
 *
 * This function sets the callback function for the specified EXTI line.
 *
 * @param ptr Pointer to the callback function.
 * @param copy_uddtLineNum The EXTI line number to set the callback for.
 *        Possible values are:
 *        - #EN_MEXTI_LINE0
 *        - #EN_MEXTI_LINE1
 *        - ...
 *        - #EN_MEXTI_LINE15
 *
 * @return The system state after setting the callback function.
 *         - #EN_MEXTI_OK: Callback function setting successful.
 *         - #EN_MEXTI_NOK: Callback function setting failed.
 *         - #EN_MEXTI_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #EN_MEXTI_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MEXTI_systemState_t MEXTI_setCallBack(void (*ptr)(void), EN_MEXTI_lines_t copy_uddtLineNum);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
