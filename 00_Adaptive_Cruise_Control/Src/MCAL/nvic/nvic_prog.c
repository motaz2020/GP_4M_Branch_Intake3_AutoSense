/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : nvic_prog.c                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/nvic/nvic_interface.h"



EN_MNVIC_systemState_t MNVIC_enableInterrupt(uint8_t copy_u8IntPos)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if(copy_u8IntPos >= POS_OF_FIRST_INT && copy_u8IntPos <= POS_OF_LAST_INT)
	{
		SET_BIT(MNVIC_PERIPHERAL->MNVIC_ISERx[getIntRegNumber(copy_u8IntPos)] ,getIntBitNumber(copy_u8IntPos));
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}

EN_MNVIC_systemState_t MNVIC_disableInterrupt(uint8_t copy_u8IntPos)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if(copy_u8IntPos >= POS_OF_FIRST_INT && copy_u8IntPos <= POS_OF_LAST_INT)
	{
		SET_BIT(MNVIC_PERIPHERAL->MNVIC_ICERx[getIntRegNumber(copy_u8IntPos)] ,getIntBitNumber(copy_u8IntPos));
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}

EN_MNVIC_systemState_t MNVIC_enableInterruptPending(uint8_t copy_u8IntPos)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if(copy_u8IntPos >= POS_OF_FIRST_INT && copy_u8IntPos <= POS_OF_LAST_INT)
	{
		SET_BIT(MNVIC_PERIPHERAL->MNVIC_ISPRx[getIntRegNumber(copy_u8IntPos)] ,getIntBitNumber(copy_u8IntPos));
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}

EN_MNVIC_systemState_t MNVIC_disableInterruptPending(uint8_t copy_u8IntPos)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if(copy_u8IntPos >= POS_OF_FIRST_INT && copy_u8IntPos <= POS_OF_LAST_INT)
	{
		SET_BIT(MNVIC_PERIPHERAL->MNVIC_ICPRx[getIntRegNumber(copy_u8IntPos)] ,getIntBitNumber(copy_u8IntPos));
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}

EN_MNVIC_systemState_t MNVIC_IsInterruptActive(uint8_t copy_u8IntPos , uint8_t *ptrOfRetReading)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if(copy_u8IntPos >= POS_OF_FIRST_INT && copy_u8IntPos <= POS_OF_LAST_INT)
	{
		*ptrOfRetReading = GET_BIT(MNVIC_PERIPHERAL->MNVIC_IABRx[getIntRegNumber(copy_u8IntPos)] ,getIntBitNumber(copy_u8IntPos));
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}

EN_MNVIC_systemState_t MNVIC_SetInterruptPriority (uint8_t copy_u8IntPos , EN_MNVIC_priorityGrouping_t copy_uddtGroupOption ,uint8_t copy_u8GroupPriority , uint8_t copy_u8SubPriority)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if((copy_u8IntPos >= POS_OF_FIRST_INT && copy_u8IntPos <= POS_OF_LAST_INT)
		&&(copy_uddtGroupOption >= GP_16_SP_00 && copy_uddtGroupOption <= GP_00_SP_16 ))
	{
		uint8_t Local_u8Priority = 0;

		  switch(copy_uddtGroupOption)
		  {
		  case GP_00_SP_16 :  Local_u8Priority = copy_u8SubPriority								   ;  break ;
		  case GP_16_SP_00 :  Local_u8Priority = copy_u8GroupPriority   						   ;  break ;
		  case GP_04_SP_04 :  Local_u8Priority = (copy_u8GroupPriority<<2) | copy_u8SubPriority    ;  break ;
		  case GP_02_SP_08 :  Local_u8Priority = (copy_u8GroupPriority<<3) | copy_u8SubPriority    ;  break ;
		  case GP_08_SP_02 :  Local_u8Priority = (copy_u8GroupPriority<<1) | copy_u8SubPriority    ;  break ;
		  }


		  MNVIC_PERIPHERAL->MNVIC_IPRx[copy_u8IntPos] = (Local_u8Priority<<4) ;

//		uint8_t Local_u8Priority =  copy_u8SubPriority | (copy_u8GroupPriority << (copy_uddtGroupOption-3) ) ;
//		MNVIC_PERIPHERAL -> MNVIC_IPRx[copy_u8IntPos/32] = (Local_u8Priority << 4 );
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}

EN_MNVIC_systemState_t MNVIC_SetInterruptGroup(EN_MNVIC_priorityGrouping_t copy_uddtGroupOption)
{
	EN_MNVIC_systemState_t ret = MNVIC_NOK;
	if(copy_uddtGroupOption >= GP_16_SP_00 && copy_uddtGroupOption <= GP_00_SP_16 )
	{
		SCB_AIRCR = MNVIC_VECTKEY;
		SCB_AIRCR = MNVIC_VECTKEY|(copy_uddtGroupOption<<8);
		ret = MNVIC_OK;
	}
	else
	{
		ret = MNVIC_INVALID_PARAMTER;
	}

	return ret;
}
