################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/hc05/hc05_prog.c 

OBJS += \
./Src/HAL/hc05/hc05_prog.o 

C_DEPS += \
./Src/HAL/hc05/hc05_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/hc05/%.o Src/HAL/hc05/%.su Src/HAL/hc05/%.cyclo: ../Src/HAL/hc05/%.c Src/HAL/hc05/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-hc05

clean-Src-2f-HAL-2f-hc05:
	-$(RM) ./Src/HAL/hc05/hc05_prog.cyclo ./Src/HAL/hc05/hc05_prog.d ./Src/HAL/hc05/hc05_prog.o ./Src/HAL/hc05/hc05_prog.su

.PHONY: clean-Src-2f-HAL-2f-hc05

