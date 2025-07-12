/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Body_Control_Module
// File          : bcm_interface.h
// Date          : Oct 17, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Interface for Body Control Module (BCM) in the application.
 */

#ifndef APPLICATION_BODY_CONTROL_MODULE_BCM_INTERFACE_H_
#define APPLICATION_BODY_CONTROL_MODULE_BCM_INTERFACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bcm_config.h"
#include "../../COMMON/std_types.h"
#include "../../MCAL/rcc/rcc_interface.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "../../MCAL/tmr/tmr_interface.h"
#include "../../MCAL/nvic/nvic_interface.h"
#include "../../HAL/ir/IR_interface.h"
#include "../../HAL/ultrasonic/ult_interface.h"
#include "../../MCAL/exti/exti_interface.h"
#include "../User_Dashboard_Interface/udi_interface.h"
#include "../Normal_Cruise_Control/ncc_interface.h"
#include "../Adaptive_Cruise_Control/acc_interface.h"
#include "../Automatic_Emergency_Brake/aeb_interface.h"
#include "../Lane_Keep_Assistant/LKA_interface.h"

/**
 * @defgroup BCM_Interface Body Control Module (BCM) Interface
 * @{
 */

/**
 * @brief Initialize the Body Control Module (BCM) system.
 * @details This function initializes the necessary components and modules for the BCM system.
 */
void ABCM_vSysInit(void);

/**
 * @brief Manage the Body Control Module (BCM) system.
 * @details This function manages the overall operation of the BCM system.
 *          It includes handling different states and modes of the car.
 */
void ABCM_vSysMangment(void);

/**
 * @brief Execute the Body Control Module (BCM) in thread mode.
 * @details This function represents the thread mode execution of the BCM system.
 *          It may perform tasks related to the thread-based functionality of the BCM.
 */
void ABCM_vThreadMode(void);

/**
 * @brief Determine the car state based on the given action.
 * @details This function determines the car state based on the provided action.
 *
 * @param copy_u8Action Action to be considered for determining the car state.
 * @return Enumeration representing the determined car state.
 */
EN_ABCM_carStates_t ABCM_uddtDetermineCarState(uint8_t copy_u8Action);

/**
 * @brief Detect faults in the Body Control Module (BCM) system.
 * @details This function detects faults in the BCM system based on the provided fault code.
 *
 * @param copy_uddtFaultCode Fault code to be used for fault detection.
 * @return Enumeration representing the detected car state after fault detection.
 */
EN_ABCM_carStates_t ABCM_uddtFaultDetection(EN_ABCM_faultCodes_t copy_uddtFaultCode);

/** @} */ // End of BCM_Interface group

#endif /* APPLICATION_BODY_CONTROL_MODULE_BCM_INTERFACE_H_ */
