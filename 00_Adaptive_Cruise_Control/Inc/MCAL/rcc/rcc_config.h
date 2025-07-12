/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC_Drivers                                    	 
// File          : rcc_config.h                                  	     
// Date          : Sep 8, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_

#define sysClkSelect  				MRCC_SYS_CLK_HSI
#define pllStatus					MRCC_PLL_DISABLE
#define pllSourceOfEntryClk			MRCC_PLL_ENTRY_CLK_HSI
#define pllpDivisionFactor			MRCC_PLL_DIVISION_FACTOR_2
#define pllmDivisionFactor			0
#define pllnMulFactor				0
#define apbHighSpeedPrescaler		MRCC_APB_PRESCALER_SPEED_NOT_DIVIDED
#define apbLowSpeedPrescaler		MRCC_APB_PRESCALER_SPEED_NOT_DIVIDED
#define ahbPrescaler				MRCC_AHB_PRESCALER_2

typedef enum
{
    MRCC_OK = 0,                 /**< Operation successful. */
    MRCC_NOK,                    /**< Operation failed. */
    MRCC_PTR_NULL,               /**< Null pointer encountered. */
    MRCC_INVALID_PARAMTER        /**< Invalid parameter detected. */
} EN_MRCC_systemState_t;

/**
 * @brief Enumeration for the system clock selection.
 */
typedef enum
{
    MRCC_SYS_CLK_HSI = 0,                /**< HSI (High-Speed Internal) oscillator. */
    MRCC_SYS_CLK_HSE_BYPASS,             /**< HSE (High-Speed External) oscillator with bypass. */
    MRCC_SYS_CLK_HSE_NOT_BYPASS = 1,     /**< HSE oscillator without bypass. */
    MRCC_SYS_CLK_PLL,                    /**< PLL (Phase-Locked Loop). */
    MRCC_SYS_CLK_NOT_ALLOWED             /**< Not allowed system clock source. */
} EN_MRCC_sysClkSelect_t;

/**
 * @brief Enumeration for the PLL entry clock source.
 */
typedef enum
{
    MRCC_PLL_ENTRY_CLK_HSI = 0,          /**< PLL entry clock source: HSI. */
    MRCC_PLL_ENTRY_CLK_HSE              /**< PLL entry clock source: HSE. */
} EN_MRCC_pllClkSourceEntry_t;

/**
 * @brief Enumeration for the PLL division factor.
 */
typedef enum
{
    MRCC_PLL_DIVISION_FACTOR_2 = 0,      /**< PLL division factor: 2. */
    MRCC_PLL_DIVISION_FACTOR_4,          /**< PLL division factor: 4. */
    MRCC_PLL_DIVISION_FACTOR_6,          /**< PLL division factor: 6. */
    MRCC_PLL_DIVISION_FACTOR_8           /**< PLL division factor: 8. */
} EN_MRCC_pllDivisionFactor_t;

/**
 * @brief Enumeration for APB (Advanced Peripheral Bus) prescaler speed.
 */
typedef enum
{
    MRCC_APB_PRESCALER_SPEED_NOT_DIVIDED = 0, /**< APB prescaler speed: Not divided. */
    MRCC_APB_PRESCALER_SPEED_2 = 4,            /**< APB prescaler speed: 2. */
    MRCC_APB_PRESCALER_SPEED_4,                /**< APB prescaler speed: 4. */
    MRCC_APB_PRESCALER_SPEED_8,                /**< APB prescaler speed: 8. */
    MRCC_APB_PRESCALER_SPEED_16                /**< APB prescaler speed: 16. */
} EN_MRCC_apbPrescalerSpeed_t;

/**
 * @brief Enumeration for AHB (Advanced High-Performance Bus) prescaler.
 */
typedef enum
{
    MRCC_AHB_PRESCALER_NOT_DIVIDED = 0,  /**< AHB prescaler: Not divided. */
    MRCC_AHB_PRESCALER_2 = 8,             /**< AHB prescaler: 2. */
    MRCC_AHB_PRESCALER_4,                 /**< AHB prescaler: 4. */
    MRCC_AHB_PRESCALER_8,                 /**< AHB prescaler: 8. */
    MRCC_AHB_PRESCALER_16,                /**< AHB prescaler: 16. */
    MRCC_AHB_PRESCALER_64,                /**< AHB prescaler: 64. */
    MRCC_AHB_PRESCALER_128,               /**< AHB prescaler: 128. */
    MRCC_AHB_PRESCALER_256,               /**< AHB prescaler: 256. */
    MRCC_AHB_PRESCALER_512                /**< AHB prescaler: 512. */
} EN_MRCC_ahbPrescaler_t;

/**
 * @brief Enumeration for PLL status.
 */
typedef enum
{
    MRCC_PLL_DISABLE = 0,  /**< PLL is disabled. */
    MRCC_PLL_ENABLE        /**< PLL is enabled. */
} EN_MRCC_pllStatus_t;

/**
 * @brief Enumeration for different buses in MRCC.
 */
typedef enum
{
    MRCC_AHP1_BUS = 0,  /**< AHP1 bus. */
    MRCC_AHP2_BUS,      /**< AHP2 bus. */
    MRCC_APB1_BUS,      /**< APB1 bus. */
    MRCC_APB2_BUS       /**< APB2 bus. */
} EN_MRCC_busOptions_t;

/**
 * @brief Enumeration for different peripheral options in MRCC.
 */
typedef enum
{
	MRCC_GPIOA_PERIPHERAL = 0,
	MRCC_GPIOB_PERIPHERAL,
	MRCC_CRC_PERIPHERAL = 12,
	MRCC_DMA1_PERIPHERAL = 21,
	MRCC_DMA2_PERIPHERAL,
	MRCC_OTGFS_PERIPHERAL = 7,
	MRCC_TIM2_PERIPHERAL = 0,
	MRCC_TIM3_PERIPHERAL,
	MRCC_TIM4_PERIPHERAL,
	MRCC_TIM5_PERIPHERAL,
	MRCC_WWDG_PERIPHERAL = 11,
	MRCC_SPI2_PERIPHERAL = 14,
	MRCC_SPI3_PERIPHERAL = 15,
	MRCC_USART2_PERIPHERAL = 17,
	MRCC_I2C1_PERIPHERAL = 21,
	MRCC_I2C2_PERIPHERAL,
	MRCC_I2C3_PERIPHERAL,
	MRCC_PWR_PERIPHERAL = 28,
	MRCC_TIM1_PERIPHERAL = 0,
	MRCC_USART1_PERIPHERAL = 4,
	MRCC_USART6_PERIPHERAL,
	MRCC_ADC1_PERIPHERAL = 8,
	MRCC_SDIO_PERIPHERAL = 11,
	MRCC_SPI1_PERIPHERAL,
	MRCC_SPI4_PERIPHERAL,
	MRCC_SYSCFG_PERIPHERAL,
	MRCC_TIM9_PERIPHERAL = 16,
	MRCC_TIM10_PERIPHERAL,
	MRCC_TIM11_PERIPHERAL

}EN_MRCC_peripheralOptions_t;


#endif /* MCAL_RCC_RCC_CONFIG_H_ */
