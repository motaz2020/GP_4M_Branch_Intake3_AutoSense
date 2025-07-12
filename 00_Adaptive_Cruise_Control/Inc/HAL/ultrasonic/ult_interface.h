
#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

void UltraSonic_Init(void);

/**
 * @brief Send a pulse on the Trig pin.
 *
 * This function triggers the Ultrasonic sensor to send a pulse on its Trig pin.
 * It is used to initiate the distance measurement process.
 *
 * @return No return.
 */
void UltraSonic_Send_Pulse(void);

/**
 * @brief Measure the distance using the Ultrasonic sensor.
 *
 * This function measures the distance using the Ultrasonic sensor.
 * It returns the calculated distance value in centimeters.
 *
 * @return The measured distance in centimeters.
 */
uint32_t UltraSonic_Measure_Distance(void);

#endif /* ULTRASONIC_INTERFACE_H_ */
