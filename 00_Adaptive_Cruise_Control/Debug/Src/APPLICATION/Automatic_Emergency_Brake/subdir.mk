################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.c 

OBJS += \
./Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.o 

C_DEPS += \
./Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APPLICATION/Automatic_Emergency_Brake/%.o Src/APPLICATION/Automatic_Emergency_Brake/%.su Src/APPLICATION/Automatic_Emergency_Brake/%.cyclo: ../Src/APPLICATION/Automatic_Emergency_Brake/%.c Src/APPLICATION/Automatic_Emergency_Brake/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APPLICATION-2f-Automatic_Emergency_Brake

clean-Src-2f-APPLICATION-2f-Automatic_Emergency_Brake:
	-$(RM) ./Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.cyclo ./Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.d ./Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.o ./Src/APPLICATION/Automatic_Emergency_Brake/aeb_prog.su

.PHONY: clean-Src-2f-APPLICATION-2f-Automatic_Emergency_Brake

