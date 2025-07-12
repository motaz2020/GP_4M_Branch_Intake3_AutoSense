/**
 * @file rcc_interface.h
 * @brief Header file for RCC (Reset and Clock Control) module.
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_


#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "rcc_private.h"
#include "rcc_config.h"

/**
 * @brief Initialize the MRCC (Reset and Clock Control) module.
 *
 * This function initializes the MRCC module, configuring the system clocks
 * and other essential settings.
 *
 * @return The system initialization state.
 *         Possible values are:
 *         - #EN_MRCC_OK: Initialization successful.
 *         - #EN_MRCC_NOK: Initialization failed.
 *         - #EN_MRCC_PTR_NULL: Null pointer encountered during initialization.
 *         - #EN_MRCC_INVALID_PARAMTER: Invalid parameter detected during initialization.
 */
EN_MRCC_systemState_t MRCC_Init(void);

/**
 * @brief Enable a specific peripheral on a selected bus.
 *
 * This function enables a peripheral on the specified bus.
 *
 * @param busSelection The bus on which the peripheral is located.
 *        Possible values are:
 *        - #EN_MRCC_AHP1_BUS
 *        - #EN_MRCC_AHP2_BUS
 *        - #EN_MRCC_APB1_BUS
 *        - #EN_MRCC_APB2_BUS
 * @param PeripheralNumber The specific peripheral to enable.
 *        Refer to the enumeration #EN_MRCC_peripheralOptions_t for available options.
 *
 * @return The state of peripheral enabling.
 *         Possible values are:
 *         - #EN_MRCC_OK: Peripheral enabling successful.
 *         - #EN_MRCC_NOK: Peripheral enabling failed.
 *         - #EN_MRCC_PTR_NULL: Null pointer encountered during the operation.
 *         - #EN_MRCC_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MRCC_systemState_t MRCC_enablePeripheral(EN_MRCC_busOptions_t busSelection, EN_MRCC_peripheralOptions_t PeripheralNumber);

/**
 * @brief Disable a specific peripheral on a selected bus.
 *
 * This function disables a peripheral on the specified bus.
 *
 * @param busSelection The bus on which the peripheral is located.
 *        Possible values are:
 *        - #EN_MRCC_AHP1_BUS
 *        - #EN_MRCC_AHP2_BUS
 *        - #EN_MRCC_APB1_BUS
 *        - #EN_MRCC_APB2_BUS
 * @param PeripheralNumber The specific peripheral to disable.
 *        Refer to the enumeration #EN_MRCC_peripheralOptions_t for available options.
 *
 * @return The state of peripheral disabling.
 *         Possible values are:
 *         - #EN_MRCC_OK: Peripheral disabling successful.
 *         - #EN_MRCC_NOK: Peripheral disabling failed.
 *         - #EN_MRCC_PTR_NULL: Null pointer encountered during the operation.
 *         - #EN_MRCC_INVALID_PARAMTER: Invalid parameter detected during the operation.
 */
EN_MRCC_systemState_t MRCC_disablePeripheral(EN_MRCC_busOptions_t busSelection, EN_MRCC_peripheralOptions_t PeripheralNumber);

void HAL_DeInit(void);

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
