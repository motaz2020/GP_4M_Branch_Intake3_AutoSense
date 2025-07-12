/**
 * @file
 * @brief Configuration file for Normal Cruise Control (NCC) in the Adaptive Cruise Control project.
 *
 * @author Sherif Ashraf Khadr
 * @date Oct 18, 2023
 * @see https://github.com/sherifkhadr
 */

#ifndef APPLICATION_NORMAL_CRUISE_CONTROL_NCC_CONFIG_H_
#define APPLICATION_NORMAL_CRUISE_CONTROL_NCC_CONFIG_H_

/**
 * @defgroup NCC_Configuration Normal Cruise Control (NCC) Configuration
 * @{
 */

/**
 * @brief Macro to represent the speed increment operation in NCC.
 * @details This macro defines the operation used for incrementing the speed in the NCC system.
 */
#define NCC_INCREMENT_SPEED +

/**
 * @brief Macro to represent the speed decrement operation in NCC.
 * @details This macro defines the operation used for decrementing the speed in the NCC system.
 */
#define NCC_DECREMENT_SPEED -

/** @} */ // End of NCC_Configuration group

#endif /* APPLICATION_NORMAL_CRUISE_CONTROL_NCC_CONFIG_H_ */
