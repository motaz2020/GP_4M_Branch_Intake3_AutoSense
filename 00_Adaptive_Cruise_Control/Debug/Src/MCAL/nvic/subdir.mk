################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/nvic/nvic_prog.c 

OBJS += \
./Src/MCAL/nvic/nvic_prog.o 

C_DEPS += \
./Src/MCAL/nvic/nvic_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/nvic/%.o Src/MCAL/nvic/%.su Src/MCAL/nvic/%.cyclo: ../Src/MCAL/nvic/%.c Src/MCAL/nvic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-nvic

clean-Src-2f-MCAL-2f-nvic:
	-$(RM) ./Src/MCAL/nvic/nvic_prog.cyclo ./Src/MCAL/nvic/nvic_prog.d ./Src/MCAL/nvic/nvic_prog.o ./Src/MCAL/nvic/nvic_prog.su

.PHONY: clean-Src-2f-MCAL-2f-nvic

