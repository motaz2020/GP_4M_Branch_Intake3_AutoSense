/**
 * @file nvic_interface.h
 *
 * @brief Header file for the NVIC (Nested Vectored Interrupt Controller) module interface.
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "nvic_private.h"
#include "nvic_config.h"

/**
 * @brief Enable an interrupt in the NVIC.
 *
 * This function enables the specified interrupt in the NVIC.
 *
 * @param copy_u8IntPos The position of the interrupt to enable.
 *
 * @return The system state after enabling the interrupt.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_enableInterrupt(uint8_t copy_u8IntPos);

/**
 * @brief Disable an interrupt in the NVIC.
 *
 * This function disables the specified interrupt in the NVIC.
 *
 * @param copy_u8IntPos The position of the interrupt to disable.
 *
 * @return The system state after disabling the interrupt.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_disableInterrupt(uint8_t copy_u8IntPos);

/**
 * @brief Enable pending status for an interrupt in the NVIC.
 *
 * This function enables the pending status for the specified interrupt in the NVIC.
 *
 * @param copy_u8IntPos The position of the interrupt to enable pending status for.
 *
 * @return The system state after enabling pending status for the interrupt.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_enableInterruptPending(uint8_t copy_u8IntPos);

/**
 * @brief Disable pending status for an interrupt in the NVIC.
 *
 * This function disables the pending status for the specified interrupt in the NVIC.
 *
 * @param copy_u8IntPos The position of the interrupt to disable pending status for.
 *
 * @return The system state after disabling pending status for the interrupt.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_disableInterruptPending(uint8_t copy_u8IntPos);

/**
 * @brief Check if an interrupt is active in the NVIC.
 *
 * This function checks if the specified interrupt is active in the NVIC.
 *
 * @param copy_u8IntPos The position of the interrupt to check.
 * @param ptrOfRetReading Pointer to store the result of the interrupt's active status.
 *
 * @return The system state after checking the interrupt's active status.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_IsInterruptActive(uint8_t copy_u8IntPos, uint8_t *ptrOfRetReading);

/**
 * @brief Set the priority of an interrupt in the NVIC.
 *
 * This function sets the priority of the specified interrupt in the NVIC.
 *
 * @param copy_u8IntPos The position of the interrupt to set the priority for.
 * @param copy_uddtGroupOption The priority grouping option (GP_16_SP_00, GP_08_SP_02, GP_04_SP_04, GP_02_SP_08, GP_00_SP_16).
 * @param copy_u8GroupPriority The group priority value (0 to 15).
 * @param copy_u8SubPriority The subpriority value (0 to 15).
 *
 * @return The system state after setting the interrupt priority.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_SetInterruptPriority(uint8_t copy_u8IntPos, EN_MNVIC_priorityGrouping_t copy_uddtGroupOption, uint8_t copy_u8GroupPriority, uint8_t copy_u8SubPriority);

/**
 * @brief Set the priority grouping for the NVIC.
 *
 * This function sets the priority grouping for the NVIC.
 *
 * @param copy_uddtGroupOption The priority grouping option (GP_16_SP_00, GP_08_SP_02, GP_04_SP_04, GP_02_SP_08, GP_00_SP_16).
 *
 * @return The system state after setting the priority grouping.
 * - MNVIC_OK: Operation successful.
 * - MNVIC_NOK: Operation failed.
 * - MNVIC_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MNVIC_systemState_t MNVIC_SetInterruptGroup(EN_MNVIC_priorityGrouping_t copy_uddtGroupOption);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
