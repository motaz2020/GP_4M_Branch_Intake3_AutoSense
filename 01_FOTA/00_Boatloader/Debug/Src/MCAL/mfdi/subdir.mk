################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/mfdi/MFDI_program.c 

OBJS += \
./Src/MCAL/mfdi/MFDI_program.o 

C_DEPS += \
./Src/MCAL/mfdi/MFDI_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/mfdi/%.o Src/MCAL/mfdi/%.su Src/MCAL/mfdi/%.cyclo: ../Src/MCAL/mfdi/%.c Src/MCAL/mfdi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-mfdi

clean-Src-2f-MCAL-2f-mfdi:
	-$(RM) ./Src/MCAL/mfdi/MFDI_program.cyclo ./Src/MCAL/mfdi/MFDI_program.d ./Src/MCAL/mfdi/MFDI_program.o ./Src/MCAL/mfdi/MFDI_program.su

.PHONY: clean-Src-2f-MCAL-2f-mfdi

