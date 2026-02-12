################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hardware/bluetooth/bluetooth.c 

OBJS += \
./hardware/bluetooth/bluetooth.o 

C_DEPS += \
./hardware/bluetooth/bluetooth.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/bluetooth/%.o hardware/bluetooth/%.su hardware/bluetooth/%.cyclo: ../hardware/bluetooth/%.c hardware/bluetooth/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../app -I../config -I../app/bluetooth -I../app/menu -I../app/modes -I../app/notifications -I../app/sound_detection -I../hardware/audio -I../hardware/bluetooth -I../hardware/buttons -I../hardware/buzzer -I../hardware/leds -I../hardware -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-hardware-2f-bluetooth

clean-hardware-2f-bluetooth:
	-$(RM) ./hardware/bluetooth/bluetooth.cyclo ./hardware/bluetooth/bluetooth.d ./hardware/bluetooth/bluetooth.o ./hardware/bluetooth/bluetooth.su

.PHONY: clean-hardware-2f-bluetooth

