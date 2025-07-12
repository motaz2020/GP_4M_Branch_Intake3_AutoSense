/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : exti_prog.c                                  	     
// Date          : Sep 11, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "../../../Inc/MCAL/exti/exti_interface.h"

static void(*arrOfPtrOfExtiCallBack[22])(void);


EN_MEXTI_systemState_t MEXTI_enableEXTI (EN_MEXTI_lines_t copy_uddtLineNum)
{
	EN_MEXTI_systemState_t ret = MEXTI_NOK;

	if(copy_uddtLineNum >= MEXTI_LINE0 && copy_uddtLineNum <= MEXTI_LINE22)
	{
		SET_BIT(MEXTI_PERIPHERAL->MEXTI_IMR , copy_uddtLineNum);
		ret = MEXTI_OK;
	}
	else
	{
		ret = MEXTI_INVALID_PARAMTER;
	}

	return ret;
}

EN_MEXTI_systemState_t MEXTI_disableEXTI (EN_MEXTI_lines_t copy_uddtLineNum)
{
	EN_MEXTI_systemState_t ret = MEXTI_NOK;

	if(copy_uddtLineNum >= MEXTI_LINE0 && copy_uddtLineNum <= MEXTI_LINE22)
	{
		CLR_BIT(MEXTI_PERIPHERAL->MEXTI_IMR , copy_uddtLineNum);
		ret = MEXTI_OK;
	}
	else
	{
		ret = MEXTI_INVALID_PARAMTER;
	}

	return ret;
}

EN_MEXTI_systemState_t MEXTI_softwareInterrupt (EN_MEXTI_lines_t copy_uddtLineNum)
{
	EN_MEXTI_systemState_t ret = MEXTI_NOK;

	if(copy_uddtLineNum >= MEXTI_LINE0 && copy_uddtLineNum <= MEXTI_LINE22)
	{
		SET_BIT(MEXTI_PERIPHERAL->MEXTI_SWIER , copy_uddtLineNum);
		ret = MEXTI_OK;
	}
	else
	{
		ret = MEXTI_INVALID_PARAMTER;
	}

	return ret;
}

EN_MEXTI_systemState_t MEXTI_setTriggerSource (EN_MEXTI_lines_t copy_uddtLineNum , EN_MEXTI_triggerOptions_t copy_uddtTriggerOption)
{
	EN_MEXTI_systemState_t ret = MEXTI_NOK;

	if((copy_uddtLineNum >= MEXTI_LINE0 && copy_uddtLineNum <= MEXTI_LINE22)
	   && (copy_uddtTriggerOption >= MEXTI_RISING_EDGE && copy_uddtTriggerOption <= MEXTI_ON_CHANGE))
	{
		switch(copy_uddtTriggerOption)
		{
			case MEXTI_RISING_EDGE :
			{
				SET_BIT(MEXTI_PERIPHERAL->MEXTI_RTSR , copy_uddtLineNum);
				ret = MEXTI_OK;
				break;
			}
			case MEXTI_FALLING_EDGE :
			{
				SET_BIT(MEXTI_PERIPHERAL->MEXTI_FTSR , copy_uddtLineNum);
				ret = MEXTI_OK;
				break;
			}
			case MEXTI_ON_CHANGE :
			{
				SET_BIT(MEXTI_PERIPHERAL->MEXTI_RTSR , copy_uddtLineNum);
				SET_BIT(MEXTI_PERIPHERAL->MEXTI_FTSR , copy_uddtLineNum);
				ret = MEXTI_OK;
				break;
			}
			default :
			{
				ret = MEXTI_INVALID_PARAMTER;
				break;
			}
		}
	}
	else
	{
		ret = MEXTI_INVALID_PARAMTER;
	}

	return ret;
}

EN_MEXTI_systemState_t MEXTI_setExtiConfig (EN_MEXTI_lines_t copy_uddtLineNum , EN_MEXTI_port_t copy_uddtPortNum)
{
	EN_MEXTI_systemState_t ret = MEXTI_NOK;

	if((copy_uddtLineNum >= MEXTI_LINE0 && copy_uddtLineNum <= MEXTI_LINE22)
	   && (copy_uddtPortNum >= MEXTI_PORTA && copy_uddtPortNum <= MEXTI_PORTH))
	{

		  switch(copy_uddtLineNum)
		  {
		  case (MEXTI_LINE0) :  MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK1   ;  //0xFFFFFFF0
		  	  	  	  	  	  	MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 |= copy_uddtPortNum ;
		                         break ;
		  case (MEXTI_LINE1) :  MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK2   ;  //0xFFFFFF0F
		  	  	  	  	  	  	MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 |= copy_uddtPortNum<<4 ;
		                         break ;
		  case (MEXTI_LINE2) :  MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK3   ;  //0xFFFFF0FF
		  	  	  	  	  	  	MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 |= copy_uddtPortNum<<8 ;
		                         break ;
		  case (MEXTI_LINE3) :  MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 &= EXTI_CONFG_MASK4   ;  //0xFFFF0FFF
		  	  	  	  	  	  	MSYSCFG_PERIPHERAL->MSYSCFG_EXTICR1 |= copy_uddtPortNum<<12 ;
		                         break ;
		  default : /*Do Nothing*/ break ;
		  }
	}
	else
	{
		ret = MEXTI_INVALID_PARAMTER;
	}

	return ret;
}

EN_MEXTI_systemState_t MEXTI_setCallBack (void(*ptr)(void) , EN_MEXTI_lines_t copy_uddtLineNum)
{
	EN_MEXTI_systemState_t ret = MEXTI_NOK;

	if((copy_uddtLineNum >= MEXTI_LINE0 && copy_uddtLineNum <= MEXTI_LINE22)
			&& (PTR_NULL != ptr))
	{
		arrOfPtrOfExtiCallBack[copy_uddtLineNum] = ptr;
		ret = MEXTI_OK;
	}
	else
	{
		ret = MEXTI_INVALID_PARAMTER;
	}
	return ret;
}


void EXTI0_IRQHandler(void)
{
	if(PTR_NULL != arrOfPtrOfExtiCallBack[0])
	{
		arrOfPtrOfExtiCallBack[0]();
		SET_BIT(MEXTI_PERIPHERAL->MEXTI_PR,0);
	}
	else
	{
		/* Do Nothing */
	}

}

void EXTI4_IRQHandler(void)
{
	if(PTR_NULL != arrOfPtrOfExtiCallBack[4])
	{
		arrOfPtrOfExtiCallBack[4]();
		SET_BIT(MEXTI_PERIPHERAL->MEXTI_PR,4);
	}
	else
	{
		/* Do Nothing */
	}

}


void EXTI5_IRQHandler(void)
{
	if(PTR_NULL != arrOfPtrOfExtiCallBack[5])
	{
		arrOfPtrOfExtiCallBack[5]();
		SET_BIT(MEXTI_PERIPHERAL->MEXTI_PR,5);
	}
	else
	{
		/* Do Nothing */
	}

}
