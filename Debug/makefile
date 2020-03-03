################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/sc/subdir.mk
-include MCAL/I2c/src/subdir.mk
-include MCAL/DIO/Src/subdir.mk
-include MCAL/ADC/Src/subdir.mk
-include HAL/LCD/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
FLASHER.lss \

FLASH_IMAGE += \
FLASHER.hex \


# All Target
all: FLASHER.elf secondary-outputs

# Tool invocations
FLASHER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FLASHER.map -mmcu=atmega32 -o "FLASHER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FLASHER.lss: FLASHER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FLASHER.elf  >"FLASHER.lss"
	@echo 'Finished building: $@'
	@echo ' '

FLASHER.hex: FLASHER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FLASHER.elf  "FLASHER.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FLASHER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
