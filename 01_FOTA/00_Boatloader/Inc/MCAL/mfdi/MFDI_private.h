/*********************************************************************
* File Name    	: 	MFDI_private.h                                   *
* Author       	: 	Mahmoud Gamal                                    *
* Version      	: 	1.0.0                                            *
* Date  		: 	28/09/2023                                       *
* Description   : 			         				                 *
*********************************************************************/
#ifndef MFDI_PRIVATE_H_
#define MFDI_PRIVATE_H_

#define	FDI_BASE_ADDRESS		(0x40023C00)

typedef struct
{

	u32	ACR;
	u32	KEYR;
	u32	OPTKEYR;
	u32	SR;
	u32	CR;
	u32	OPTCR;

}FDI_t;

#define MFDI ((volatile FDI_t *)FDI_BASE_ADDRESS)

/* FLASH_CR Pins Difinitions */
#define CR_LOCK            31
#define CR_ERRIE           25
#define CR_EOPIE           24
#define CR_STRT            16
#define CR_PSIZE           8
#define CR_SNB             3
#define CR_MER             2
#define CR_SER             1
#define CR_PG              0

#define SR_EOP             0
#define SR_BSY             16


#define OPTKEY1	 (0x45670123)
#define OPTKEY2	 (0xCDEF89AB)


#define HALF_WORD  		1
#define ONE_WORD   		2
#define DOUBLE_WORD 	4


#endif /* MCAL_FDI_FDI_PRIVATE_H_ */
