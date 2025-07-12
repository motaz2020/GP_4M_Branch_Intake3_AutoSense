################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MCAL/dma/dma_prog.c 

OBJS += \
./Src/MCAL/dma/dma_prog.o 

C_DEPS += \
./Src/MCAL/dma/dma_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Src/MCAL/dma/%.o Src/MCAL/dma/%.su Src/MCAL/dma/%.cyclo: ../Src/MCAL/dma/%.c Src/MCAL/dma/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-MCAL-2f-dma

clean-Src-2f-MCAL-2f-dma:
	-$(RM) ./Src/MCAL/dma/dma_prog.cyclo ./Src/MCAL/dma/dma_prog.d ./Src/MCAL/dma/dma_prog.o ./Src/MCAL/dma/dma_prog.su

.PHONY: clean-Src-2f-MCAL-2f-dma

