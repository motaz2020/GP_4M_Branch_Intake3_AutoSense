################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/ssd/ssd_prog.c 

OBJS += \
./Src/HAL/ssd/ssd_prog.o 

C_DEPS += \
./Src/HAL/ssd/ssd_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/ssd/%.o Src/HAL/ssd/%.su Src/HAL/ssd/%.cyclo: ../Src/HAL/ssd/%.c Src/HAL/ssd/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-ssd

clean-Src-2f-HAL-2f-ssd:
	-$(RM) ./Src/HAL/ssd/ssd_prog.cyclo ./Src/HAL/ssd/ssd_prog.d ./Src/HAL/ssd/ssd_prog.o ./Src/HAL/ssd/ssd_prog.su

.PHONY: clean-Src-2f-HAL-2f-ssd

