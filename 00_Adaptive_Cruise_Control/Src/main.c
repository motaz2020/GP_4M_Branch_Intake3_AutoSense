/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : main.c                                  	     
// Date          : Oct 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/


#include "../Inc/APPLICATION/Body_Control_Module/bcm_interface.h"


/**
 * @fn void main(void)
 * @brief : Entry point of the system
 *
 * @param  : void
 * @return : void
 */



void main(void)
{
	ABCM_vSysInit();
	ABCM_vSysMangment();
}

