################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/fdi/fdi_prog.c 

OBJS += \
./Src/MCAL/fdi/fdi_prog.o 

C_DEPS += \
./Src/MCAL/fdi/fdi_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/fdi/%.o Src/MCAL/fdi/%.su Src/MCAL/fdi/%.cyclo: ../Src/MCAL/fdi/%.c Src/MCAL/fdi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-fdi

clean-Src-2f-MCAL-2f-fdi:
	-$(RM) ./Src/MCAL/fdi/fdi_prog.cyclo ./Src/MCAL/fdi/fdi_prog.d ./Src/MCAL/fdi/fdi_prog.o ./Src/MCAL/fdi/fdi_prog.su

.PHONY: clean-Src-2f-MCAL-2f-fdi

