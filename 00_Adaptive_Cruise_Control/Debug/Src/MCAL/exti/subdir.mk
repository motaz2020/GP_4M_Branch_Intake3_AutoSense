################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/exti/exti_prog.c 

OBJS += \
./Src/MCAL/exti/exti_prog.o 

C_DEPS += \
./Src/MCAL/exti/exti_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/exti/%.o Src/MCAL/exti/%.su Src/MCAL/exti/%.cyclo: ../Src/MCAL/exti/%.c Src/MCAL/exti/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-exti

clean-Src-2f-MCAL-2f-exti:
	-$(RM) ./Src/MCAL/exti/exti_prog.cyclo ./Src/MCAL/exti/exti_prog.d ./Src/MCAL/exti/exti_prog.o ./Src/MCAL/exti/exti_prog.su

.PHONY: clean-Src-2f-MCAL-2f-exti

