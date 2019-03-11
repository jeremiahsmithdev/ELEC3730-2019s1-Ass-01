################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Ass-01-Q04.c \
../Src/Ass-01-Q05.c \
../Src/Ass-01.c \
../Src/gpio.c \
../Src/main_STM32.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/usart.c 

OBJS += \
./Src/Ass-01-Q04.o \
./Src/Ass-01-Q05.o \
./Src/Ass-01.o \
./Src/gpio.o \
./Src/main_STM32.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/usart.o 

C_DEPS += \
./Src/Ass-01-Q04.d \
./Src/Ass-01-Q05.d \
./Src/Ass-01.d \
./Src/gpio.d \
./Src/main_STM32.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Tom/Desktop/ELEC3730-2019s1-Ass-01/ELEC3730_Ass1/Ass-01/Inc" -I"C:/Users/Tom/Desktop/ELEC3730-2019s1-Ass-01/ELEC3730_Ass1/Ass-01/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Tom/Desktop/ELEC3730-2019s1-Ass-01/ELEC3730_Ass1/Ass-01/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Tom/Desktop/ELEC3730-2019s1-Ass-01/ELEC3730_Ass1/Ass-01/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Tom/Desktop/ELEC3730-2019s1-Ass-01/ELEC3730_Ass1/Ass-01/Drivers/CMSIS/Include"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


