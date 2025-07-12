/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : hc05_config.h                                  	     
// Date          : Oct 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_HC05_HC05_CONFIG_H_
#define HAL_HC05_HC05_CONFIG_H_

/**
 * @brief Enumeration for the system states of the HHC05 module.
 */
typedef enum
{
	HHC05_NOK = 0,      /**< HHC05 module operation unsuccessful. */
	HHC05_OK,           /**< HHC05 module operation successful. */
	HHC05_PTR_NULL      /**< Null pointer encountered during the operation. */
} EN_HHC05_systeamState_t;

#endif /* HAL_HC05_HC05_CONFIG_H_ */
