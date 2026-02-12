################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hardware/leds/led.c 

OBJS += \
./hardware/leds/led.o 

C_DEPS += \
./hardware/leds/led.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/leds/%.o hardware/leds/%.su hardware/leds/%.cyclo: ../hardware/leds/%.c hardware/leds/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../app -I../config -I../app/bluetooth -I../app/menu -I../app/modes -I../app/notifications -I../app/sound_detection -I../hardware/audio -I../hardware/bluetooth -I../hardware/buttons -I../hardware/buzzer -I../hardware/leds -I../hardware -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-hardware-2f-leds

clean-hardware-2f-leds:
	-$(RM) ./hardware/leds/led.cyclo ./hardware/leds/led.d ./hardware/leds/led.o ./hardware/leds/led.su

.PHONY: clean-hardware-2f-leds

