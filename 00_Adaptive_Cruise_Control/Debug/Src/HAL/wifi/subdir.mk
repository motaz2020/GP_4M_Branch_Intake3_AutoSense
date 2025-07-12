################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/wifi/wifi_prog.c 

OBJS += \
./Src/HAL/wifi/wifi_prog.o 

C_DEPS += \
./Src/HAL/wifi/wifi_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/wifi/%.o Src/HAL/wifi/%.su Src/HAL/wifi/%.cyclo: ../Src/HAL/wifi/%.c Src/HAL/wifi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-wifi

clean-Src-2f-HAL-2f-wifi:
	-$(RM) ./Src/HAL/wifi/wifi_prog.cyclo ./Src/HAL/wifi/wifi_prog.d ./Src/HAL/wifi/wifi_prog.o ./Src/HAL/wifi/wifi_prog.su

.PHONY: clean-Src-2f-HAL-2f-wifi

