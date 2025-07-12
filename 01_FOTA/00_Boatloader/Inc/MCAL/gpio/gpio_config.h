/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : gpio_config.h                                  	     
// Date          : Sep 10, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_GPIO_GPIO_CONFIG_H_
#define MCAL_GPIO_GPIO_CONFIG_H_


#define MIN_VAL_OF_U16				0
#define MAX_VAL_OF_U16				65536

typedef enum
{
	MGPIO_NOK = 0,
	MGPIO_OK,
	MGPIO_INVALID_PARAMTER,
	MGPIO_PTR_NULL
}EN_MGPIO_systemState_t;


typedef enum
{
	MGPIO_PIN0 = 0,
	MGPIO_PIN1,
	MGPIO_PIN2,
	MGPIO_PIN3,
	MGPIO_PIN4,
	MGPIO_PIN5,
	MGPIO_PIN6,
	MGPIO_PIN7,
	MGPIO_PIN8,
	MGPIO_PIN9,
	MGPIO_PIN10,
	MGPIO_PIN11,
	MGPIO_PIN12,
	MGPIO_PIN13,
	MGPIO_PIN14,
	MGPIO_PIN15,

}EN_MGPIO_pinOptions_t;


typedef enum
{
	MGPIO_MODE_INPUT = 0,
	MGPIO_MODE_OUTPUT,
	MGPIO_MODE_ALTF,
	MGPIO_MODE_ANALOG

}EN_MGPIO_pinModeOptions_t;


typedef enum
{
	MGPIO_LOGIC_LOW = 0,
	MGPIO_LOGIC_HIGH
}EN_MGPIO_pinLogicOptions_t;


typedef enum
{
	MGPIO_OUTPUT_SPEED_LOW = 0,
	MGPIO_OUTPUT_SPEED_MEDIUM,
	MGPIO_OUTPUT_SPEED_HIGH,
	MGPIO_OUTPUT_SPEED_VERY_HIGH
}EN_MGPIO_outputSpeedOptions_t;

typedef enum
{
	MGPIO_OUTPUT_RESISTOR_PUSH_PULL = 0,
	MGPIO_OUTPUT_RESISTOR_OPEN_DRAIN
}EN_MGPIO_outputResistorOptions_t;


typedef enum
{
	MGPIO_PULL_FLOATING = 0,
	MGPIO_PULL_PULL_UP,
	MGPIO_PULL_PULL_DOWN
}EN_MGPIO_pushPullOptions_t;


typedef enum
{
	 MGPIO_ALTFN_0 = 0,
	 MGPIO_ALTFN_1 ,
	 MGPIO_ALTFN_2 ,
	 MGPIO_ALTFN_3 ,
	 MGPIO_ALTFN_4 ,
	 MGPIO_ALTFN_5 ,
	 MGPIO_ALTFN_6 ,
	 MGPIO_ALTFN_7 ,
	 MGPIO_ALTFN_8 ,
	 MGPIO_ALTFN_9 ,
	 MGPIO_ALTFN_10,
	 MGPIO_ALTFN_11,
	 MGPIO_ALTFN_12,
	 MGPIO_ALTFN_13,
	 MGPIO_ALTFN_14,
	 MGPIO_ALTFN_15
}EN_MGPIO_altfnOptions_t;


typedef enum
{
	MGPIO_PIN_RESET = 0,
	MGPIO_PIN_SET
}EN_MGPIO_setResetOptions_t;


typedef struct
{
	ST_MGPIOx_RegistersMap_t  *PS_GPIOx;
	EN_MGPIO_pinOptions_t copy_uddtPinNum;
	EN_MGPIO_pinModeOptions_t copy_uddtPinMode;
	EN_MGPIO_outputResistorOptions_t copy_uddtOutputResistor;
	EN_MGPIO_outputSpeedOptions_t copy_uddtOutputSpeed;
	EN_MGPIO_pinLogicOptions_t copy_uddtPtrRetOfPinLogic;
	EN_MGPIO_pushPullOptions_t copy_uddtPullState;
}ST_MGPIO_pinCfg_t;

typedef struct
{
	ST_MGPIOx_RegistersMap_t  *PS_GPIOx;
	EN_MGPIO_pinOptions_t copy_uddtPinNum;
	EN_MGPIO_altfnOptions_t Copy_uddtAltFun;
	EN_MGPIO_outputResistorOptions_t copy_uddtOutputResistor;
	EN_MGPIO_outputSpeedOptions_t copy_uddtOutputSpeed;
	EN_MGPIO_pushPullOptions_t copy_uddtPullState;
}ST_MGPIO_altPinCfg_t;

#endif /* MCAL_GPIO_GPIO_CONFIG_H_ */
