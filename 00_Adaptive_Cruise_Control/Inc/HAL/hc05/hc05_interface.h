/**
 * @file hc05_interface.h
 * @brief Header file for the Bluetooth Module (HHC05) module.
 */

#ifndef HAL_HC05_HC05_INTERFACE_H_
#define HAL_HC05_HC05_INTERFACE_H_

#include "../../MCAL/usart/usart_interface.h"
#include "hc05_config.h"


/**
 * @brief Initialize the HHC05 module using the specified UART configuration.
 *
 * This function initializes the HHC05 module using the provided UART configuration.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param PS_uddtUartCfg Pointer to the UART configuration structure.
 *
 * @return The system state after initializing the HHC05 module.
 *         - #HHC05_OK: HHC05 module initialization successful.
 *         - #HHC05_NOK: HHC05 module initialization failed.
 *         - #HHC05_PTR_NULL: Null pointer encountered during the operation.
 */
EN_HHC05_systeamState_t HHC05_uddtInit(ST_MUART_RegistersMap_t *PS_USARTx, ST_MUSART_cfg_t const *PS_uddtUartCfg);

/**
 * @brief Enable the HHC05 module.
 *
 * This function enables the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 *
 * @return The system state after enabling the HHC05 module.
 *         - #HHC05_OK: HHC05 module enabling successful.
 *         - #HHC05_NOK: HHC05 module enabling failed.
 */
EN_HHC05_systeamState_t HHC05_uddtEnable(ST_MUART_RegistersMap_t *PS_USARTx);

/**
 * @brief Disable the HHC05 module.
 *
 * This function disables the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 *
 * @return The system state after disabling the HHC05 module.
 *         - #HHC05_OK: HHC05 module disabling successful.
 *         - #HHC05_NOK: HHC05 module disabling failed.
 */
EN_HHC05_systeamState_t HHC05_uddtDisable(ST_MUART_RegistersMap_t *PS_USARTx);

/**
 * @brief Transmit a byte through the HHC05 module.
 *
 * This function transmits a byte through the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8ByteToSend The byte to transmit.
 *
 * @return The system state after transmitting the byte.
 *         - #HHC05_OK: Byte transmission successful.
 *         - #HHC05_NOK: Byte transmission failed.
 */
EN_HHC05_systeamState_t HHC05_uddtTransmitByte(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8ByteToSend);

/**
 * @brief Transmit a string through the HHC05 module.
 *
 * This function transmits a string through the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8StringToSend The string to transmit.
 *
 * @return The system state after transmitting the string.
 *         - #HHC05_OK: String transmission successful.
 *         - #HHC05_NOK: String transmission failed.
 */
EN_HHC05_systeamState_t HHC05_uddtTransmitString(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8StringToSend);

/**
 * @brief Read a byte from the HHC05 module data register.
 *
 * This function reads a byte from the HHC05 module data register.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8ByteToReceive Pointer to store the received byte.
 *
 * @return The system state after reading the byte.
 *         - #HHC05_OK: Byte reading successful.
 *         - #HHC05_NOK: Byte reading failed.
 */
EN_HHC05_systeamState_t HHC05_uddtReadDataRegister(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Receive a byte synchronously (non-blocking) from the HHC05 module.
 *
 * This function receives a byte synchronously (non-blocking) from the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8ByteToReceive Pointer to store the received byte.
 *
 * @return The system state after receiving the byte.
 *         - #HHC05_OK: Byte reception successful.
 *         - #HHC05_NOK: Byte reception failed.
 */
EN_HHC05_systeamState_t HHC05_uddtReceiveByteSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Receive a string synchronously (non-blocking) from the HHC05 module.
 *
 * This function receives a string synchronously (non-blocking) from the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8ByteToReceive Pointer to store the received string.
 *
 * @return The system state after receiving the string.
 *         - #HHC05_OK: String reception successful.
 *         - #HHC05_NOK: String reception failed.
 */
EN_HHC05_systeamState_t HHC05_uddtReceiveStringSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Receive a string asynchronously (blocking) from the HHC05 module.
 *
 * This function receives a string asynchronously (blocking) from the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8ByteToReceive Pointer to store the received string.
 *
 * @return The system state after receiving the string.
 *         - #HHC05_OK: String reception successful.
 *         - #HHC05_NOK: String reception failed.
 */
EN_HHC05_systeamState_t HHC05_uddtReceiveStringAsynchBlocking(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Set the status of the receive interrupt for the HHC05 module.
 *
 * This function sets the status of the receive interrupt for the HHC05 module.
 *
 * @param PS_USARTx Pointer to the UART registers map.
 * @param copy_u8Status The status to set for the receive interrupt.
 *
 * @return The system state after setting the interrupt status.
 *         - #HHC05_OK: Interrupt status setting successful.
 *         - #HHC05_NOK: Interrupt status setting failed.
 */
EN_HHC05_systeamState_t HHC05_RxIntSetStatus(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8Status);

/**
 * @brief Set the callback function for UART1 communication with the HHC05 module.
 *
 * This function sets the callback function for UART1 communication with the HHC05 module.
 *
 * @param ptr Pointer to the callback function.
 *
 * @return The system state after setting the callback function.
 *         - #HHC05_OK: Callback function setting successful.
 *         - #HHC05_NOK: Callback function setting failed.
 */
EN_HHC05_systeamState_t HHC05_uddtSetCallBackUart1(void (*ptr)(void));

/**
 * @brief Set the callback function for UART2 communication with the HHC05 module.
 *
 * This function sets the callback function for UART2 communication with the HHC05 module.
 *
 * @param ptr Pointer to the callback function.
 *
 * @return The system state after setting the callback function.
 *         - #HHC05_OK: Callback function setting successful.
 *         - #HHC05_NOK: Callback function setting failed.
 */
EN_HHC05_systeamState_t HHC05_uddtSetCallBackUart2(void (*ptr)(void));

/**
 * @brief Set the callback function for UART6 communication with the HHC05 module.
 *
 * This function sets the callback function for UART6 communication with the HHC05 module.
 *
 * @param ptr Pointer to the callback function.
 *
 * @return The system state after setting the callback function.
 *         - #HHC05_OK: Callback function setting successful.
 *         - #HHC05_NOK: Callback function setting failed.
 */
EN_HHC05_systeamState_t HHC05_uddtSetCallBackUart6(void (*ptr)(void));



#endif /* HAL_HC05_HC05_INTERFACE_H_ */
