################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/dcm/dcm_prog.c 

OBJS += \
./Src/HAL/dcm/dcm_prog.o 

C_DEPS += \
./Src/HAL/dcm/dcm_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/dcm/%.o Src/HAL/dcm/%.su Src/HAL/dcm/%.cyclo: ../Src/HAL/dcm/%.c Src/HAL/dcm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-dcm

clean-Src-2f-HAL-2f-dcm:
	-$(RM) ./Src/HAL/dcm/dcm_prog.cyclo ./Src/HAL/dcm/dcm_prog.d ./Src/HAL/dcm/dcm_prog.o ./Src/HAL/dcm/dcm_prog.su

.PHONY: clean-Src-2f-HAL-2f-dcm

