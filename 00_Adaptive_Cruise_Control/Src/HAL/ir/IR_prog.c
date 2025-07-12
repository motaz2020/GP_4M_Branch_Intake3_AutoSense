/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : IR_prog.c                                  	     
// Date          : Nov 7, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/ir/IR_interface.h"

EN_HIR_systemState_t HIR_uddtInit(ST_HIR_cfg_t *PS_uddtIrInstance)
{
	EN_HIR_systemState_t ret = HIR_NOK;

	if(PTR_NULL != PS_uddtIrInstance)
	{
		ST_MGPIO_pinCfg_t lo_uddtIrPin = {PS_uddtIrInstance->HIR_port,PS_uddtIrInstance->HIR_pin,MGPIO_MODE_INPUT,
				MGPIO_OUTPUT_RESISTOR_PUSH_PULL , MGPIO_OUTPUT_SPEED_HIGH ,MGPIO_LOGIC_LOW ,
				MGPIO_PULL_FLOATING};
		MGPIO_uddtInitPin(&lo_uddtIrPin);
		ret = HIR_OK;
	}
	else
	{
		ret = HIR_PTR_NULL;
	}

	return ret;
}

EN_HIR_systemState_t HIR_uddtReadData(ST_HIR_cfg_t *PS_uddtIrInstance , EN_HIR_surfaceState_t *copy_uddtRetOfIrRead)
{
	EN_HIR_systemState_t ret = HIR_NOK;

	EN_MGPIO_pinLogicOptions_t lo_uddtPinLogic = MGPIO_LOGIC_LOW;

	if( (PTR_NULL != PS_uddtIrInstance) && (PTR_NULL != copy_uddtRetOfIrRead))
	{
		MGPIO_uddtGetPinVal(PS_uddtIrInstance->HIR_port,PS_uddtIrInstance->HIR_pin,&lo_uddtPinLogic);
		if(lo_uddtPinLogic == MGPIO_LOGIC_HIGH)
		{
			*copy_uddtRetOfIrRead = HIR_ON_BLACK;
		}
		else if(lo_uddtPinLogic == MGPIO_LOGIC_LOW)
		{
			*copy_uddtRetOfIrRead = HIR_ON_WHITE;
		}
		else
		{
			/*Do Nothing */
		}
		ret = HIR_OK;
	}
	else
	{
		ret = HIR_PTR_NULL;
	}

	return ret;
}

