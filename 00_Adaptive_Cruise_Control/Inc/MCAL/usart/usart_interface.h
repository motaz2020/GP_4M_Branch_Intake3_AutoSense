/**
 * @file usart_interface.h
 * @brief Header file for the Universal Synchronous/Asynchronous Receiver Transmitter (MUSART) module.
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include "../../COMMON/std_types.h"
#include "../../COMMON/bit_math.h"
#include "../../MCAL/gpio/gpio_interface.h"
#include "usart_private.h"
#include "usart_config.h"


/**
 * @brief Initialize the USART module with the given configuration.
 *
 * This function initializes the USART module with the provided configuration.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param PS_uddtUartCfg Pointer to the USART configuration structure.
 *
 * @return The system state after initializing the USART module.
 *         - #EN_MUSART_OK: Initialization successful.
 *         - #EN_MUSART_NOK: Initialization failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtInit(ST_MUART_RegistersMap_t *PS_USARTx, ST_MUSART_cfg_t const *PS_uddtUartCfg);

/**
 * @brief Enable the USART module.
 *
 * This function enables the USART module.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 *
 * @return The system state after enabling the USART module.
 *         - #EN_MUSART_OK: USART enabling successful.
 *         - #EN_MUSART_NOK: USART enabling failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtEnable(ST_MUART_RegistersMap_t *PS_USARTx);

/**
 * @brief Disable the USART module.
 *
 * This function disables the USART module.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 *
 * @return The system state after disabling the USART module.
 *         - #EN_MUSART_OK: USART disabling successful.
 *         - #EN_MUSART_NOK: USART disabling failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtDisable(ST_MUART_RegistersMap_t *PS_USARTx);

/**
 * @brief Transmit a byte through the USART module.
 *
 * This function transmits a byte through the USART module.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8ByteToSend The byte to transmit.
 *
 * @return The system state after transmitting the byte.
 *         - #EN_MUSART_OK: Byte transmission successful.
 *         - #EN_MUSART_NOK: Byte transmission failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtTransmitByte(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8ByteToSend);

/**
 * @brief Transmit a string through the USART module.
 *
 * This function transmits a string through the USART module.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8StringToSend Pointer to the string to transmit.
 *
 * @return The system state after transmitting the string.
 *         - #EN_MUSART_OK: String transmission successful.
 *         - #EN_MUSART_NOK: String transmission failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtTransmitString(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8StringToSend);

/**
 * @brief Read data from the USART data register.
 *
 * This function reads data from the USART data register.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8ByteToReceive Pointer to store the received byte.
 *
 * @return The system state after reading the data register.
 *         - #EN_MUSART_OK: Data read successful.
 *         - #EN_MUSART_NOK: Data read failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtReadDataRegister(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Clear the USART flags.
 *
 * This function clears the USART flags.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 *
 * @return The system state after clearing the USART flags.
 *         - #EN_MUSART_OK: Flag clearing successful.
 *         - #EN_MUSART_NOK: Flag clearing failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtClearFlags(ST_MUART_RegistersMap_t *PS_USARTx);

/**
 * @brief Receive a byte asynchronously in a non-blocking manner.
 *
 * This function receives a byte asynchronously in a non-blocking manner.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8ByteToReceive Pointer to store the received byte.
 *
 * @return The system state after receiving the byte.
 *         - #EN_MUSART_OK: Byte reception successful.
 *         - #EN_MUSART_NOK: Byte reception failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtReceiveByteSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Receive a string asynchronously in a blocking manner.
 *
 * This function receives a string asynchronously in a blocking manner.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8ByteToReceive Pointer to store the received string.
 *
 * @return The system state after receiving the string.
 *         - #EN_MUSART_OK: String reception successful.
 *         - #EN_MUSART_NOK: String reception failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtReceiveStringAsynchBlocking(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Receive a string asynchronously in a non-blocking manner.
 *
 * This function receives a string asynchronously in a non-blocking manner.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8ByteToReceive Pointer to store the received string.
 *
 * @return The system state after receiving the string.
 *         - #EN_MUSART_OK: String reception successful.
 *         - #EN_MUSART_NOK: String reception failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_uddtReceiveStringSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t *copy_u8ByteToReceive);

/**
 * @brief Set the receive interrupt status for the USART module.
 *
 * This function sets the receive interrupt status for the USART module.
 *
 * @param PS_USARTx Pointer to the USARTx registers map.
 * @param copy_u8Status The status to set.
 *
 * @return The system state after setting the receive interrupt status.
 *         - #EN_MUSART_OK: Status setting successful.
 *         - #EN_MUSART_NOK: Status setting failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART_RxIntSetStatus(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8Status);

/**
 * @brief Set the callback function for USART1.
 *
 * This function sets the callback function for USART1.
 *
 * @param ptr Pointer to the callback function.
 *
 * @return The system state after setting the callback function.
 *         - #EN_MUSART_OK: Callback setting successful.
 *         - #EN_MUSART_NOK: Callback setting failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART1_uddtSetCallBack(void (*ptr)(void));

/**
 * @brief Set the callback function for USART2.
 *
 * This function sets the callback function for USART2.
 *
 * @param ptr Pointer to the callback function.
 *
 * @return The system state after setting the callback function.
 *         - #EN_MUSART_OK: Callback setting successful.
 *         - #EN_MUSART_NOK: Callback setting failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART2_uddtSetCallBack(void (*ptr)(void));

/**
 * @brief Set the callback function for USART6.
 *
 * This function sets the callback function for USART6.
 *
 * @param ptr Pointer to the callback function.
 *
 * @return The system state after setting the callback function.
 *         - #EN_MUSART_OK: Callback setting successful.
 *         - #EN_MUSART_NOK: Callback setting failed.
 *         - #EN_MUSART_PTR_NULL: Null pointer encountered during the operation.
 */
EN_MUSART_systeamState_t MUSART6_uddtSetCallBack(void (*ptr)(void));


#endif /* MCAL_USART_USART_INTERFACE_H_ */
