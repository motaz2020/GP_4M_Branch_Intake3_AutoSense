/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : acc_config.h                                  	     
// Date          : Oct 23, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Configuration file for Adaptive Cruise Control (ACC) in the application.
 */

#ifndef APPLICATION_ADAPTIVE_CRUISE_CONTROL_ACC_CONFIG_H_
#define APPLICATION_ADAPTIVE_CRUISE_CONTROL_ACC_CONFIG_H_

/**
 * @defgroup ACC_Configuration ACC Configuration
 * @{
 */

/**
 * @brief Red range definition for ACC.
 * @details Define the red range for the ACC system.
 *          This range may represent a specific condition or state.
 */
#define RED_RANGE   0

/**
 * @brief Blue range definition for ACC.
 * @details Define the blue range for the ACC system.
 *          This range may represent a specific condition or state.
 */
#define BLUE_RANGE  20

/**
 * @brief Green range definition for ACC.
 * @details Define the green range for the ACC system.
 *          This range may represent a specific condition or state.
 */
#define GREEN_RANGE 50

/** @} */ // End of ACC_Configuration group

#endif /* APPLICATION_ADAPTIVE_CRUISE_CONTROL_ACC_CONFIG_H_ */
