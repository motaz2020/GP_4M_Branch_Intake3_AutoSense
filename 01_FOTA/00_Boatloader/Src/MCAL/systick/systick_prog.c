/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : systick_prog.c                                  	     
// Date          : Sep 12, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/systick/systick_interface.h"

static void(*pfForStkCallBack)(void) = PTR_NULL;
static uint8_t g_u8intervalMode;

EN_MSTK_systemState_t	MSTK_init(EN_MSTK_clkSourceOptions_t copy_uddtClkSource , EN_MSTK_interruptStates_t copy_uddtIntStates)
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	if((copy_uddtClkSource >= MSTK_CLK_AHB_8 && copy_uddtClkSource <= MSTK_CLK_PROCESSOR_AHB )
	   &&(copy_uddtIntStates >= MSTK_INTERRUPT_ENABLED && copy_uddtIntStates >= MSTK_INTERRUPT_DISABLED ))
	{
		if(copy_uddtClkSource == MSTK_CLK_AHB_8)
		{
			CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_CLKSOURCE_BIT);
			ret = MSTK_OK;
		}
		else if(copy_uddtClkSource == MSTK_CLK_PROCESSOR_AHB)
		{
			SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_CLKSOURCE_BIT);
			ret = MSTK_OK;
		}
		else
		{
			ret = MSTK_INVALID_PARAMTER;
		}

		if(ret == MSTK_OK)
		{
			if(copy_uddtIntStates == MSTK_INTERRUPT_DISABLED)
			{
				CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_TICKINT_BIT);
				ret = MSTK_OK;
			}
			else if(copy_uddtIntStates == MSTK_INTERRUPT_ENABLED)
			{
				SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_TICKINT_BIT);
				ret = MSTK_OK;
			}
			else
			{
				ret = MSTK_INVALID_PARAMTER;
			}
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		ret = MSTK_INVALID_PARAMTER;
	}
	return ret;
}

EN_MSTK_systemState_t	MSTK_setBusyWait(uint32_t copy_u32NumberOfTicks)
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	if(copy_u32NumberOfTicks >= MIN_VAL_OF_U32 && copy_u32NumberOfTicks <= MAX_VAL_OF_U32)
	{
		MSTK_PERIPHERAL->MSTK_STK_LOAD = copy_u32NumberOfTicks;
		SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_ENABLE_BIT);

		while(GET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_COUNTFLAG_BIT) == 0);
		//CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_ENABLE_BIT);
		MSTK_PERIPHERAL->MSTK_STK_LOAD = 0;
		MSTK_PERIPHERAL->MSTK_STK_VAL = 0;
		ret = MSTK_OK;
	}
	else
	{
		ret = MSTK_INVALID_PARAMTER;
	}
	return ret;
}

EN_MSTK_systemState_t	MSTK_SetIntervalSingle(uint32_t copy_u32NumberOfTicks, void (*Pf)(void))
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	if((copy_u32NumberOfTicks >= MIN_VAL_OF_U32 && copy_u32NumberOfTicks <= MAX_VAL_OF_U32) && (PTR_NULL != Pf))
	{
		MSTK_PERIPHERAL->MSTK_STK_VAL = 0;
		MSTK_PERIPHERAL->MSTK_STK_LOAD = copy_u32NumberOfTicks;
		pfForStkCallBack = Pf;
		g_u8intervalMode = MSTK_IntervalSingle;
		CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_CLKSOURCE_BIT);
		SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_ENABLE_BIT);
		SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_TICKINT_BIT);

		ret = MSTK_OK;
	}
	else
	{
		ret = MSTK_INVALID_PARAMTER;
	}
	return ret;
}

EN_MSTK_systemState_t	MSTK_SetIntervalPeriodic(uint32_t copy_u32NumberOfTicks, void (*Pf)(void))
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	if((copy_u32NumberOfTicks >= MIN_VAL_OF_U32 && copy_u32NumberOfTicks <= MAX_VAL_OF_U32) && (PTR_NULL != Pf))
	{
		MSTK_PERIPHERAL->MSTK_STK_LOAD = copy_u32NumberOfTicks;
		pfForStkCallBack = Pf;
		g_u8intervalMode = MSTK_IntervalPeriodic;
		SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_ENABLE_BIT);
		SET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_TICKINT_BIT);

		ret = MSTK_OK;
	}
	else
	{
		ret = MSTK_INVALID_PARAMTER;
	}
	return ret;
}

EN_MSTK_systemState_t	MSTK_StopInterval(void)
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_ENABLE_BIT);
	CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_TICKINT_BIT);

	ret = MSTK_OK;

	return ret;
}

EN_MSTK_systemState_t	MSTK_getElapsedTime(uint32_t *copy_u32PtrRetOfElapsedTicks)
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	if(PTR_NULL != copy_u32PtrRetOfElapsedTicks)
	{
		 *copy_u32PtrRetOfElapsedTicks = MSTK_PERIPHERAL->MSTK_STK_LOAD - MSTK_PERIPHERAL->MSTK_STK_VAL;
		 ret = MSTK_OK;
	}
	else
	{
		ret = MSTK_INVALID_PARAMTER;
	}
	return ret;
}

EN_MSTK_systemState_t	MSTK_getRemainingTime(uint32_t *copy_u32PtrRetOfRemainingTicks)
{
	EN_MSTK_systemState_t ret = MSTK_NOK;

	if(PTR_NULL != copy_u32PtrRetOfRemainingTicks)
	{
		 *copy_u32PtrRetOfRemainingTicks = MSTK_PERIPHERAL->MSTK_STK_VAL;
		 ret = MSTK_OK;
	}
	else
	{
		ret = MSTK_INVALID_PARAMTER;
	}
	return ret;
}


void SysTick_Handler(void)
{
	if(PTR_NULL != pfForStkCallBack)
	{
		uint8_t u8TempForFlagReading = 0;
		if(g_u8intervalMode == MSTK_IntervalSingle)
		{
			u8TempForFlagReading = GET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_COUNTFLAG_BIT);
			pfForStkCallBack();
			CLR_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_ENABLE_BIT);
			MSTK_PERIPHERAL->MSTK_STK_LOAD = 0;
			MSTK_PERIPHERAL->MSTK_STK_VAL = 0;
		}
		else if(g_u8intervalMode == MSTK_IntervalPeriodic)
		{
			u8TempForFlagReading = GET_BIT(MSTK_PERIPHERAL->MSTK_STK_CTRL , MSTK_COUNTFLAG_BIT);
			pfForStkCallBack();
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}
}



