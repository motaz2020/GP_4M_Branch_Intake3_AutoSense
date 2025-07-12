################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APPLICATION/User_Dashboard_Interface/udi_prog.c 

OBJS += \
./Src/APPLICATION/User_Dashboard_Interface/udi_prog.o 

C_DEPS += \
./Src/APPLICATION/User_Dashboard_Interface/udi_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APPLICATION/User_Dashboard_Interface/%.o Src/APPLICATION/User_Dashboard_Interface/%.su Src/APPLICATION/User_Dashboard_Interface/%.cyclo: ../Src/APPLICATION/User_Dashboard_Interface/%.c Src/APPLICATION/User_Dashboard_Interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APPLICATION-2f-User_Dashboard_Interface

clean-Src-2f-APPLICATION-2f-User_Dashboard_Interface:
	-$(RM) ./Src/APPLICATION/User_Dashboard_Interface/udi_prog.cyclo ./Src/APPLICATION/User_Dashboard_Interface/udi_prog.d ./Src/APPLICATION/User_Dashboard_Interface/udi_prog.o ./Src/APPLICATION/User_Dashboard_Interface/udi_prog.su

.PHONY: clean-Src-2f-APPLICATION-2f-User_Dashboard_Interface

