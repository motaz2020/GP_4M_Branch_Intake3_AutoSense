/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : hc05_prog.c                                  	     
// Date          : Oct 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/HAL/hc05/hc05_interface.h"


EN_HHC05_systeamState_t  HHC05_uddtInit(ST_MUART_RegistersMap_t *PS_USARTx , ST_MUSART_cfg_t const *PS_uddtUartCfg)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtInit(PS_USARTx,PS_uddtUartCfg);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtEnable(ST_MUART_RegistersMap_t *PS_USARTx)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtEnable(PS_USARTx);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtDisable(ST_MUART_RegistersMap_t *PS_USARTx)
{
	EN_HHC05_systeamState_t ret = HHC05_uddtDisable(PS_USARTx);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtTransmitByte(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t copy_u8ByteToSend)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtTransmitByte(PS_USARTx,copy_u8ByteToSend);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtTransmitString(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8StringToSend)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtTransmitString(PS_USARTx,copy_u8StringToSend);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtReadDataRegister(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{

	EN_HHC05_systeamState_t ret = MUSART_uddtReadDataRegister(PS_USARTx,copy_u8ByteToReceive);
	return ret;

}

EN_HHC05_systeamState_t  HHC05_uddtReceiveByteSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtReceiveByteSynchNonBlocking(PS_USARTx,copy_u8ByteToReceive);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtReceiveStringSynchNonBlocking(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtReceiveStringSynchNonBlocking(PS_USARTx,copy_u8ByteToReceive);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtReceiveStringAsynchBlocking(ST_MUART_RegistersMap_t *PS_USARTx , uint8_t *copy_u8ByteToReceive)
{
	EN_HHC05_systeamState_t ret = MUSART_uddtReceiveStringAsynchBlocking(PS_USARTx,copy_u8ByteToReceive);
	return ret;
}


EN_HHC05_systeamState_t  HHC05_RxIntSetStatus(ST_MUART_RegistersMap_t *PS_USARTx, uint8_t copy_u8Status)
{
	EN_HHC05_systeamState_t ret = MUSART_RxIntSetStatus(PS_USARTx,copy_u8Status);
	return ret;
}

EN_HHC05_systeamState_t  HHC05_uddtSetCallBackUart1( void (*ptr) (void) )
{
	EN_HHC05_systeamState_t ret = MUSART1_uddtSetCallBack(ptr);
	return ret;
}
EN_HHC05_systeamState_t  HHC05_uddtSetCallBackUart2( void (*ptr) (void) )
{
	EN_HHC05_systeamState_t ret = MUSART2_uddtSetCallBack(ptr);
	return ret;
}
EN_HHC05_systeamState_t  HHC05_uddtSetCallBackUart6( void (*ptr) (void) )
{
	EN_HHC05_systeamState_t ret = MUSART6_uddtSetCallBack(ptr);
	return ret;
}





