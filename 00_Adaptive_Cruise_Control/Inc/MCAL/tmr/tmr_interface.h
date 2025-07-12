/**
 * @file tmr_interface.h
 * @brief Header file for the Multi-Mode Timer (MTMR) module.
 */

#ifndef MCAL_TMR_TMR_INTERFACE_H_
#define MCAL_TMR_TMR_INTERFACE_H_

#include "../../COMMON/bit_math.h"
#include "../../COMMON/std_types.h"
#include "tmr_private.h"
#include "tmr_config.h"

/**
 * @brief Start the specified Multi-Function Timer.
 *
 * This function starts the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to start.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vStartTimer(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Stop the specified Multi-Function Timer.
 *
 * This function stops the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to stop.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vStopTimer(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Set the prescaler value for the specified Multi-Function Timer.
 *
 * This function sets the prescaler value for the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @param copy_u16Value The prescaler value to set.
 * @return No return.
 */
void MTMR_vSetTimerPrescaler(EN_MTMR_number_t copy_uddtTMRNumber, uint16_t copy_u16Value);

/**
 * @brief Enable One-Pulse Mode for the specified Multi-Function Timer.
 *
 * This function enables One-Pulse Mode for the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vEnableTimerOPM(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Reset the count of the specified Multi-Function Timer.
 *
 * This function resets the count of the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to reset.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vTimerCountRst(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Set the output mode for a specific channel of the Multi-Function Timer.
 *
 * This function sets the output mode for a specific channel of the Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @param copy_uddtTimerMode The mode to set for the timer channel.
 *        Possible values are:
 *        - #MTMR_MODE_FROZEN
 *        - #MTMR_MODE_ACTIVE
 *        - #MTMR_MODE_INACTIVE
 *        - #MTMR_MODE_TOGGLE
 *        - #MTMR_MODE_INACTIVE_FORCE
 *        - #MTMR_MODE_ACTIVE_FORCE
 *        - #MTMR_MODE_PWM_MODE1
 *        - #MTMR_MODE_PWM_MODE2
 * @param copy_uddtChannelNumber The channel number to configure.
 *        Possible values are:
 *        - #MTMR_CH1
 *        - #MTMR_CH2
 *        - #MTMR_CH3
 *        - #MTMR_CH4
 * @return No return.
 */
void MTMR_vSetTimerChannelOutput(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_selectedMode_t copy_uddtTimerMode, EN_MTMR_channel_t copy_uddtChannelNumber);

/**
 * @brief Set the input mode for a specific channel of the Multi-Function Timer.
 *
 * This function sets the input mode for a specific channel of the Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @param copy_uddtChannelNumber The channel number to configure.
 *        Possible values are:
 *        - #MTMR_CH1
 *        - #MTMR_CH2
 *        - #MTMR_CH3
 *        - #MTMR_CH4
 * @return No return.
 */
void MTMR_vSetTimerChannelInput(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber);

/**
 * @brief Set the Auto-Reload Register value for the specified Multi-Function Timer.
 *
 * This function sets the Auto-Reload Register value for the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @param copy_u32Value The value to set for the Auto-Reload Register.
 * @return No return.
 */
void MTMR_vSetTimerARR(EN_MTMR_number_t copy_uddtTMRNumber, uint32_t copy_u32Value);

/**
 * @brief Stop the specified Multi-Function Timer.
 *
 * This function stops the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to stop.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vSetTimerStop(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Clear the count of the specified Multi-Function Timer.
 *
 * This function clears the count of the specified Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to clear.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vClearTimerCount(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Enable the interrupt for the specified Multi-Function Timer input capture.
 *
 * This function enables the interrupt for the specified Multi-Function Timer input capture.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @return No return.
 */
void MTMR_vEnableTimerICUInt(EN_MTMR_number_t copy_uddtTMRNumber);

/**
 * @brief Set the compare value for the specified channel of the Multi-Function Timer.
 *
 * This function sets the compare value for the specified channel of the Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to configure.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @param copy_uddtChannelNumber The channel number to configure.
 *        Possible values are:
 *        - #MTMR_CH1
 *        - #MTMR_CH2
 *        - #MTMR_CH3
 *        - #MTMR_CH4
 * @param copy_u32CmpValue The compare value to set.
 * @return No return.
 */
void MTMR_vSetTimerCMPVal(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber, uint32_t copy_u32CmpValue);

/**
 * @brief Read the capture value for the specified channel of the Multi-Function Timer.
 *
 * This function reads the capture value for the specified channel of the Multi-Function Timer.
 *
 * @param copy_uddtTMRNumber The Multi-Function Timer to read from.
 *        Possible values are:
 *        - #MTMR2
 *        - #MTMR3
 *        - #MTMR4
 *        - #MTMR5
 * @param copy_uddtChannelNumber The channel number to read from.
 *        Possible values are:
 *        - #MTMR_CH1
 *        - #MTMR_CH2
 *        - #MTMR_CH3
 *        - #MTMR_CH4
 * @return The captured value from the specified channel.
 */
uint32_t MTMR_vReadCaptureVal(EN_MTMR_number_t copy_uddtTMRNumber, EN_MTMR_channel_t copy_uddtChannelNumber);

/**
 * @brief Initialize the capture compare functionality for Multi-Function Timer 3.
 *
 * This function initializes the capture compare functionality for Multi-Function Timer 3.
 *
 * @return No return.
 */
void MTMR3_vCaptureCompareInit(void);

#endif /* MCAL_TMR_TMR_INTERFACE_H_ */
