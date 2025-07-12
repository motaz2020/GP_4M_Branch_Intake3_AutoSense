/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : dcm_config.h                                  	     
// Date          : Oct 17, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_DCM_DCM_CONFIG_H_
#define HAL_DCM_DCM_CONFIG_H_


/**
 * @brief Enumeration for the system states of the DC motor.
 */
typedef enum
{
	DCM_OK = 0,  /**< DC motor operation successful. */
	DCM_NOK     /**< DC motor operation failed. */
} EN_DCM_systemState_t;

/**
 * @brief Enumeration for the states of the DC motor (turn on or off).
 */
typedef enum
{
	DCM_TURN_OFF = 0, /**< DC motor turned off. */
	DCM_TURN_ON      /**< DC motor turned on. */
} EN_DCM_states_t;

/**
 * @brief Enumeration for the direction of the DC motor.
 */
typedef enum
{
	DCM_DIR_CLOCKWISE = 0,       /**< DC motor rotates in the clockwise direction. */
	DCM_DIR_ANTI_CLOCKWISE       /**< DC motor rotates in the anti-clockwise direction. */
} EN_DCM_direction_t;

/**
 * @brief Enumeration for the rotation of the DC motor.
 */
typedef enum
{
	DCM_ROTATE_LEFT = 0,  /**< DC motor rotates to the left. */
	DCM_ROTATE_RIGHT      /**< DC motor rotates to the right. */
} EN_DCM_rotation_t;

typedef struct
{
	ST_MGPIOx_RegistersMap_t  *DCM_5vPort;
	EN_MGPIO_pinOptions_t    DCM_5vPin;
	ST_MGPIOx_RegistersMap_t  *DCM_gndPort;
	EN_MGPIO_pinOptions_t    DCM_gndPin;
	EN_DCM_states_t  	 DCM_intialState;
    EN_DCM_direction_t   DCM_defaultDirection;
}ST_DCM_cfg_t;


#endif /* HAL_DCM_DCM_CONFIG_H_ */
