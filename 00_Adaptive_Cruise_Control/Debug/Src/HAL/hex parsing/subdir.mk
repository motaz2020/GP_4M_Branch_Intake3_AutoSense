################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/hex\ parsing/hexParsing_prog.c 

OBJS += \
./Src/HAL/hex\ parsing/hexParsing_prog.o 

C_DEPS += \
./Src/HAL/hex\ parsing/hexParsing_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/hex\ parsing/hexParsing_prog.o: ../Src/HAL/hex\ parsing/hexParsing_prog.c Src/HAL/hex\ parsing/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Src/HAL/hex parsing/hexParsing_prog.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-hex-20-parsing

clean-Src-2f-HAL-2f-hex-20-parsing:
	-$(RM) ./Src/HAL/hex\ parsing/hexParsing_prog.cyclo ./Src/HAL/hex\ parsing/hexParsing_prog.d ./Src/HAL/hex\ parsing/hexParsing_prog.o ./Src/HAL/hex\ parsing/hexParsing_prog.su

.PHONY: clean-Src-2f-HAL-2f-hex-20-parsing

