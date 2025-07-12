################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/rcc/rcc_prog.c 

OBJS += \
./Src/MCAL/rcc/rcc_prog.o 

C_DEPS += \
./Src/MCAL/rcc/rcc_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/rcc/%.o Src/MCAL/rcc/%.su Src/MCAL/rcc/%.cyclo: ../Src/MCAL/rcc/%.c Src/MCAL/rcc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-rcc

clean-Src-2f-MCAL-2f-rcc:
	-$(RM) ./Src/MCAL/rcc/rcc_prog.cyclo ./Src/MCAL/rcc/rcc_prog.d ./Src/MCAL/rcc/rcc_prog.o ./Src/MCAL/rcc/rcc_prog.su

.PHONY: clean-Src-2f-MCAL-2f-rcc

