################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/app_main.c \
../app/logger.c 

OBJS += \
./app/app_main.o \
./app/logger.o 

C_DEPS += \
./app/app_main.d \
./app/logger.d 


# Each subdirectory must supply rules for building sources it contributes
app/%.o app/%.su app/%.cyclo: ../app/%.c app/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../app -I../config -I../app/bluetooth -I../app/menu -I../app/modes -I../app/notifications -I../app/sound_detection -I../hardware/audio -I../hardware/bluetooth -I../hardware/buttons -I../hardware/buzzer -I../hardware/leds -I../hardware -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app

clean-app:
	-$(RM) ./app/app_main.cyclo ./app/app_main.d ./app/app_main.o ./app/app_main.su ./app/logger.cyclo ./app/logger.d ./app/logger.o ./app/logger.su

.PHONY: clean-app

