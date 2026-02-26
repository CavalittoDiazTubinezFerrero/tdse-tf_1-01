################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hardware/buttons/dip_switch.c 

OBJS += \
./hardware/buttons/dip_switch.o 

C_DEPS += \
./hardware/buttons/dip_switch.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/buttons/%.o hardware/buttons/%.su hardware/buttons/%.cyclo: ../hardware/buttons/%.c hardware/buttons/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../app -I../config -I../app/modes -I../app/notifications -I../app/sound_detection -I../hardware/audio -I../hardware/bluetooth -I../hardware/buttons -I../hardware/buzzer -I../hardware/leds -I../hardware -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-hardware-2f-buttons

clean-hardware-2f-buttons:
	-$(RM) ./hardware/buttons/dip_switch.cyclo ./hardware/buttons/dip_switch.d ./hardware/buttons/dip_switch.o ./hardware/buttons/dip_switch.su

.PHONY: clean-hardware-2f-buttons

