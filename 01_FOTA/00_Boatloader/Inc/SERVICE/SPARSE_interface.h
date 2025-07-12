/**
 * @file SPARCE_interface.h
 * @brief Header file for Hex_Parse module.
 */

#ifndef MPARSE_INTERFACE_H_
#define MPARSE_INTERFACE_H_

/**
 * @brief Converts an ASCII character to its hexadecimal equivalent.
 *
 * This function takes an ASCII character as input and returns its hexadecimal
 * equivalent as an unsigned 8-bit integer.
 *
 * @param Copy_u8Asci The ASCII character to be converted.
 * @return The hexadecimal equivalent as an unsigned 8-bit integer.
 */
u8 PARSE_u8AsciToHex(u8 Copy_u8Asci);

/**
 * @brief Parses data in a buffer and performs a specific action.
 *
 * This function parses the data in the provided buffer and performs a specific
 * action based on the content of the data.
 *
 * @param Copy_u8BufferData Pointer to the buffer containing the data to be parsed.
 */
void PARSE_voidParseData(u8* Copy_u8BufferData);

/**
 * @brief Parses a record in a buffer and performs a specific action.
 *
 * This function parses a record in the provided buffer and performs a specific
 * action based on the content of the record.
 *
 * @param Copy_u8BufferData Pointer to the buffer containing the record to be parsed.
 */
void PARSE_voidParseRecord(u8* Copy_u8BufferData);

#endif
