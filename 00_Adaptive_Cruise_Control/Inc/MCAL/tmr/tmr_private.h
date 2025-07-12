/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : Adaptive_Cruise_Control                                    	 
// File          : tmr_private.h                                  	     
// Date          : Oct 14, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_TMR_TMR_PRIVATE_H_
#define MCAL_TMR_TMR_PRIVATE_H_


#define	 MTMR2_PERIPHERAL_BASE_ADDR		(0x40000000)
#define	 MTMR3_PERIPHERAL_BASE_ADDR		(0x40000400)
#define	 MTMR4_PERIPHERAL_BASE_ADDR		(0x40000800)
#define	 MTMR5_PERIPHERAL_BASE_ADDR		(0x40000C00)



typedef struct
{

	vuint32_t	MTMRx_CR1;
	vuint32_t	MTMRx_CR2;
	vuint32_t	MTMRx_SMCR;
	vuint32_t	MTMRx_DIER;
	vuint32_t	MTMRx_SR;
	vuint32_t	MTMRx_EGR;
	vuint32_t	MTMRx_CCMR1;
	vuint32_t	MTMRx_CCMR2;
	vuint32_t	MTMRx_CCER;
	vuint32_t	MTMRx_CNT;
	vuint32_t	MTMRx_PSC;
	vuint32_t	MTMRx_ARR;
	vuint32_t	MTMRx_RESERVED_1;
	vuint32_t	MTMRx_CCR1;
	vuint32_t	MTMRx_CCR2;
	vuint32_t	MTMRx_CCR3;
	vuint32_t	MTMRx_CCR4;
	vuint32_t	MTMRx_RESERVED_2;
	vuint32_t	MTMRx_DCR;
	vuint32_t	MTMRx_DMAR;
	vuint32_t	MTMRx_OR;

}ST_MTMRx_RegistersMap_t;


#define CEN_BIT			    0
#define OPM_BIT			    3
#define CC1S_SHIFT		    0
#define OC1M_SHIFT		    4
#define CC2S_SHIFT		    8
#define OC2M_SHIFT		    12
#define CC3S_SHIFT		    0
#define OC3M_SHIFT		    4
#define CC4S_SHIFT		    8
#define OC4M_SHIFT		    12
#define CC1IE_BIT		    1
#define CC1P_BIT			1
#define CC1NP_BIT			3
#define CC3P_BIT			9
#define CC3NP_BIT			11
#define CC3EN_BIT			8
#define CC1EN_BIT		    0



#define MTMR2_PERIPHERAL ((volatile ST_MTMRx_RegistersMap_t *)MTMR2_PERIPHERAL_BASE_ADDR)
#define MTMR3_PERIPHERAL ((volatile ST_MTMRx_RegistersMap_t *)MTMR3_PERIPHERAL_BASE_ADDR)
#define MTMR4_PERIPHERAL ((volatile ST_MTMRx_RegistersMap_t *)MTMR4_PERIPHERAL_BASE_ADDR)
#define MTMR5_PERIPHERAL ((volatile ST_MTMRx_RegistersMap_t *)MTMR5_PERIPHERAL_BASE_ADDR)




#endif /* MCAL_TMR_TMR_PRIVATE_H_ */
