/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : rcc_private.h                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_


#define	 RCC_PERIPHERAL_BASE_ADDR		(0x40023800)


typedef struct
{
	vuint32_t RCC_CR_REG;
	vuint32_t RCC_PLLCFGR_REG;
	vuint32_t RCC_CFGR_REG;
	vuint32_t RCC_CIR_REG;
	vuint32_t RCC_AHB1RSTR_REG;
	vuint32_t RCC_AHB2RSTR_REG;
	vuint32_t RESERVED0_REG;
	vuint32_t RESERVED1_REG;
	vuint32_t RCC_APB1RSTR_REG;
	vuint32_t RCC_APB2RSTR_REG;
	vuint32_t RESERVED2_REG;
	vuint32_t RESERVED3_REG;
	vuint32_t RCC_AHB1ENR_REG;
	vuint32_t RCC_AHB2ENR_REG;
	vuint32_t Reserved5_REG;
	vuint32_t Reserved6_REG;
	vuint32_t RCC_APB1ENR_REG;
	vuint32_t RCC_APB2ENR_REG;
	vuint32_t RESERVED7_REG;
	vuint32_t RESERVED8_REG;
	vuint32_t RCC_AHB1LPENR_REG;
	vuint32_t RCC_AHB2LPENR_REG;
	vuint32_t RESERVED9_REG;
	vuint32_t RESERVED10_REG;
	vuint32_t RCC_APB1LPENR_REG;
	vuint32_t RCC_APB2LPENR_REG;
	vuint32_t RESERVED11_REG;
	vuint32_t RESERVED12_REG;
	vuint32_t RCC_BDCR_REG;
	vuint32_t RCC_CSR_REG;
	vuint32_t RESERVED13_REG;
	vuint32_t RESERVED14_REG;
	vuint32_t RCC_SSCGR_REG;
	vuint32_t RCC_PLLI2SCFGR_REG;
	vuint32_t RESERVED15_REG;
	vuint32_t RCC_DCKCFGR_REG;
}ST_MRCC_RegistersMap_t;

#define MRCC_PERIPHERAL ((volatile ST_MRCC_RegistersMap_t *)RCC_PERIPHERAL_BASE_ADDR)

/* RCC_CR_REG Bits */

#define	HSION_BIT			0
#define	HSIRDY_BIT			1
#define	HSEON_BIT			16
#define	HSERDY_BIT			17
#define	HSEBYP_BIT			18
#define	CSSON_BIT			19
#define	PLLON_BIT			24
#define	PLLRDY_BIT			25
#define PLLI2SON_BIT		26
#define	PLLI2SRDY_BIT		27

/* RCC_PLLCFGR_REG Bits */

#define PLLM0_BIT	0
#define PLLM1_BIT	1
#define PLLM2_BIT	2
#define PLLM3_BIT	3
#define PLLM4_BIT	4
#define PLLM5_BIT	5
#define PLLN0_BIT	6
#define PLLP0_BIT	16
#define PLLSRC_BIT	22

/* RCC_CFGR_REG Bits */

#define SW0_BIT		0
#define SW1_BIT		1
#define SWS0_BIT	2
#define SWS1_BIT	3
#define HPRE0_BIT	4
#define PPRE10_BIT	10
#define PPRE20_BIT	13


#define __HAL_RCC_APB1_FORCE_RESET()     (MRCC_PERIPHERAL->RCC_APB1RSTR_REG = 0xFFFFFFFFU)
#define __HAL_RCC_APB1_RELEASE_RESET()   (MRCC_PERIPHERAL->RCC_APB1RSTR_REG = 0x00U)
#define __HAL_RCC_APB2_FORCE_RESET()     (MRCC_PERIPHERAL->RCC_APB2RSTR_REG = 0xFFFFFFFFU)
#define __HAL_RCC_APB2_RELEASE_RESET()   (MRCC_PERIPHERAL->RCC_APB2RSTR_REG = 0x00U)
#define __HAL_RCC_AHB1_FORCE_RESET()     (MRCC_PERIPHERAL->RCC_AHB1RSTR_REG = 0xFFFFFFFFU)
#define __HAL_RCC_AHB1_RELEASE_RESET()   (MRCC_PERIPHERAL->RCC_AHB1RSTR_REG = 0x00U)
#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
