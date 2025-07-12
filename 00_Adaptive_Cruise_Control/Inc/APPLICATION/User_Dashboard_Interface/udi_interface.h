/**
 * @file
 * @brief Interface for User Dashboard in the Adaptive Cruise Control project.
 *
 * @author Sherif Ashraf Khadr
 * @date Oct 18, 2023
 * @see https://github.com/sherifkhadr
 */

#ifndef APPLICATION_USER_DASHBOARD_INTERFACE_UDI_INTERFACE_H_
#define APPLICATION_USER_DASHBOARD_INTERFACE_UDI_INTERFACE_H_

#include "../../HAL/hc05/hc05_interface.h"

/**
 * @defgroup UDI_Interface User Dashboard Interface (UDI) Interface
 * @{
 */

/**
 * @brief Initialize the User Dashboard Interface (UDI).
 *
 * @param PS_USARTx Pointer to the USART registers map.
 * @param PS_uddtUartCfg Pointer to the USART configuration structure.
 * @param ptr Pointer to the callback function.
 */
void AUDI_vInitInterface(ST_MUART_RegistersMap_t *PS_USARTx, ST_MUSART_cfg_t const *PS_uddtUartCfg, void (*ptr)(void));

/**
 * @brief Put the User Dashboard Interface (UDI) in standby mode.
 *
 * @param PS_USARTx Pointer to the USART registers map.
 */
void AUDI_vStandByDashboard(ST_MUART_RegistersMap_t *PS_USARTx);

/**
 * @brief Turn on the User Dashboard Interface (UDI).
 *
 * @param PS_USARTx Pointer to the USART registers map.
 */
void AUDI_vOnDashboard(ST_MUART_RegistersMap_t *PS_USARTx);

/** @} */ // End of UDI_Interface group

#endif /* APPLICATION_USER_DASHBOARD_INTERFACE_UDI_INTERFACE_H_ */
