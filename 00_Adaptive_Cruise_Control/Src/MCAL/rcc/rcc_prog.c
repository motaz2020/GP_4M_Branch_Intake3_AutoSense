/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : rcc_prog.c                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/rcc/rcc_interface.h"


EN_MRCC_systemState_t MRCC_Init(void)
{
	EN_MRCC_systemState_t ret = MRCC_NOK;

		MRCC_PERIPHERAL->RCC_CFGR_REG = ((MRCC_PERIPHERAL->RCC_CFGR_REG & 0xFFFFFFFC ) | (sysClkSelect << SW0_BIT));

		if(sysClkSelect == MRCC_SYS_CLK_HSI )
		{
			SET_BIT(MRCC_PERIPHERAL->RCC_CR_REG , HSION_BIT );
			ret = MRCC_OK;
		}
		else if(sysClkSelect == MRCC_SYS_CLK_HSE_NOT_BYPASS)
		{
			SET_BIT(MRCC_PERIPHERAL->RCC_CR_REG , HSEON_BIT );
			CLR_BIT(MRCC_PERIPHERAL->RCC_CR_REG , HSEBYP_BIT);
			ret = MRCC_OK;
		}
		else if(sysClkSelect == MRCC_SYS_CLK_HSE_BYPASS)
		{
			SET_BIT(MRCC_PERIPHERAL->RCC_CR_REG , HSEON_BIT );
			SET_BIT(MRCC_PERIPHERAL->RCC_CR_REG , HSEBYP_BIT);
			ret = MRCC_OK;
		}
		else if(sysClkSelect == MRCC_SYS_CLK_PLL)
		{
			if( (pllmDivisionFactor >= 0 && pllmDivisionFactor <= 63 )
					&&(pllnMulFactor >= 0 && pllnMulFactor <= 511 ))
			{

				MRCC_PERIPHERAL->RCC_PLLCFGR_REG = ((MRCC_PERIPHERAL->RCC_PLLCFGR_REG & 0xFFDE4000 )
				|(pllmDivisionFactor << PLLM0_BIT)
				|(pllnMulFactor << PLLN0_BIT)
				|(pllpDivisionFactor << PLLP0_BIT)
				|(pllSourceOfEntryClk << PLLSRC_BIT));


				SET_BIT(MRCC_PERIPHERAL->RCC_CR_REG , PLLON_BIT);

				ret = MRCC_OK;
			}
			else
			{
				ret = MRCC_INVALID_PARAMTER;
			}
		}
		else
		{
			ret = MRCC_INVALID_PARAMTER;
		}
		MRCC_PERIPHERAL->RCC_CFGR_REG = ((MRCC_PERIPHERAL->RCC_CFGR_REG & 0xFFFF030F )
						|(ahbPrescaler << HPRE0_BIT)
						|(apbLowSpeedPrescaler << PPRE10_BIT)
						|(apbHighSpeedPrescaler << PPRE20_BIT));
	return ret;
}


EN_MRCC_systemState_t MRCC_enablePeripheral(EN_MRCC_busOptions_t busSelection,EN_MRCC_peripheralOptions_t PeripheralNumber)
{
	EN_MRCC_systemState_t ret = MRCC_NOK;
	if((busSelection >=0 && busSelection <=4 ) && (PeripheralNumber >=0 && PeripheralNumber <= 31))
	{
		switch(busSelection)
		{
			case MRCC_AHP1_BUS :
			{
				SET_BIT(MRCC_PERIPHERAL->RCC_AHB1ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			case MRCC_AHP2_BUS :
			{
				SET_BIT(MRCC_PERIPHERAL->RCC_AHB2ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			case MRCC_APB1_BUS :
			{
				SET_BIT(MRCC_PERIPHERAL->RCC_APB1ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			case MRCC_APB2_BUS :
			{
				SET_BIT(MRCC_PERIPHERAL->RCC_APB2ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			default :
			{
				ret = MRCC_INVALID_PARAMTER;
			}
		}
	}
	else
	{
		ret = MRCC_INVALID_PARAMTER;
	}
	return ret;
}
EN_MRCC_systemState_t MRCC_disablePeripheral(EN_MRCC_busOptions_t busSelection,EN_MRCC_peripheralOptions_t PeripheralNumber)
{
	EN_MRCC_systemState_t ret = MRCC_NOK;
	if((busSelection >=0 && busSelection <=4 ) && (PeripheralNumber >=0 && PeripheralNumber <= 31))
	{
		switch(busSelection)
		{
			case MRCC_AHP1_BUS :
			{
				CLR_BIT(MRCC_PERIPHERAL->RCC_AHB1ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			case MRCC_AHP2_BUS :
			{
				CLR_BIT(MRCC_PERIPHERAL->RCC_AHB2ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			case MRCC_APB1_BUS :
			{
				CLR_BIT(MRCC_PERIPHERAL->RCC_APB1ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			case MRCC_APB2_BUS :
			{
				CLR_BIT(MRCC_PERIPHERAL->RCC_APB2ENR_REG , PeripheralNumber);
				ret = MRCC_OK;
				break;
			}
			default :
			{
				ret = MRCC_INVALID_PARAMTER;
			}
		}
	}
	else
	{
		ret = MRCC_INVALID_PARAMTER;
	}
	return ret;
}


void HAL_DeInit(void)
{
  /* Reset of all peripherals */
  __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();

  __HAL_RCC_AHB1_FORCE_RESET();
  __HAL_RCC_AHB1_RELEASE_RESET();

}
