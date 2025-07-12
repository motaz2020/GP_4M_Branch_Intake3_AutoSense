/**
 * @file MFDI_interface.h
 * @brief Header file for FDI (Flash Driver Interface) module.
 */

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "MFDI_private.h"
#include "MFDI_config.h"


#define FLASH_START_ADDRESS   0x08000000
#define FLASH_APP_ADDRESS     0x08004000

/**
 * @brief Erases a specified sector in the flash memory.
 *
 * This function erases the specified sector in the flash memory.
 *
 * @param copy_u8SectorNumber The sector number to be erased.
 */
void MFDI_voidEraseSector(u8 copy_u8SectorNumber);

/**
 * @brief Writes data to the flash memory at the specified address.
 *
 * This function writes data to the flash memory at the specified address.
 *
 * @param copy_u32Address      The address in the flash memory where the data should be written.
 * @param copy_u16PtrData      A pointer to an array of unsigned 16-bit integers representing the data to be written.
 * @param copy_u8DataLength    The length of the data to be written.
 */
void MFDI_voidFlashWrite(u32 copy_u32Address, u16 *copy_u16PtrData, u8 copy_u8DataLength);

/**
 * @brief Erases a specific application area in the flash memory.
 *
 * This function erases the specified application area in the flash memory.
 *
 * @param Copy_u8AppId The application ID or identifier for the application area to be erased.
 */
void MFDI_voidEraseAppArea(u8 Copy_u8AppId);
#endif
