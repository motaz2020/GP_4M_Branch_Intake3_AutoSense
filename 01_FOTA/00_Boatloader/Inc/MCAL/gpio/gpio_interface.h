/**
 * @file gpio_interface.h
 *
 * @brief Header file for GPIO (General Purpose I/O) module.
 */
#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "gpio_private.h"
#include "gpio_config.h"

/**
 * @brief Set the mode of a GPIO pin.
 *
 * This function sets the mode of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtPinMode The mode to set for the pin.
 *        Possible values are:
 *        - #MGPIO_MODE_INPUT
 *        - #MGPIO_MODE_OUTPUT
 *        - #MGPIO_MODE_ALTF
 *        - #MGPIO_MODE_ANALOG
 *
 * @return The system state after setting the pin mode.
 *         - #MGPIO_OK: Pin mode setting successful.
 *         - #MGPIO_NOK: Pin mode setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetPinMode(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_pinModeOptions_t copy_uddtPinMode);

/**
 * @brief Set the output mode of a GPIO pin.
 *
 * This function sets the output mode of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtOutputResistor The output resistor option.
 *        Possible values are:
 *        - #MGPIO_OUTPUT_RESISTOR_PUSH_PULL
 *        - #MGPIO_OUTPUT_RESISTOR_OPEN_DRAIN
 *
 * @return The system state after setting the pin output mode.
 *         - #MGPIO_OK: Pin output mode setting successful.
 *         - #MGPIO_NOK: Pin output mode setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetOutputMode(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_outputResistorOptions_t copy_uddtOutputResistor);

/**
 * @brief Set the output speed of a GPIO pin.
 *
 * This function sets the output speed of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtOutputSpeed The output speed option.
 *        Possible values are:
 *        - #MGPIO_OUTPUT_SPEED_LOW
 *        - #MGPIO_OUTPUT_SPEED_MEDIUM
 *        - #MGPIO_OUTPUT_SPEED_HIGH
 *        - #MGPIO_OUTPUT_SPEED_VERY_HIGH
 *
 * @return The system state after setting the pin output speed.
 *         - #MGPIO_OK: Pin output speed setting successful.
 *         - #MGPIO_NOK: Pin output speed setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetOutputSpeed(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_outputSpeedOptions_t copy_uddtOutputSpeed);

/**
 * @brief Set the pull state of a GPIO pin.
 *
 * This function sets the pull state of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtPullState The pull state option.
 *        Possible values are:
 *        - #MGPIO_PULL_FLOATING
 *        - #MGPIO_PULL_PULL_UP
 *        - #MGPIO_PULL_PULL_DOWN
 *
 * @return The system state after setting the pin pull state.
 *         - #MGPIO_OK: Pin pull state setting successful.
 *         - #MGPIO_NOK: Pin pull state setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetPullState(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_pushPullOptions_t copy_uddtPullState);

/**
 * @brief Get the logic level of a GPIO pin.
 *
 * This function retrieves the logic level of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to read.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtPtrRetOfPinLogic Pointer to store the retrieved logic level.
 *
 * @return The system state after getting the pin logic level.
 *         - #MGPIO_OK: Pin logic level retrieval successful.
 *         - #MGPIO_NOK: Pin logic level retrieval failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtGetPinVal(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_pinLogicOptions_t *copy_uddtPtrRetOfPinLogic);

/**
 * @brief Set the logic level of a GPIO pin.
 *
 * This function sets the logic level of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtPinLogic The logic level to set for the pin.
 *        Possible values are:
 *        - #MGPIO_LOGIC_LOW
 *        - #MGPIO_LOGIC_HIGH
 *
 * @return The system state after setting the pin logic level.
 *         - #MGPIO_OK: Pin logic level setting successful.
 *         - #MGPIO_NOK: Pin logic level setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetPinVal(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_pinLogicOptions_t copy_uddtPinLogic);

/**
 * @brief Perform a direct set/reset operation on a GPIO pin.
 *
 * This function performs a direct set/reset operation on a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param copy_uddtSetResetState The set/reset option.
 *        Possible values are:
 *        - #MGPIO_PIN_RESET
 *        - #MGPIO_PIN_SET
 *
 * @return The system state after the set/reset operation.
 *         - #MGPIO_OK: Set/reset operation successful.
 *         - #MGPIO_NOK: Set/reset operation failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtDirectSetReset(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_setResetOptions_t copy_uddtSetResetState);

/**
 * @brief Set the value of an entire GPIO port.
 *
 * This function sets the value of an entire GPIO port.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_u16OutputVal The value to set for the entire port.
 *
 * @return The system state after setting the port value.
 *         - #MGPIO_OK: Port value setting successful.
 *         - #MGPIO_NOK: Port value setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetPortVal(ST_MGPIOx_RegistersMap_t *PS_GPIOx, uint16_t copy_u16OutputVal);

/**
 * @brief Set the alternate function of a GPIO pin.
 *
 * This function sets the alternate function of a specified GPIO pin.
 *
 * @param PS_GPIOx Pointer to the GPIOx registers map.
 * @param copy_uddtPinNum The pin number to configure.
 *        Possible values are:
 *        - #MGPIO_PIN0
 *        - #MGPIO_PIN1
 *        - ...
 *        - #MGPIO_PIN15
 * @param Copy_uddtAltFun The alternate function option.
 *        Possible values are:
 *        - #MGPIO_ALTFN_0
 *        - #MGPIO_ALTFN_1
 *        - ...
 *        - #MGPIO_ALTFN_15
 *
 * @return The system state after setting the alternate function.
 *         - #MGPIO_OK: Alternate function setting successful.
 *         - #MGPIO_NOK: Alternate function setting failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtSetAltFun(ST_MGPIOx_RegistersMap_t *PS_GPIOx, EN_MGPIO_pinOptions_t copy_uddtPinNum, EN_MGPIO_altfnOptions_t Copy_uddtAltFun);

/**
 * @brief Initialize a GPIO pin based on a configuration structure.
 *
 * This function initializes a GPIO pin based on the provided configuration structure.
 *
 * @param PS_pinInstance Pointer to the GPIO pin configuration structure.
 *
 * @return The system state after initializing the GPIO pin.
 *         - #MGPIO_OK: GPIO pin initialization successful.
 *         - #MGPIO_NOK: GPIO pin initialization failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtInitPin(ST_MGPIO_pinCfg_t *PS_pinInstance);

/**
 * @brief Initialize an alternate GPIO pin based on a configuration structure.
 *
 * This function initializes an alternate GPIO pin based on the provided configuration structure.
 *
 * @param PS_altPinInstance Pointer to the alternate GPIO pin configuration structure.
 *
 * @return The system state after initializing the alternate GPIO pin.
 *         - #MGPIO_OK: Alternate GPIO pin initialization successful.
 *         - #MGPIO_NOK: Alternate GPIO pin initialization failed.
 *         - #MGPIO_INVALID_PARAMTER: Invalid parameter detected during the operation.
 *         - #MGPIO_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MGPIO_systemState_t MGPIO_uddtInitAltPin(ST_MGPIO_altPinCfg_t *PS_altPinInstance);


//EN_MGPIO_systemState_t MGPIO_PinLock 		(u8 copy_u8PortName , u8 copy_u8PinNum );
//EN_MGPIO_systemState_t MGPIO_SetPortMode (u8 Copy_u8PortName , u8 Copy_u8Mode);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
