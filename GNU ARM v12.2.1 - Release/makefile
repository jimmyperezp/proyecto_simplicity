################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include dw1000_lib/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := cookie_migration
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: cookie_migration.axf

# Tool invocations
cookie_migration.axf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -T "cookie_migration.ld" --specs=nosys.specs -Xlinker --gc-sections -Xlinker -Map="cookie_migration.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o cookie_migration.axf "./dw1000_lib/DW1000.o" "./dw1000_lib/DW1000Device.o" "./dw1000_lib/DW1000Mac.o" "./dw1000_lib/DW1000Ranging.o" "./dw1000_lib/DW1000Time.o" "./dw1000_lib/cookie_hal.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building out file: cookie_migration.out'
	arm-none-eabi-objcopy "cookie_migration.axf" "cookie_migration.out"
	@echo ' '

	@echo 'Building hex file: cookie_migration.hex'
	arm-none-eabi-objcopy -O ihex "cookie_migration.axf" "cookie_migration.hex"
	@echo ' '

	@echo 'Building bin file: cookie_migration.bin'
	arm-none-eabi-objcopy -O binary "cookie_migration.axf" "cookie_migration.bin"
	@echo ' '

	@echo 'Building s37 file: cookie_migration.s37'
	arm-none-eabi-objcopy -O srec "cookie_migration.axf" "cookie_migration.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "cookie_migration.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(CC_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C++_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CCM_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_UPPER_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CXX_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CXXM_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C++M_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(CPP_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) cookie_migration.axf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
