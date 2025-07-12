/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : aeb_prog.c                                  	     
// Date          : Oct 26, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/APPLICATION/Automatic_Emergency_Brake/aeb_interface.h"



void AAEB_vIsReady(void)
{
	/* transmit a massage for the driver with UART */
	HHC05_uddtTransmitString(MUART1_PERIPHERAL,(uint8_t *)"Automatic Emergency Brake Is Ready \r\n");
}

EN_AAEB_zones_t AAEB_uddtCheckForObstacles(ST_DCM_cfg_t *PS_uddtRightDcm , ST_DCM_cfg_t *PS_uddtLeftDcm , uint32_t copy_u32CurrentDistance)
{
	EN_AAEB_zones_t ret = AAEB_SAFE_ZONE;
	if( (PS_uddtRightDcm != PTR_NULL) && (PS_uddtLeftDcm != PTR_NULL))
	{
		if(copy_u32CurrentDistance <= DANGEROUS_ZONE)
		{
			MTMR_vStopTimer(MTMR2);
			//HDCM_controlSpeed(STOP_SPEED); /* Stop PWM*/
			HDCM_turnOff(PS_uddtRightDcm); /* turn off dc_motors to stop car */
			HDCM_turnOff(PS_uddtLeftDcm);
			ret = AAEB_DANGEROUS_ZONE;
		}
		else
		{
			ret = AAEB_SAFE_ZONE;
		}
	}
	else
	{
		/* do nothing */
	}
	return ret;
}
