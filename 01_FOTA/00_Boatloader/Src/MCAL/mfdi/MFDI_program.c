/*********************************************************************
* File Name    	: 	MFDI_program.c                                   *
* Author       	: 	Mahmoud Gamal                                    *
* Version      	: 	1.0.0                                            *
* Date  		: 	28/09/2023                                       *
* Description   : 			         				                 *
*********************************************************************/

#include "../../../Inc/MCAL/mfdi/MFDI_interface.h"




void MFDI_voidEraseSector(u8 copy_u8SectorNumber)
{

	if((copy_u8SectorNumber != 0) && (copy_u8SectorNumber <= 7))
	{
		/* 1- Check Busy Flag Of SR is Set  */
		while (GET_BIT(MFDI->SR , SR_BSY)==1);
		/* 2- Check The Authorized Of Configuration Operation */
		if (GET_BIT(MFDI->CR , CR_LOCK )==1)
		{
			// Unlock Sequence
			MFDI->KEYR = OPTKEY1;
			MFDI->KEYR = OPTKEY2;
		}

		// Selecting the sector to erase
		MFDI->CR &= 0xFFFFFF87;  // Clearing the Selection bits [bit3 to bit6]
		MFDI->CR |= copy_u8SectorNumber<<CR_SNB; // Selecting the sector

		/* 3- Sector Erase Enable */
		SET_BIT(MFDI->CR,CR_SER);

		/* 4- Set Start Bit  */
		SET_BIT(MFDI->CR,CR_STRT);

		/* 5- Check Busy Flag Of SR is Set  */
		while (GET_BIT(MFDI->SR , SR_BSY)==1);

		/* 6- Clear Bit Of Ending Operation */
		SET_BIT(MFDI->SR,SR_EOP);

		/* 7- Sector Erase Disable */
		CLR_BIT(MFDI->CR,CR_SER);

	}
	else
	{
		/* Wrong Sector Number */
	}

}
void MFDI_voidFlashWrite(u32 copy_u32Address , u16 *copy_u16PtrData , u8 copy_u8DataLength)
{

	if(NULL != copy_u16PtrData)
	{
		// wait if busy bit is set
		while (GET_BIT(MFDI->SR , SR_BSY)==1);

		// check if Authorized for configurations
		if (GET_BIT(MFDI->CR , CR_LOCK )==1)
		{
			//Unlock Sequence
			MFDI->KEYR = OPTKEY1;
			MFDI->KEYR = OPTKEY2;
		}

		// Clear Write Size Bits
		MFDI->CR &= 0xFFFFFCFF;
		// Flash Driver Writes (2Byte)16 bit every once
		MFDI->CR |= SIZE_OF_WRITE_WORD << CR_PSIZE ;

		for (u8 L_u8Iterator =0 ; L_u8Iterator < copy_u8DataLength ; L_u8Iterator ++ )
		{
			// Activate Programming Flash
			SET_BIT(MFDI->CR,CR_PG);
			/* Assign data to required address */
			*((volatile u16*)copy_u32Address)= copy_u16PtrData[L_u8Iterator];
			/* Increment address by 2 to write half word every iteration */
			copy_u32Address += 2;
			// wait if busy bit is set
			while (GET_BIT(MFDI->SR , SR_BSY)==1);
			// Clear the EOP flag
		    SET_BIT(MFDI->SR,SR_EOP);
			// deactivate Programming Flash
			CLR_BIT(MFDI->CR,CR_PG);
		}

	}

}
void MFDI_voidEraseAppArea(u8 Copy_u8AppId)
{
	MFDI_voidEraseSector(Copy_u8AppId);
}
