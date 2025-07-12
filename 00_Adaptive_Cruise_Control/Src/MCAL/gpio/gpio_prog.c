/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : gpio_prog.c                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/gpio/gpio_interface.h"


EN_MGPIO_systemState_t MGPIO_uddtSetPinMode (ST_MGPIOx_RegistersMap_t  *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinModeOptions_t copy_uddtPinMode)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtPinMode >= MGPIO_MODE_OUTPUT && copy_uddtPinMode <= MGPIO_MODE_ANALOG))
	{
		PS_GPIOx->MGPIOx_MODER |= (uint32_t) (copy_uddtPinMode <<((2U) * copy_uddtPinNum));
		ret = MGPIO_OK;
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_uddtSetOutputMode (ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_outputResistorOptions_t copy_uddtOutputResistor)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtOutputResistor >= MGPIO_OUTPUT_RESISTOR_PUSH_PULL && copy_uddtOutputResistor <= MGPIO_OUTPUT_RESISTOR_OPEN_DRAIN))
	{
		PS_GPIOx->MGPIOx_OTYPER |= (uint32_t) (copy_uddtOutputResistor << copy_uddtPinNum);
		ret = MGPIO_OK;
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_uddtSetOutputSpeed  (ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_outputSpeedOptions_t copy_uddtOutputSpeed )
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtOutputSpeed >= MGPIO_OUTPUT_SPEED_LOW && copy_uddtOutputSpeed <= MGPIO_OUTPUT_SPEED_VERY_HIGH))
	{
		PS_GPIOx->MGPIOx_OSPEEDR |= (uint32_t) (copy_uddtOutputSpeed << ((2U) * copy_uddtPinNum));
		ret = MGPIO_OK;
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_uddtSetPullState  (ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pushPullOptions_t copy_uddtPullState )
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtPullState >= MGPIO_PULL_FLOATING && copy_uddtPullState <= MGPIO_PULL_PULL_DOWN))
	{
		PS_GPIOx->MGPIOx_PUPDR |= (uint32_t) (copy_uddtPullState << ((2U) * copy_uddtPinNum));
		ret = MGPIO_OK;
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_uddtGetPinVal  (ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinLogicOptions_t *copy_uddtPtrRetOfPinLogic)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (PTR_NULL != copy_uddtPtrRetOfPinLogic))
	{

		*copy_uddtPtrRetOfPinLogic = GET_BIT(PS_GPIOx->MGPIOx_IDR , copy_uddtPinNum);
		ret = MGPIO_OK;
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_uddtSetPinVal(ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_pinLogicOptions_t copy_uddtPinLogic)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtPinLogic >= MGPIO_LOGIC_LOW && copy_uddtPinLogic <= MGPIO_LOGIC_HIGH))
	{
		if(copy_uddtPinLogic == MGPIO_LOGIC_HIGH)
		{
			SET_BIT(PS_GPIOx->MGPIOx_ODR , copy_uddtPinNum);
			ret = MGPIO_OK;
		}
		else if(copy_uddtPinLogic == MGPIO_LOGIC_LOW)
		{
			CLR_BIT(PS_GPIOx->MGPIOx_ODR , copy_uddtPinNum);
			ret = MGPIO_OK;
		}
		else
		{
			ret = MGPIO_INVALID_PARAMTER;
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_uddtDirectSetReset (ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_setResetOptions_t copy_uddtSetResetState )
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&& (copy_uddtPinNum >= MGPIO_PIN0 && copy_uddtPinNum <= MGPIO_PIN15)
		&& (copy_uddtSetResetState >= MGPIO_PIN_RESET && copy_uddtSetResetState <= MGPIO_PIN_SET))
	{
		if(copy_uddtSetResetState == MGPIO_PIN_SET)
		{
			SET_BIT(PS_GPIOx->MGPIOx_BSRR , copy_uddtPinNum);
			ret = MGPIO_OK;
		}
		else if(copy_uddtSetResetState == MGPIO_PIN_RESET)
		{
			copy_uddtPinNum += 16;
			CLR_BIT(PS_GPIOx->MGPIOx_BSRR , copy_uddtPinNum);
			ret = MGPIO_OK;
		}
		else
		{
			ret = MGPIO_INVALID_PARAMTER;
		}
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_uddtSetPortVal(ST_MGPIOx_RegistersMap_t *PS_GPIOx , uint16_t copy_u16OutputVal)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if((PS_GPIOx != PTR_NULL)
		&&(copy_u16OutputVal >= MIN_VAL_OF_U16 && copy_u16OutputVal <= MAX_VAL_OF_U16))
	{
		PS_GPIOx->MGPIOx_ODR = (uint32_t) copy_u16OutputVal;
		ret = MGPIO_OK;
	}
	else
	{
		ret = MGPIO_INVALID_PARAMTER;
	}
	return ret;
}

EN_MGPIO_systemState_t MGPIO_uddtSetAltFun (ST_MGPIOx_RegistersMap_t *PS_GPIOx , EN_MGPIO_pinOptions_t copy_uddtPinNum , EN_MGPIO_altfnOptions_t Copy_uddtAltFun)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;
	if (copy_uddtPinNum <= 7U )
	{
		PS_GPIOx->MGPIOx_AFRL  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum));
		ret= MGPIO_OK;
	}
	else  if (copy_uddtPinNum <= 15U )
	{
		PS_GPIOx->MGPIOx_AFRH  |= (Copy_uddtAltFun << 4U * (copy_uddtPinNum));
		ret= MGPIO_OK;
	}
	else
	{
		ret= MGPIO_PTR_NULL;
	}
	return ret;
}



EN_MGPIO_systemState_t MGPIO_uddtInitPin		(ST_MGPIO_pinCfg_t *PS_pinInstance)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;
	if(PS_pinInstance != PTR_NULL)
	{
		ret = MGPIO_uddtSetPinMode(PS_pinInstance->PS_GPIOx,PS_pinInstance->copy_uddtPinNum,PS_pinInstance->copy_uddtPinMode);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetOutputMode(PS_pinInstance->PS_GPIOx,PS_pinInstance->copy_uddtPinNum,PS_pinInstance->copy_uddtOutputResistor);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetOutputSpeed(PS_pinInstance->PS_GPIOx,PS_pinInstance->copy_uddtPinNum,PS_pinInstance->copy_uddtOutputSpeed);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetPullState(PS_pinInstance->PS_GPIOx,PS_pinInstance->copy_uddtPinNum,PS_pinInstance->copy_uddtPullState);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetPinVal(PS_pinInstance->PS_GPIOx,PS_pinInstance->copy_uddtPinNum,PS_pinInstance->copy_uddtPtrRetOfPinLogic);
	}
	else
	{
		ret = MGPIO_PTR_NULL;
	}
	return ret;
}


EN_MGPIO_systemState_t MGPIO_uddtInitAltPin		(ST_MGPIO_altPinCfg_t *PS_altPinInstance)
{
	EN_MGPIO_systemState_t ret = MGPIO_NOK;

	if(PS_altPinInstance != PTR_NULL)
	{
		ret = MGPIO_uddtSetPinMode(PS_altPinInstance->PS_GPIOx,PS_altPinInstance->copy_uddtPinNum,MGPIO_MODE_ALTF);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetOutputMode(PS_altPinInstance->PS_GPIOx,PS_altPinInstance->copy_uddtPinNum,PS_altPinInstance->copy_uddtOutputResistor);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetOutputSpeed(PS_altPinInstance->PS_GPIOx,PS_altPinInstance->copy_uddtPinNum,PS_altPinInstance->copy_uddtOutputSpeed);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetAltFun(PS_altPinInstance->PS_GPIOx,PS_altPinInstance->copy_uddtPinNum,PS_altPinInstance->Copy_uddtAltFun);
		if(ret == MGPIO_OK)
		ret = MGPIO_uddtSetPullState(PS_altPinInstance->PS_GPIOx,PS_altPinInstance->copy_uddtPinNum,PS_altPinInstance->copy_uddtPullState);

	}
	else
	{
		ret = MGPIO_PTR_NULL;
	}
	return ret;
}










