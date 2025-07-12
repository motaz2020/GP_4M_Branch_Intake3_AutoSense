/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : tmr_prog.c                                  	     
// Date          : Oct 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/

#include "../../../Inc/MCAL/tmr/tmr_interface.h"
#include "../../../Inc/MCAL/gpio/gpio_interface.h"

void 	 MTMR_vStartTimer(EN_MTMR_number_t copy_uddtTMRNumber)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		SET_BIT(MTMR2_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;
	case MTMR3:
		SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;
	case MTMR4:
		SET_BIT(MTMR4_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;
	case MTMR5:
		SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;

	default:                               break;
	}
}

void 	 MTMR_vStopTimer(EN_MTMR_number_t copy_uddtTMRNumber)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		CLR_BIT(MTMR2_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;
	case MTMR3:
		CLR_BIT(MTMR3_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;
	case MTMR4:
		CLR_BIT(MTMR4_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;
	case MTMR5:
		CLR_BIT(MTMR5_PERIPHERAL -> MTMRx_CR1, CEN_BIT); break;

	default:                               break;
	}
}


void 	 MTMR_vSetTimerPrescaler(EN_MTMR_number_t copy_uddtTMRNumber, uint16_t copy_u16Value)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		CLR_ALL_BITS(MTMR2_PERIPHERAL -> MTMRx_PSC);
		MTMR2_PERIPHERAL -> MTMRx_PSC |= copy_u16Value;
		break;
	case MTMR3:
		CLR_ALL_BITS(MTMR3_PERIPHERAL -> MTMRx_PSC);
		MTMR3_PERIPHERAL -> MTMRx_PSC |= copy_u16Value;
		break;
	case MTMR4:
		CLR_ALL_BITS(MTMR4_PERIPHERAL -> MTMRx_PSC);
		MTMR4_PERIPHERAL -> MTMRx_PSC |= copy_u16Value;
		break;
	case MTMR5:
		CLR_ALL_BITS(MTMR5_PERIPHERAL -> MTMRx_PSC);
		MTMR5_PERIPHERAL -> MTMRx_PSC |= copy_u16Value;
		break;
	default:                               break;
	}
}


void 	 MTMR_vEnableTimerOPM(EN_MTMR_number_t copy_uddtTMRNumber)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		SET_BIT(MTMR2_PERIPHERAL -> MTMRx_CR1, OPM_BIT); break;

	default:                               break;
	}
}



void 	 MTMR_vSetTimerChannelOutput(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_selectedMode_t copy_uddtTimerMode, EN_MTMR_channel_t copy_uddtChannelNumber)
{
	switch(copy_uddtTMRNumber)
	{
		case MTMR2:
			switch(copy_uddtChannelNumber)
			{
				case MTMR_CH1:
				{
					CLR_BITS(MTMR2_PERIPHERAL -> MTMRx_CCMR1, 0x00000073);
					MTMR2_PERIPHERAL -> MTMRx_CCMR1 |= (copy_uddtTimerMode << OC1M_SHIFT);
					SET_BIT(MTMR2_PERIPHERAL -> MTMRx_CCER, CC1EN_BIT);
					break;
				}
				case MTMR_CH2:	break;
				case MTMR_CH3:
				{
					CLR_BITS(MTMR2_PERIPHERAL -> MTMRx_CCMR2, 0x00000073);
					MTMR2_PERIPHERAL -> MTMRx_CCMR2 |= (copy_uddtTimerMode << OC1M_SHIFT);
					SET_BIT(MTMR2_PERIPHERAL -> MTMRx_CCER, 8);
					break;
				}
				case MTMR_CH4:	break;
			}
			break;
		case MTMR3 :
		{
			switch(copy_uddtChannelNumber)
			{
				case MTMR_CH1:
				{
					CLR_BITS(MTMR3_PERIPHERAL -> MTMRx_CCMR1, 0x00000073);
					MTMR3_PERIPHERAL -> MTMRx_CCMR1 |= (copy_uddtTimerMode << OC1M_SHIFT);
					SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER, CC1EN_BIT);
					break;
				}
				case MTMR_CH2: break;
				case MTMR_CH3: break;
				case MTMR_CH4: break;
			}
		}

		default:                               break;
	}
}

void 	 MTMR_vSetTimerCMPVal(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber, uint32_t copy_u32CmpValue)
{
	switch(copy_uddtTMRNumber)
	{
		case MTMR2:
		{
				switch(copy_uddtChannelNumber)
				{
				case MTMR_CH1:
					MTMR2_PERIPHERAL -> MTMRx_CCR1 = copy_u32CmpValue;
					break;
				case MTMR_CH2:
					MTMR2_PERIPHERAL -> MTMRx_CCR2 = copy_u32CmpValue;
					break;
				case MTMR_CH3:
					MTMR2_PERIPHERAL -> MTMRx_CCR3 = copy_u32CmpValue;
					break;
				case MTMR_CH4:
					MTMR2_PERIPHERAL -> MTMRx_CCR4 = copy_u32CmpValue;
					break;
				}
			break;
		}
		case MTMR3:
		{
				switch(copy_uddtChannelNumber)
				{
				case MTMR_CH1:
					MTMR3_PERIPHERAL -> MTMRx_CCR1 = copy_u32CmpValue;
					break;
				case MTMR_CH2:
					MTMR3_PERIPHERAL -> MTMRx_CCR2 = copy_u32CmpValue;
					break;
				case MTMR_CH3:
					MTMR3_PERIPHERAL -> MTMRx_CCR3 = copy_u32CmpValue;
					break;
				case MTMR_CH4:
					MTMR3_PERIPHERAL -> MTMRx_CCR4 = copy_u32CmpValue;
					break;
				}
			break;
		}

		default:                               break;
	}
}




void 	 MTMR_vSetTimerARR(EN_MTMR_number_t copy_uddtTMRNumber, uint32_t copy_u32Value)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		MTMR2_PERIPHERAL -> MTMRx_ARR = copy_u32Value;
		break;
	case MTMR3:
		MTMR3_PERIPHERAL -> MTMRx_ARR = copy_u32Value;
		break;
	case MTMR5:
		MTMR5_PERIPHERAL -> MTMRx_ARR = copy_u32Value;
		break;
	default:                               break;
	}
}


void 	 MTMR_vClearTimerCount(EN_MTMR_number_t copy_uddtTMRNumber)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		MTMR2_PERIPHERAL -> MTMRx_CNT = 0;
		break;
	case MTMR3:
		MTMR3_PERIPHERAL -> MTMRx_CNT = 0;
		break;
	case MTMR5:
		MTMR5_PERIPHERAL -> MTMRx_CNT = 0;
		break;
	default:                               break;
	}
}


void 	 MTMR_vEnableTimerICUInt(EN_MTMR_number_t copy_uddtTMRNumber)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:
		SET_BIT(MTMR2_PERIPHERAL->MTMRx_DIER , 1);
		break;
	case MTMR3:
		SET_BIT(MTMR3_PERIPHERAL->MTMRx_DIER , 1);
		break;
	case MTMR5:
		SET_BIT(MTMR5_PERIPHERAL->MTMRx_DIER , 1);
		break;
	default:                               break;
	}
}

void 	 MTMR_vSetTimerChannelInput(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber)
{
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:

		break;
	case MTMR3:
		switch(copy_uddtChannelNumber)
		{
		case MTMR_CH1:
			CLR_BITS(MTMR3_PERIPHERAL -> MTMRx_CCMR1, 0x00000003);
			SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1, CC1S_SHIFT);

			SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER, CC1P_BIT);
			SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER, CC1NP_BIT);

			SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER, CC1EN_BIT);
			break;
		case MTMR_CH2:
			break;
		case MTMR_CH3:
			break;
		case MTMR_CH4:
			break;
		}
		break;
		case MTMR4:
			break;
		case MTMR5:
			switch(copy_uddtChannelNumber)
			{
			case MTMR_CH1:
				CLR_BITS(MTMR5_PERIPHERAL -> MTMRx_CCMR1, 0x00000003);
				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCMR1, CC1S_SHIFT);

				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCER, CC1P_BIT);
				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCER, CC1NP_BIT);

				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCER, CC1EN_BIT);
				break;
			case MTMR_CH2:
				break;
			case MTMR_CH3:
				CLR_BITS(MTMR5_PERIPHERAL -> MTMRx_CCMR2, 0x00000003);
				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCMR2, CC1S_SHIFT);

				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCER, CC3P_BIT);
				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCER, CC3NP_BIT);

				SET_BIT(MTMR5_PERIPHERAL -> MTMRx_CCER, CC3EN_BIT);
				break;
			case MTMR_CH4:
				break;
			}
			break;
	}
}


uint32_t MTMR_vReadCaptureVal(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber)
{
	uint32_t lo_u32RetOfReading = 0;
	switch(copy_uddtTMRNumber)
	{
	case MTMR2:

		break;
	case MTMR3:
		switch(copy_uddtChannelNumber)
		{
		case MTMR_CH1:
			lo_u32RetOfReading = MTMR3_PERIPHERAL -> MTMRx_CCR1;
			break;
		case MTMR_CH2:
			lo_u32RetOfReading = MTMR3_PERIPHERAL -> MTMRx_CCR2;
			break;
		case MTMR_CH3:
			lo_u32RetOfReading = MTMR3_PERIPHERAL -> MTMRx_CCR3;
			break;
		case MTMR_CH4:
			lo_u32RetOfReading = MTMR3_PERIPHERAL -> MTMRx_CCR4;
			break;
		}
		break;
		case MTMR5:
			switch(copy_uddtChannelNumber)
			{
			case MTMR_CH1:
				lo_u32RetOfReading = MTMR5_PERIPHERAL -> MTMRx_CCR1;
				break;
			case MTMR_CH2:
				lo_u32RetOfReading = MTMR5_PERIPHERAL -> MTMRx_CCR2;
				break;
			case MTMR_CH3:
				lo_u32RetOfReading = MTMR5_PERIPHERAL -> MTMRx_CCR3;
				break;
			case MTMR_CH4:
				lo_u32RetOfReading = MTMR5_PERIPHERAL -> MTMRx_CCR4;
				break;
			}
			break;
			default:            break;
	}
	return lo_u32RetOfReading;
}

//void 	 MTMR3_vCaptureCompareInit(void)
//{
//	/*DIER Register*/
//
//	SET_BIT(MTMR3_PERIPHERAL -> MTMRx_DIER , 1);	// Capture/Compare interrupt enable
//
//	/*CCMR1 Register*/
//
//	SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1 , 0);	// configure timer3 ch1 as input
//	CLR_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1 , 1);
//
//	CLR_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1 , 2);	// configure timer3 ch1 to capture at every edge detected
//	CLR_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1 , 3);
//
//
//	CLR_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1 , 6);
//	CLR_BIT(MTMR3_PERIPHERAL -> MTMRx_CCMR1 , 7);
//
//	/*CCER Register*/
//
//	SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER , 0);	// Capture Enabled
//
//
//	SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER , 1);	// Capture/Compare channel captures on both edges (rising & falling)
//	SET_BIT(MTMR3_PERIPHERAL -> MTMRx_CCER , 3);
//
//	MTMR_vSetTimerPrescaler(MTMR3,72);
//
//	MTMR3_PERIPHERAL -> MTMRx_ARR = 65535;
//}













