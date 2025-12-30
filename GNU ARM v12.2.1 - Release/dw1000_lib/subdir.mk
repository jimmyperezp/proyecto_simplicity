################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dw1000_lib/DW1000.cpp \
../dw1000_lib/DW1000Device.cpp \
../dw1000_lib/DW1000Mac.cpp \
../dw1000_lib/DW1000Ranging.cpp \
../dw1000_lib/DW1000Time.cpp \
../dw1000_lib/cookie_hal.cpp 

OBJS += \
./dw1000_lib/DW1000.o \
./dw1000_lib/DW1000Device.o \
./dw1000_lib/DW1000Mac.o \
./dw1000_lib/DW1000Ranging.o \
./dw1000_lib/DW1000Time.o \
./dw1000_lib/cookie_hal.o 

CPP_DEPS += \
./dw1000_lib/DW1000.d \
./dw1000_lib/DW1000Device.d \
./dw1000_lib/DW1000Mac.d \
./dw1000_lib/DW1000Ranging.d \
./dw1000_lib/DW1000Time.d \
./dw1000_lib/cookie_hal.d 


# Each subdirectory must supply rules for building sources it contributes
dw1000_lib/DW1000.o: ../dw1000_lib/DW1000.cpp dw1000_lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb '-DNDEBUG=1' -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"dw1000_lib/DW1000.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dw1000_lib/DW1000Device.o: ../dw1000_lib/DW1000Device.cpp dw1000_lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb '-DNDEBUG=1' -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"dw1000_lib/DW1000Device.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dw1000_lib/DW1000Mac.o: ../dw1000_lib/DW1000Mac.cpp dw1000_lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb '-DNDEBUG=1' -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"dw1000_lib/DW1000Mac.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dw1000_lib/DW1000Ranging.o: ../dw1000_lib/DW1000Ranging.cpp dw1000_lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb '-DNDEBUG=1' -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"dw1000_lib/DW1000Ranging.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dw1000_lib/DW1000Time.o: ../dw1000_lib/DW1000Time.cpp dw1000_lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb '-DNDEBUG=1' -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"dw1000_lib/DW1000Time.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

dw1000_lib/cookie_hal.o: ../dw1000_lib/cookie_hal.cpp dw1000_lib/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb '-DNDEBUG=1' -O2 -Wall -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"dw1000_lib/cookie_hal.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


