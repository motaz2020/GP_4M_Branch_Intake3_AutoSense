/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : ncc_prog.c                                  	     
// Date          : Oct 18, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/APPLICATION/Normal_Cruise_Control/ncc_interface.h"

static uint8_t gl_u8NccSpeedLimit = 0;

void ANCC_vStartNcc(ST_DCM_cfg_t *leftdcm,ST_DCM_cfg_t *rightdcm, uint8_t copy_u8Speed)
{
	gl_u8NccSpeedLimit = copy_u8Speed; /* set gl_u8NccSpeedLimit with the default speed limit of car */
	HDCM_controlSpeed(copy_u8Speed); /* set the speed of NCC taken from driver */
	HDCM_turnOn(leftdcm); /* turn dc motor on to start moving the car */
	HDCM_turnOn(rightdcm);
	HHC05_uddtTransmitString(MUART1_PERIPHERAL,(uint8_t *)"Ncc Is Working Now \r\n");
}

void ANCC_vStopNcc(ST_DCM_cfg_t *leftdcm,ST_DCM_cfg_t *rightdcm)
{
	MTMR_vStopTimer(MTMR2);
	//HDCM_controlSpeed(STOP_SPEED); /* set the speed of NCC to stop speed to turn off pwm*/
	HDCM_turnOff(leftdcm); /* turn off dc motors to stop car */
	HDCM_turnOff(rightdcm);
}

uint8_t ANCC_vChangeNccSpeedLimit(uint8_t copy_u8SpeedAction)
{
	switch(copy_u8SpeedAction)
	{
		case '+' :
		{
			gl_u8NccSpeedLimit+=10;
			HDCM_controlSpeed(gl_u8NccSpeedLimit);
			break;
		}
		case '-' :
		{
			gl_u8NccSpeedLimit-=10;
			HDCM_controlSpeed(gl_u8NccSpeedLimit);
			break;
		}
		default :
		{
			/*Do Nothing*/
			break;
		}
	}
	return gl_u8NccSpeedLimit;
}

