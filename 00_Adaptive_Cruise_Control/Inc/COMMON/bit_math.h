/*************************************************************************/
// Author        : Sherif Ashraf Khadr
// Project       : STM32F401xC_Drivers
// File          : main.c
// Date          : Sep 8, 2023
// GitHub        : https://github.com/sherifkhadr
/*************************************************************************/

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define SET_BIT(REG, BIT_NUMBER) (REG |= (1 << BIT_NUMBER))
#define GET_BIT(REG, BIT_NUMBER) ((REG >> BIT_NUMBER) & 1)
#define CLR_BIT(REG, BIT_NUMBER) (REG &= (~(1 << BIT_NUMBER)))
#define TOG_BIT(REG, BIT_NUMBER) (REG ^= (1 << BIT_NUMBER))


 #define SET_BITS(REG,MSK)			(REG) |=  (MSK)
 #define CLR_BITS(REG,MSK)			(REG) &= ~(MSK)
 #define TOG_BITS(REG,MSK)			(REG) ^=  (MSK)

 #define SET_ALL_BITS(REG)			(REG) =  (0xFFFFFFFF)
 #define CLR_ALL_BITS(REG)			(REG) =  (0x00000000)
 #define TOG_ALL_BITS(REG)			(REG) ^= (0xFFFFFFFF)

#endif /* COMMON_BIT_MATH_H_ */
