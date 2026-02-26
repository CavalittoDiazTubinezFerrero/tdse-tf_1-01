################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hardware/buzzer/buzzer.c 

OBJS += \
./hardware/buzzer/buzzer.o 

C_DEPS += \
./hardware/buzzer/buzzer.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/buzzer/%.o hardware/buzzer/%.su hardware/buzzer/%.cyclo: ../hardware/buzzer/%.c hardware/buzzer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../app -I../config -I../app/modes -I../app/notifications -I../app/sound_detection -I../hardware/audio -I../hardware/bluetooth -I../hardware/buttons -I../hardware/buzzer -I../hardware/leds -I../hardware -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-hardware-2f-buzzer

clean-hardware-2f-buzzer:
	-$(RM) ./hardware/buzzer/buzzer.cyclo ./hardware/buzzer/buzzer.d ./hardware/buzzer/buzzer.o ./hardware/buzzer/buzzer.su

.PHONY: clean-hardware-2f-buzzer

