/*************************************************************************/
// Author        : Sherif Ashraf Khadr									 
// Project       : STM32F401xC                                    	 
// File          : usart_config.h                                  	     
// Date          : Sep 19, 2023	                                                                                                 
// GitHub        : https://github.com/sherifkhadr             		     
/*************************************************************************/
#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

#define THRESHOLD_VALUE		50000
#define __PCLK__	        8000000UL

#define MUSART_ENABLE				1
#define MUSART_DISABLE				0

/**
 * @brief Enumeration for USART system states.
 */
typedef enum
{
    MUSART_NOK = 0,     /**< USART operation unsuccessful. */
    MUSART_OK,          /**< USART operation successful. */
    MUSART_PTR_NULL     /**< Null pointer encountered during the operation. */
} EN_MUSART_systeamState_t;

/**
 * @brief Enumeration for USART sampling mode options.
 */
typedef enum
{
    MUSART_SAMPLING_BY_16 = 0,  /**< USART sampling by 16. */
    MUSART_SAMPLING_BY_8        /**< USART sampling by 8. */
} EN_MUSART_samplingModeOptions_t;

/**
 * @brief Enumeration for USART baud rate options.
 */
typedef enum
{
	MUSART_BUAD_RATE_1200_bps = 1200,
	MUSART_BUAD_RATE_2400_bps = 2400,
	MUSART_BUAD_RATE_9600_bps = 9600,
	MUSART_BUAD_RATE_19200_bps = 19200,
	MUSART_BUAD_RATE_38400_bps = 38400,
	MUSART_BUAD_RATE_57600_bps = 57600,
	MUSART_BUAD_RATE_115200_bps = 115200,
	MUSART_BUAD_RATE_230400_bps = 230400,
	MUSART_BUAD_RATE_460800_bps = 460800,
	MUSART_BUAD_RATE_921600_bps = 921600,
	MUSART_BUAD_RATE_1792000_bps = 1792000,
	MUSART_BUAD_RATE_1843200_bps = 1843200,
	MUSART_BUAD_RATE_3584000_bps = 3584000,
	MUSART_BUAD_RATE_3686400_bps = 3686400,
	MUSART_BUAD_RATE_7168000_bps = 7168000,
	MUSART_BUAD_RATE_7372800_bps = 7372800,
	MUSART_BUAD_RATE_9000000_bps = 9000000,
	MUSART_BUAD_RATE_10500000_bps = 10500000,

}EN_MUSART_baudRateOptions_t;

/**
 * @brief Enumeration for USART transfer control options.
 */
typedef enum
{
    MUSART_TX_ONLY = 0,  /**< USART transmit only. */
    MUSART_RX_ONLY,      /**< USART receive only. */
    MUSART_TX_RX          /**< USART transmit and receive. */
} EN_MUSART_transferControl_t;

/**
 * @brief Enumeration for USART stop bit options.
 */
typedef enum
{
    MUSART_ONE_STOP_BIT = 0,         /**< USART one stop bit. */
    MUSART_HALF_STOP_BIT,            /**< USART half stop bit. */
    MUSART_TWO_STOP_BIT,             /**< USART two stop bits. */
    MUSART_ONE_AND_HALF_BIT          /**< USART one and a half stop bits. */
} EN_MUSART_stopBitOption_t;

/**
 * @brief Enumeration for USART parity control options.
 */
typedef enum
{
    MUSART_PARITY_DISABLED = 0,  /**< USART parity control disabled. */
    MUSART_PARITY_ENABLED        /**< USART parity control enabled. */
} EN_MUSART_parityControlOption_t;

/**
 * @brief Enumeration for USART parity selection options.
 */
typedef enum
{
    MUSART_EVEN_PARITY = 0,  /**< USART even parity. */
    MUSART_ODD_PARITY        /**< USART odd parity. */
} EN_MUSART_paritySelectionOption_t;

/**
 * @brief Enumeration for USART data size options.
 */
typedef enum
{
    MUSART_DATA_SIZE_8_BIT = 0,  /**< USART data size: 8 bits. */
    MUSART_DATA_SIZE_9_BIT        /**< USART data size: 9 bits. */
} EN_MUSART_dataSizeOptions_t;

/**
 * @brief Structure for USART clock initialization.
 */
typedef struct
{
    uint8_t clockOutput;       /**< Clock output. */
    uint8_t clockPolarity;     /**< Clock polarity. */
    uint8_t clockPhase;        /**< Clock phase. */
    uint8_t lastBitClockPulse; /**< Last bit clock pulse. */
} ST_MUSART_clockInit_t;

/**
 * @brief Structure for USART configuration.
 */
typedef struct
{
    EN_MUSART_transferControl_t copy_uddtTransferDirection;       /**< Transfer direction. */
    EN_MUSART_samplingModeOptions_t copy_uddtSamplingModeOption;  /**< Sampling mode option. */
    EN_MUSART_baudRateOptions_t copy_uddtBuadRateOption;          /**< Baud rate option. */
    EN_MUSART_dataSizeOptions_t copy_uddtDataSizeOption;          /**< Data size option. */
    EN_MUSART_parityControlOption_t copy_uddtParityControl;       /**< Parity control option. */
    EN_MUSART_paritySelectionOption_t copy_uddtParitySelection;   /**< Parity selection option. */
    EN_MUSART_stopBitOption_t copy_uddtStopBitSelection;         /**< Stop bit option. */
    uint8_t copy_HardwareFlowControl;                              /**< Hardware flow control. */
    ST_MUSART_clockInit_t copy_uddtUartClockInit;                /**< USART clock initialization. */
} ST_MUSART_cfg_t;

#endif /* MCAL_USART_USART_CONFIG_H_ */
