################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APPLICATION/Body_Control_Module/bcm_prog.c 

OBJS += \
./Src/APPLICATION/Body_Control_Module/bcm_prog.o 

C_DEPS += \
./Src/APPLICATION/Body_Control_Module/bcm_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APPLICATION/Body_Control_Module/%.o Src/APPLICATION/Body_Control_Module/%.su Src/APPLICATION/Body_Control_Module/%.cyclo: ../Src/APPLICATION/Body_Control_Module/%.c Src/APPLICATION/Body_Control_Module/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APPLICATION-2f-Body_Control_Module

clean-Src-2f-APPLICATION-2f-Body_Control_Module:
	-$(RM) ./Src/APPLICATION/Body_Control_Module/bcm_prog.cyclo ./Src/APPLICATION/Body_Control_Module/bcm_prog.d ./Src/APPLICATION/Body_Control_Module/bcm_prog.o ./Src/APPLICATION/Body_Control_Module/bcm_prog.su

.PHONY: clean-Src-2f-APPLICATION-2f-Body_Control_Module

