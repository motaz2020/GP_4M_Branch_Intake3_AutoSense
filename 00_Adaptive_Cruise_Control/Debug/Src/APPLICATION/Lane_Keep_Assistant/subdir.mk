################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.c 

OBJS += \
./Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.o 

C_DEPS += \
./Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/APPLICATION/Lane_Keep_Assistant/%.o Src/APPLICATION/Lane_Keep_Assistant/%.su Src/APPLICATION/Lane_Keep_Assistant/%.cyclo: ../Src/APPLICATION/Lane_Keep_Assistant/%.c Src/APPLICATION/Lane_Keep_Assistant/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-APPLICATION-2f-Lane_Keep_Assistant

clean-Src-2f-APPLICATION-2f-Lane_Keep_Assistant:
	-$(RM) ./Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.cyclo ./Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.d ./Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.o ./Src/APPLICATION/Lane_Keep_Assistant/LKA_prog.su

.PHONY: clean-Src-2f-APPLICATION-2f-Lane_Keep_Assistant

