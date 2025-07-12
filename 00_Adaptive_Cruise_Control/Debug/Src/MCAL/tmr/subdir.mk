################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/tmr/tmr_prog.c 

OBJS += \
./Src/MCAL/tmr/tmr_prog.o 

C_DEPS += \
./Src/MCAL/tmr/tmr_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/tmr/%.o Src/MCAL/tmr/%.su Src/MCAL/tmr/%.cyclo: ../Src/MCAL/tmr/%.c Src/MCAL/tmr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-tmr

clean-Src-2f-MCAL-2f-tmr:
	-$(RM) ./Src/MCAL/tmr/tmr_prog.cyclo ./Src/MCAL/tmr/tmr_prog.d ./Src/MCAL/tmr/tmr_prog.o ./Src/MCAL/tmr/tmr_prog.su

.PHONY: clean-Src-2f-MCAL-2f-tmr

