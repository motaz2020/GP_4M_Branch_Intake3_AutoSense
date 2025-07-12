/**
 * @file systick_interface.h
 *
 * @brief Header file for the SysTick (System Timer) module interface.
 */
#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "systick_private.h"
#include "systick_config.h"

/**
 * @brief Initialize the SysTick timer.
 *
 * This function initializes the SysTick timer with the specified clock source and interrupt state.
 *
 * @param copy_uddtClkSource The clock source option (MSTK_CLK_AHB_8, MSTK_CLK_PROCESSOR_AHB).
 * @param copy_uddtIntStates The interrupt state option (MSTK_INTERRUPT_ENABLED, MSTK_INTERRUPT_DISABLED).
 *
 * @return The system state after initializing the SysTick timer.
 * - MSTK_OK: Operation successful.
 * - MSTK_NOK: Operation failed.
 * - MSTK_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MSTK_systemState_t MSTK_init(EN_MSTK_clkSourceOptions_t copy_uddtClkSource, EN_MSTK_interruptStates_t copy_uddtIntStates);

/**
 * @brief Set a busy-wait delay using the SysTick timer.
 *
 * This function sets a busy-wait delay using the SysTick timer for the specified number of ticks.
 *
 * @param copy_u32NumberOfTicks The number of ticks for the busy-wait delay.
 *
 * @return The system state after setting the busy-wait delay.
 * - MSTK_OK: Operation successful.
 * - MSTK_NOK: Operation failed.
 * - MSTK_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MSTK_systemState_t MSTK_setBusyWait(uint32_t copy_u32NumberOfTicks);

/**
 * @brief Set a single-shot interval using the SysTick timer.
 *
 * This function sets a single-shot interval using the SysTick timer for the specified number of ticks and associates a callback function.
 *
 * @param copy_u32NumberOfTicks The number of ticks for the single-shot interval.
 * @param Pf Pointer to the callback function to be executed after the interval elapses.
 *
 * @return The system state after setting the single-shot interval.
 * - MSTK_OK: Operation successful.
 * - MSTK_NOK: Operation failed.
 * - MSTK_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MSTK_systemState_t MSTK_SetIntervalSingle(uint32_t copy_u32NumberOfTicks, void (*Pf)(void));

/**
 * @brief Set a periodic interval using the SysTick timer.
 *
 * This function sets a periodic interval using the SysTick timer for the specified number of ticks and associates a callback function.
 *
 * @param copy_u32NumberOfTicks The number of ticks for the periodic interval.
 * @param Pf Pointer to the callback function to be executed after each interval elapses.
 *
 * @return The system state after setting the periodic interval.
 * - MSTK_OK: Operation successful.
 * - MSTK_NOK: Operation failed.
 * - MSTK_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MSTK_systemState_t MSTK_SetIntervalPeriodic(uint32_t copy_u32NumberOfTicks, void (*Pf)(void));

/**
 * @brief Stop the current interval in the SysTick timer.
 *
 * This function stops the current interval in the SysTick timer.
 *
 * @return The system state after stopping the interval.
 * - MSTK_OK: Operation successful.
 * - MSTK_NOK: Operation failed.
 * - MSTK_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MSTK_systemState_t MSTK_StopInterval(void);

/**
 * @brief Get the elapsed time since the last SysTick timer initialization.
 *
 * This function retrieves the elapsed time since the last SysTick timer initialization.
 *
 * @param copy_u32PtrRetOfElapsedTicks Pointer to store the result of the elapsed ticks.
 *
 * @return The system state after getting the elapsed time.
 * - MSTK_OK: Operation successful.
 * - MSTK_NOK: Operation failed.
 * - MSTK_INVALID_PARAMTER: Invalid parameter detected.
 */
EN_MSTK_systemState_t MSTK_getElapsedTime(uint32_t *copy_u32PtrRetOfElapsedTicks);

/**
 * @brief Get the remaining time in the current SysTick timer interval.
 *
 * This function retrieves the remaining time in the current SysTick timer interval.
 *
 * @param copy_u32PtrRetOfRemainingTicks Pointer to store the result of the remaining ticks.
 *
 * @return The system state after getting the remaining time.
 *
*/
#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
