################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/sound_detection/sound_detector.c 

OBJS += \
./app/sound_detection/sound_detector.o 

C_DEPS += \
./app/sound_detection/sound_detector.d 


# Each subdirectory must supply rules for building sources it contributes
app/sound_detection/%.o app/sound_detection/%.su app/sound_detection/%.cyclo: ../app/sound_detection/%.c app/sound_detection/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../app -I../config -I../app/bluetooth -I../app/menu -I../app/modes -I../app/notifications -I../app/sound_detection -I../hardware/audio -I../hardware/bluetooth -I../hardware/buttons -I../hardware/buzzer -I../hardware/leds -I../hardware -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-2f-sound_detection

clean-app-2f-sound_detection:
	-$(RM) ./app/sound_detection/sound_detector.cyclo ./app/sound_detection/sound_detector.d ./app/sound_detection/sound_detector.o ./app/sound_detection/sound_detector.su

.PHONY: clean-app-2f-sound_detection

