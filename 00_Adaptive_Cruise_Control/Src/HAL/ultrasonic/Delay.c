
#include "../../../Inc/HAL/ultrasonic/Delay.h"
#include "../../../Inc/COMMON/std_types.h"
#include "../../../Inc/COMMON/bit_math.h"


void delay_us(uint32_t microseconds) {
    // Assuming a 16MHz system clock
    microseconds = microseconds * 16;
    while (microseconds--) {
        __asm__("NOP");
    }
}
