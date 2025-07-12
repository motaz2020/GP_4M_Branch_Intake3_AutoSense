

#include <HAL/ultrasonic/Delay.h>
#include <HAL/ultrasonic/ult_config.h>
#include <HAL/ultrasonic/ult_interface.h>
#include "../../../Inc/COMMON/std_types.h"
#include "../../../Inc/COMMON/bit_math.h"

#include "../../../Inc/MCAL/gpio/gpio_interface.h"


void UltraSonic_Init(void)
{
    /*Configure Trig pin as output*/

	ST_MGPIO_pinCfg_t trig = {TRIG_PORT,TRIG_PIN,MGPIO_MODE_OUTPUT,
			MGPIO_OUTPUT_RESISTOR_PUSH_PULL , MGPIO_OUTPUT_SPEED_MEDIUM ,MGPIO_LOGIC_LOW,
			MGPIO_PULL_FLOATING};
	MGPIO_uddtInitPin(&trig);


    /*Configure echo pin as input*/

	ST_MGPIO_pinCfg_t echo = {ECHO_PORT,ECHO_PIN,MGPIO_MODE_INPUT,
			MGPIO_OUTPUT_RESISTOR_PUSH_PULL , MGPIO_OUTPUT_SPEED_MEDIUM ,MGPIO_LOGIC_HIGH,
			MGPIO_PULL_PULL_DOWN};
	MGPIO_uddtInitPin(&echo);

}

void UltraSonic_Send_Pulse(void) {

    // Set trigger pin high for 10 microseconds to generate a pulse
	MGPIO_uddtSetPinVal(TRIG_PORT, TRIG_PIN, MGPIO_LOGIC_HIGH);
	delay_us(10);
	MGPIO_uddtSetPinVal(TRIG_PORT, TRIG_PIN, MGPIO_LOGIC_LOW);
}

uint32_t UltraSonic_Measure_Distance(void){
    // Wait for the echo pin to go high
	EN_MGPIO_pinLogicOptions_t Copy_pu8Data = MGPIO_LOGIC_LOW;
	while(Copy_pu8Data==0)
	{
		MGPIO_uddtGetPinVal(ECHO_PORT, ECHO_PIN, &Copy_pu8Data);
	}

    // Start timer
    volatile uint32_t start_time = 0;
    while(Copy_pu8Data==1){
        start_time++;
        delay_us(1);
        MGPIO_uddtGetPinVal(ECHO_PORT,ECHO_PIN,&Copy_pu8Data);
    }
    // Calculate distance in centimeters
    volatile uint32_t distance = (start_time * 0.0343 * 10.7);
    return distance;



}
