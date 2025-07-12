################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APPLICATION/Normal_Cruise_Control/ncc_prog.c 

OBJS += \
./Src/APPLICATION/Normal_Cruise_Control/ncc_prog.o 

C_DEPS += \
./Src/APPLICATION/Normal_Cruise_Control/ncc_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APPLICATION/Normal_Cruise_Control/%.o Src/APPLICATION/Normal_Cruise_Control/%.su Src/APPLICATION/Normal_Cruise_Control/%.cyclo: ../Src/APPLICATION/Normal_Cruise_Control/%.c Src/APPLICATION/Normal_Cruise_Control/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APPLICATION-2f-Normal_Cruise_Control

clean-Src-2f-APPLICATION-2f-Normal_Cruise_Control:
	-$(RM) ./Src/APPLICATION/Normal_Cruise_Control/ncc_prog.cyclo ./Src/APPLICATION/Normal_Cruise_Control/ncc_prog.d ./Src/APPLICATION/Normal_Cruise_Control/ncc_prog.o ./Src/APPLICATION/Normal_Cruise_Control/ncc_prog.su

.PHONY: clean-Src-2f-APPLICATION-2f-Normal_Cruise_Control

