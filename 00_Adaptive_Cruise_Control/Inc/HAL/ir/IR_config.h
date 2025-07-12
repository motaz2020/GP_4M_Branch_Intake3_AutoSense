/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : IR_config.h                                  	     
// Date          : Nov 7, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef HAL_IR_IR_CONFIG_H_
#define HAL_IR_IR_CONFIG_H_

/**
 * @brief Enumeration for the system state of the Human Interface Receiver (HIR) module.
 *
 * This enumeration defines possible system states for the HIR module.
 */
typedef enum
{
    HIR_NOK = 0,      /**< HIR module encountered an error. */
    HIR_OK,           /**< HIR module operation successful. */
    HIR_PTR_NULL      /**< Null pointer encountered during the operation. */
} EN_HIR_systemState_t;

/**
 * @brief Enumeration for the surface state of the Human Interface Receiver (HIR) module.
 *
 * This enumeration defines possible surface states for the HIR module.
 */
typedef enum
{
    HIR_ON_WHITE = 0, /**< HIR module is on a white surface. */
    HIR_ON_BLACK      /**< HIR module is on a black surface. */
} EN_HIR_surfaceState_t;

/**
 * @brief Configuration structure for the Human Interface Receiver (HIR) module.
 *
 * This structure holds the configuration parameters for the HIR module.
 */
typedef struct
{
    ST_MGPIOx_RegistersMap_t *HIR_port;       /**< Pointer to the GPIO port for the HIR module. */
    EN_MGPIO_pinOptions_t    HIR_pin;        /**< Pin option for the HIR module. */
} ST_HIR_cfg_t;

#endif /* HAL_IR_IR_CONFIG_H_ */
