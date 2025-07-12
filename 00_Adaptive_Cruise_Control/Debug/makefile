################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/MCAL/usart/subdir.mk
-include Src/MCAL/tmr/subdir.mk
-include Src/MCAL/systick/subdir.mk
-include Src/MCAL/rcc/subdir.mk
-include Src/MCAL/nvic/subdir.mk
-include Src/MCAL/gpio/subdir.mk
-include Src/MCAL/exti/subdir.mk
-include Src/HAL/ultrasonic/subdir.mk
-include Src/HAL/ir/subdir.mk
-include Src/HAL/hc05/subdir.mk
-include Src/HAL/dcm/subdir.mk
-include Src/APPLICATION/User_Dashboard_Interface/subdir.mk
-include Src/APPLICATION/Normal_Cruise_Control/subdir.mk
-include Src/APPLICATION/Lane_Keep_Assistant/subdir.mk
-include Src/APPLICATION/Body_Control_Module/subdir.mk
-include Src/APPLICATION/Automatic_Emergency_Brake/subdir.mk
-include Src/APPLICATION/Adaptive_Cruise_Control/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Adaptive_Cruise_Control
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Adaptive_Cruise_Control.elf \

MAP_FILES += \
Adaptive_Cruise_Control.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Adaptive_Cruise_Control.list \

OBJCOPY_HEX += \
Adaptive_Cruise_Control.hex \


# All Target
all: main-build

# Main-build Target
main-build: Adaptive_Cruise_Control.elf secondary-outputs

# Tool invocations
Adaptive_Cruise_Control.elf Adaptive_Cruise_Control.map: $(OBJS) $(USER_OBJS) C:\Users\elkot\Downloads\Adaptive_Cruise_Control\STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Adaptive_Cruise_Control.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\elkot\Downloads\Adaptive_Cruise_Control\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Adaptive_Cruise_Control.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Adaptive_Cruise_Control.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Adaptive_Cruise_Control.list"
	@echo 'Finished building: $@'
	@echo ' '

Adaptive_Cruise_Control.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Adaptive_Cruise_Control.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Adaptive_Cruise_Control.elf Adaptive_Cruise_Control.hex Adaptive_Cruise_Control.list Adaptive_Cruise_Control.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
