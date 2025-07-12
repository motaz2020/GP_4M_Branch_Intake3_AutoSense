/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : usart_prog.c                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/usart/usart_interface.h"

static void (*MUSART1_CallBack)(void) = PTR_NULL;
static void (*MUSART2_CallBack)(void) = PTR_NULL;
static void (*MUSART6_CallBack)(void) = PTR_NULL;

EN_MUSART_systeamState_t MUSART_uddtInit(ST_MUART_RegistersMap_t *PS_USARTx , ST_MUSART_cfg_t const *PS_uddtUartCfg)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;
	if(PS_uddtUartCfg != PTR_NULL && PS_USARTx != PTR_NULL)
	{
		switch (PS_uddtUartCfg->copy_uddtSamplingModeOption)
		{
			case MUSART_SAMPLING_BY_16 : PS_USARTx->MUSART_BRR = UART_BRR_SAMPLING16(__PCLK__,PS_uddtUartCfg->copy_uddtBuadRateOption); break;
			case MUSART_SAMPLING_BY_8  : PS_USARTx->MUSART_BRR = UART_BRR_SAMPLING8(__PCLK__,PS_uddtUartCfg->copy_uddtBuadRateOption); break;
		}

		PS_USARTx->MUSART_CR1 =  (PS_uddtUartCfg->copy_uddtSamplingModeOption << MUSART_CR1_OVER8_BIT)  |
					      	  	 (PS_uddtUartCfg->copy_HardwareFlowControl<<MUSART_CR1_UE_BIT)          |
								 (PS_uddtUartCfg->copy_uddtDataSizeOption <<MUSART_CR1_M_BIT)           |
								 (PS_uddtUartCfg->copy_uddtParityControl <<MUSART_CR1_PCE_BIT)     		|
								 (PS_uddtUartCfg->copy_uddtParitySelection <<MUSART_CR1_PS_BIT)    		;

		switch (PS_uddtUartCfg->copy_uddtTransferDirection)
		{
			case MUSART_TX_ONLY:   SET_BIT(PS_USARTx->MUSART_CR1, MUSART_CR1_TE_BIT); break;
			case MUSART_RX_ONLY:   SET_BIT(PS_USARTx->MUSART_CR1, MUSART_CR1_RE_BIT); break;
			case MUSART_TX_RX  :   SET_BIT(PS_USARTx->MUSART_CR1, MUSART_CR1_TE_BIT);
						  	  	   SET_BIT(PS_USARTx->MUSART_CR1, MUSART_CR1_RE_BIT); break;
		}
		PS_USARTx->MUSART_CR2 = (PS_uddtUartCfg->copy_uddtStopBitSelection<<MUSART_CR2_STOP_BIT)				  |
								(PS_uddtUartCfg->copy_uddtUartClockInit.clockOutput <<MUSART_CR2_CLKEN_BIT)       |
								(PS_uddtUartCfg->copy_uddtUartClockInit.clockPhase <<MUSART_CR2_CPHA_BIT)         |
								(PS_uddtUartCfg->copy_uddtUartClockInit.clockPolarity <<MUSART_CR2_CPOL_BIT)      |
								(PS_uddtUartCfg->copy_uddtUartClockInit.lastBitClockPulse <<MUSART_CR2_LBCL_BIT)  ;

		PS_USARTx->MUSART_SR = 0																                  ;

		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}



EN_MUSART_systeamState_t MUSART_uddtEnable(ST_MUART_RegistersMap_t *PS_USARTx)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL)
	{
		SET_BIT(PS_USARTx->MUSART_CR1,MUSART_CR1_UE_BIT);
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtDisable(ST_MUART_RegistersMap_t *PS_USARTx)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL)
	{
		CLR_BIT(PS_USARTx->MUSART_CR1,MUSART_CR1_UE_BIT);
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtTransmitByte(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t copy_u8ByteToSend)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL)
	{
		while (GET_BIT(PS_USARTx->MUSART_SR,MUSART_SR_TXE_BIT)==0);
		PS_USARTx->MUSART_DR = copy_u8ByteToSend;
		while (GET_BIT(PS_USARTx->MUSART_SR,MUSART_SR_TC_BIT)==0);
		CLR_BIT(PS_USARTx->MUSART_SR,MUSART_SR_TC_BIT);
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtTransmitString(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8StringToSend)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL && copy_u8StringToSend != PTR_NULL)
	{
		uint32_t loc_u32Iterator = 0;
		while (copy_u8StringToSend[loc_u32Iterator] != STR_NULL)
		{
			MUSART_uddtTransmitByte(PS_USARTx, copy_u8StringToSend[loc_u32Iterator]);
			loc_u32Iterator++;
		}
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtReadDataRegister(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL && copy_u8ByteToReceive!= PTR_NULL)
	{
		while(GET_BIT(PS_USARTx->MUSART_SR , MUSART_SR_RXNE_BIT) == 0);
		*copy_u8ByteToReceive = PS_USARTx->MUSART_DR;
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtClearFlags(ST_MUART_RegistersMap_t *PS_USARTx)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL)
	{
		PS_USARTx-> MUSART_SR=0;
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART_uddtReceiveByteSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;
	uint32_t loc_u32TimeOut = 0;

	if(PS_USARTx != PTR_NULL && copy_u8ByteToReceive != PTR_NULL)
	{
		while ((GET_BIT(PS_USARTx->MUSART_SR,MUSART_SR_RXNE_BIT)==0) && (loc_u32TimeOut < THRESHOLD_VALUE) )
		{
			loc_u32TimeOut++;
		}
		if (loc_u32TimeOut == THRESHOLD_VALUE)
		{
			*copy_u8ByteToReceive = 255;
		}
		else
		{
			*copy_u8ByteToReceive = PS_USARTx->MUSART_DR;
		}
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}
	return ret;
}

EN_MUSART_systeamState_t  MUSART_uddtReceiveStringAsynchBlocking (ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL && copy_u8ByteToReceive != PTR_NULL)
	{
		uint8_t loc_Iterator = 0 , loc_u8DataCome ;
		MUSART_uddtReadDataRegister(PS_USARTx , &loc_u8DataCome);
		while(loc_u8DataCome != 13)
		{
			copy_u8ByteToReceive[ loc_Iterator ] = loc_u8DataCome ;
			loc_Iterator++;
			MUSART_uddtReadDataRegister(PS_USARTx , &loc_u8DataCome);
		}

		copy_u8ByteToReceive[loc_Iterator] = '\0';
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}
	return ret;
}

EN_MUSART_systeamState_t  MUSART_uddtReceiveStringSynchNonBlocking (ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL && copy_u8ByteToReceive != PTR_NULL)
	{
		uint8_t loc_Iterator = 0 , loc_u8DataCome ;
		MUSART_uddtReceiveByteSynchNonBlocking(PS_USARTx , &loc_u8DataCome);
		while(loc_u8DataCome != 13)
		{
			if(loc_u8DataCome == 255) break;
			copy_u8ByteToReceive[ loc_Iterator ] = loc_u8DataCome ;
			loc_Iterator++;
			MUSART_uddtReceiveByteSynchNonBlocking(PS_USARTx , &loc_u8DataCome);
		}

		copy_u8ByteToReceive[loc_Iterator] = '\0';
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}
	return ret;
}


EN_MUSART_systeamState_t MUSART_RxIntSetStatus(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8Status)
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(PS_USARTx != PTR_NULL)
	{
		switch (copy_u8Status)
		{
			case MUSART_ENABLE:  SET_BIT(PS_USARTx->MUSART_CR1 ,(MUSART_CR1_RXNEIE_BIT)); break;
			case MUSART_DISABLE: CLR_BIT(PS_USARTx->MUSART_CR1 ,(MUSART_CR1_RXNEIE_BIT)); break;
		}
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}



EN_MUSART_systeamState_t MUSART1_uddtSetCallBack( void (*ptr) (void) )
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(ptr != PTR_NULL)
	{
		MUSART1_CallBack = ptr ;
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}

EN_MUSART_systeamState_t MUSART2_uddtSetCallBack( void (*ptr) (void) )
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(ptr != PTR_NULL)
	{
		MUSART2_CallBack = ptr ;
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;}

EN_MUSART_systeamState_t MUSART6_uddtSetCallBack( void (*ptr) (void) )
{
	EN_MUSART_systeamState_t ret = MUSART_NOK;

	if(ptr != PTR_NULL)
	{
		MUSART6_CallBack = ptr ;
		ret = MUSART_OK;
	}
	else
	{
		ret = MUSART_PTR_NULL;
	}

	return ret;
}


void USART1_IRQHandler(void)
{
	MUART1_PERIPHERAL -> MUSART_SR = 0 ;
	MUSART1_CallBack();
}

void USART2_IRQHandler(void)
{
	MUART2_PERIPHERAL -> MUSART_SR = 0 ;
	MUSART2_CallBack();
}

void USART6_IRQHandler(void)
{
	MUART6_PERIPHERAL -> MUSART_SR = 0 ;
	MUSART6_CallBack();
}






