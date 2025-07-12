/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : LKA_config.h                                  	     
// Date          : Nov 7, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
/**
 * @file
 * @brief Configuration file for Lane Keep Assistant (LKA) application.
 */

#ifndef APPLICATION_LANE_KEEP_ASSISTANT_LKA_CONFIG_H_
#define APPLICATION_LANE_KEEP_ASSISTANT_LKA_CONFIG_H_

/**
 * @defgroup LKA_Configuration Lane Keep Assistant (LKA) Configuration
 * @{
 */

/**
 * @brief Enumeration representing different system states for Lane Keep Assistant (LKA).
 */
typedef enum
{
    ALKA_IN_LANE = 0,           /**< Car is in the lane. */
    ALKA_OUT_LEFT_LANE,         /**< Car is out of the left lane. */
    ALKA_OUT_RIGHT_LANE,        /**< Car is out of the right lane. */
    ALKA_OUT_BOTH_LANE,         /**< Car is out of both lanes. */
    ALKA_PTR_NULL,              /**< Pointer is null (used for error handling). */
    ALKA_POS_SET                /**< Lane position is set. */
} EN_ALKA_systeamState_t;

/** @} */ // End of LKA_Configuration group

#endif /* APPLICATION_LANE_KEEP_ASSISTANT_LKA_CONFIG_H_ */
