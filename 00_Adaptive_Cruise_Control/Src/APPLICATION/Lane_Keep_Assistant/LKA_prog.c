/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : LKA_prog.c                                  	     
// Date          : Nov 7, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "../../../Inc/APPLICATION/Lane_Keep_Assistant/LKA_interface.h"


EN_ALKA_systeamState_t ALKA_uddtGetLanePosition(ST_HIR_cfg_t *PS_uddtRightIr,ST_HIR_cfg_t *PS_uddtLeftIr)
{
	EN_ALKA_systeamState_t ret = ALKA_PTR_NULL;

	if( (PTR_NULL != PS_uddtRightIr) && (PTR_NULL != PS_uddtLeftIr))
	{
		EN_HIR_surfaceState_t lo_uddtRightIrStates;
		EN_HIR_surfaceState_t lo_uddtLeftIrStates;

		HIR_uddtReadData(PS_uddtRightIr, &lo_uddtRightIrStates);
		HIR_uddtReadData(PS_uddtLeftIr, &lo_uddtLeftIrStates);

		if((lo_uddtRightIrStates == HIR_ON_WHITE) && (lo_uddtLeftIrStates ==  HIR_ON_WHITE ))
		{
			ret = ALKA_IN_LANE;
		}
		else if((lo_uddtRightIrStates == HIR_ON_BLACK) && (lo_uddtLeftIrStates == HIR_ON_WHITE ))
		{
			ret = ALKA_OUT_RIGHT_LANE;
		}
		else if((lo_uddtRightIrStates == HIR_ON_WHITE) && (lo_uddtLeftIrStates == HIR_ON_BLACK))
		{
			ret = ALKA_OUT_LEFT_LANE;
		}
		else if((lo_uddtRightIrStates == HIR_ON_BLACK) && (lo_uddtLeftIrStates ==  HIR_ON_BLACK ))
		{
			ret = ALKA_OUT_BOTH_LANE;
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		ret = ALKA_PTR_NULL;
	}
	return ret;
}


EN_ALKA_systeamState_t ALKA_uddtSetCarInLanes(ST_HIR_cfg_t *PS_uddtRightIr,ST_HIR_cfg_t *PS_uddtLeftIr , ST_DCM_cfg_t *PS_uddtRightDcm , ST_DCM_cfg_t *PS_uddtLeftDcm)
{
	EN_ALKA_systeamState_t ret = ALKA_PTR_NULL;

	if((PTR_NULL != PS_uddtRightDcm) && (PTR_NULL != PS_uddtLeftDcm))
	{
			ret = ALKA_uddtGetLanePosition(PS_uddtRightIr , PS_uddtLeftIr);

			if(ret == ALKA_IN_LANE)
			{
				HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_CLOCKWISE);
				HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_CLOCKWISE);
				HDCM_turnOn(PS_uddtRightDcm);
				HDCM_turnOn(PS_uddtLeftDcm);
			}
			else if(ret == ALKA_OUT_RIGHT_LANE)
			{
				HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_ANTI_CLOCKWISE);
				HDCM_turnOn(PS_uddtRightDcm);
				HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_CLOCKWISE);
				HDCM_turnOn(PS_uddtLeftDcm);
			}
			else if(ret == ALKA_OUT_LEFT_LANE)
			{
				HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_ANTI_CLOCKWISE);
				HDCM_turnOn(PS_uddtLeftDcm);
				HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_CLOCKWISE);
				HDCM_turnOn(PS_uddtRightDcm);
			}
			else if(ret == ALKA_OUT_BOTH_LANE)
			{
				HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_CLOCKWISE);
				HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_CLOCKWISE);
				HDCM_turnOn(PS_uddtRightDcm);
				HDCM_turnOn(PS_uddtLeftDcm);
			}
			else
			{
				/* Do Nothing */
			}
		ret = ALKA_POS_SET;
	}
	else
	{
		ret = ALKA_PTR_NULL;
	}
	return ret;
}

EN_ALKA_systeamState_t ALKA_left(ST_HIR_cfg_t *PS_uddtRightIr,ST_HIR_cfg_t *PS_uddtLeftIr , ST_DCM_cfg_t *PS_uddtRightDcm , ST_DCM_cfg_t *PS_uddtLeftDcm)
{
	EN_ALKA_systeamState_t ret = ALKA_PTR_NULL;

	if((PTR_NULL != PS_uddtRightDcm) && (PTR_NULL != PS_uddtLeftDcm))
	{

			HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_ANTI_CLOCKWISE);
			HDCM_turnOn(PS_uddtRightDcm);
			HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_CLOCKWISE);
			HDCM_turnOn(PS_uddtLeftDcm);

		ret = ALKA_POS_SET;
	}
	else
	{
		ret = ALKA_PTR_NULL;
	}
	return ret;
}

EN_ALKA_systeamState_t ALKA_right(ST_HIR_cfg_t *PS_uddtRightIr,ST_HIR_cfg_t *PS_uddtLeftIr , ST_DCM_cfg_t *PS_uddtRightDcm , ST_DCM_cfg_t *PS_uddtLeftDcm)
{
	EN_ALKA_systeamState_t ret = ALKA_PTR_NULL;

	if((PTR_NULL != PS_uddtRightDcm) && (PTR_NULL != PS_uddtLeftDcm))
	{

			HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_ANTI_CLOCKWISE);
			HDCM_turnOn(PS_uddtLeftDcm);
			HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_CLOCKWISE);
			HDCM_turnOn(PS_uddtRightDcm);

		ret = ALKA_POS_SET;
	}
	else
	{
		ret = ALKA_PTR_NULL;
	}
	return ret;
}

EN_ALKA_systeamState_t ALKA_forward(ST_HIR_cfg_t *PS_uddtRightIr,ST_HIR_cfg_t *PS_uddtLeftIr , ST_DCM_cfg_t *PS_uddtRightDcm , ST_DCM_cfg_t *PS_uddtLeftDcm)
{
	EN_ALKA_systeamState_t ret = ALKA_PTR_NULL;

	if((PTR_NULL != PS_uddtRightDcm) && (PTR_NULL != PS_uddtLeftDcm))
	{

			HDCM_changeDirection(PS_uddtLeftDcm ,DCM_DIR_CLOCKWISE);
			HDCM_turnOn(PS_uddtLeftDcm);
			HDCM_changeDirection(PS_uddtRightDcm ,DCM_DIR_CLOCKWISE);
			HDCM_turnOn(PS_uddtRightDcm);

		ret = ALKA_POS_SET;
	}
	else
	{
		ret = ALKA_PTR_NULL;
	}
	return ret;
}
