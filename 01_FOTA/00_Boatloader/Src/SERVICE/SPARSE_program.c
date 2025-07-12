/*********************************************************************
* File Name    	: 	HEX_PARCE.c             	                     *
* Author       	: 	Mahmoud Gamal                                    *
* Version      	: 	1.0.0                                            *
* Date  		: 	28/09/2023                                       *
* Description   : 			         				                 *
*********************************************************************/

#include "MCAL/mfdi/MFDI_interface.h"

#include "SERVICE/SPARSE_interface.h"

u16 G_u16DataBuffer[100];
u32 G_u32Address= FLASH_START_ADDRESS;

u8 PARSE_u8AsciToHex(u8 Copy_u8Asci)
{
	u8 L_u8HexValue;
	if ( (Copy_u8Asci >= '0') && (Copy_u8Asci <= '9') )
	{
		L_u8HexValue = Copy_u8Asci - '0';
	}

	else if ( (Copy_u8Asci >= 'A') && (Copy_u8Asci <= 'F') )

	{
		L_u8HexValue = Copy_u8Asci - 55;
	}

	return L_u8HexValue;
}


void PARSE_voidParseData(u8* Copy_u8BufferData)
{
	/*HEX RECORD EX:
	 * : 10(CC) 0000(Low Address) 00(Record Type) 00 (0) 00(1) 00(2) 00(3) 01(4) 20(5) C5(6) 02(7) 00(8) 08(9) CB(10) 02(11) 00(12) 08(13) CF(14) 02(15)   52(Checksum)
	 */
	/*For Character Count*/
	u8 L_u8CCHIGH,L_u8CCLOW,L_u8CC;
	/*For Low 4 Address Digits*/
	u8 L_u8Digit0,L_u8Digit1,L_u8Digit2,L_u8Digit3;

	/* Get Character Count */
	L_u8CCHIGH = PARSE_u8AsciToHex (Copy_u8BufferData[1]);
	L_u8CCLOW  = PARSE_u8AsciToHex (Copy_u8BufferData[2]);
	L_u8CC     = (L_u8CCHIGH<<4) | L_u8CCLOW ;

	/* Get Address */
	L_u8Digit0 = PARSE_u8AsciToHex (Copy_u8BufferData[3]);
	L_u8Digit1 = PARSE_u8AsciToHex (Copy_u8BufferData[4]);
	L_u8Digit2 = PARSE_u8AsciToHex (Copy_u8BufferData[5]);
	L_u8Digit3 = PARSE_u8AsciToHex (Copy_u8BufferData[6]);

	/* Clear Low Part of Address */
	G_u32Address = G_u32Address & 0xFFFF0000;
	G_u32Address |= (L_u8Digit0<<12) |(L_u8Digit1 << 8) | (L_u8Digit2 << 4) | (L_u8Digit3);

	/* Write Data After Convert it into Hex format in App Sector in Flash */
	for (u8 L_u8Iterator=0;L_u8Iterator<L_u8CC/2; L_u8Iterator++)
	{
		/*Receive  Half Word Data [4 Digits]*/
		L_u8Digit0 = PARSE_u8AsciToHex (Copy_u8BufferData[4*L_u8Iterator+9 ]);
		L_u8Digit1 = PARSE_u8AsciToHex (Copy_u8BufferData[4*L_u8Iterator+10]);
		L_u8Digit2 = PARSE_u8AsciToHex (Copy_u8BufferData[4*L_u8Iterator+11]);
		L_u8Digit3 = PARSE_u8AsciToHex (Copy_u8BufferData[4*L_u8Iterator+12]);
		/*because little_Endian, Where in arm data is stored Little_Endian ,MSB
		 * Explaination:
		 *  ByteOfData =  0x 03 1C { Local_u8Digit_0 = 0,       |     3    |                            |    1   |  Local_u8Digit_2 = 1
		 *                           Local_u8Digit_1 = 3,       |     0    |  ->{Little_Endian ,MSB}->  |    C   |  Local_u8Digit_3 = C
		 *                           Local_u8Digit_2 = 1,       |     C    |                            |    0   |  Local_u8Digit_0 = 0
		 *                           Local_u8Digit_3 = C,       |     1    |                            |    3   |  Local_u8Digit_1 = 3
		 *} This Data Represent As Big_Endian ,LSB Due To Intel.
		 * */
		G_u16DataBuffer[L_u8Iterator] = (L_u8Digit2<<12) | (L_u8Digit3 << 8) | (L_u8Digit0<<4) | (L_u8Digit1);
	}

	MFDI_voidFlashWrite(G_u32Address,G_u16DataBuffer,L_u8CC/2);
}


void PARSE_voidParseRecord(u8* Copy_u8BufferData)
{
	switch (Copy_u8BufferData[8])
	{
	case '0': PARSE_voidParseData(Copy_u8BufferData); break;
	case '4': /* Set high address part */  			break;
	case '1': /* End of file */					 	break;
	default :  										break;/* Corrupt Record*/
	}
}
