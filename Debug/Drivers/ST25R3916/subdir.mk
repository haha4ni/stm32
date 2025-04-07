################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/ST25R3916/rfal_rfst25r3916.c \
../Drivers/ST25R3916/st25r3916.c \
../Drivers/ST25R3916/st25r3916_aat.c \
../Drivers/ST25R3916/st25r3916_com.c \
../Drivers/ST25R3916/st25r3916_irq.c \
../Drivers/ST25R3916/st25r3916_led.c \
../Drivers/ST25R3916/timer.c 

OBJS += \
./Drivers/ST25R3916/rfal_rfst25r3916.o \
./Drivers/ST25R3916/st25r3916.o \
./Drivers/ST25R3916/st25r3916_aat.o \
./Drivers/ST25R3916/st25r3916_com.o \
./Drivers/ST25R3916/st25r3916_irq.o \
./Drivers/ST25R3916/st25r3916_led.o \
./Drivers/ST25R3916/timer.o 

C_DEPS += \
./Drivers/ST25R3916/rfal_rfst25r3916.d \
./Drivers/ST25R3916/st25r3916.d \
./Drivers/ST25R3916/st25r3916_aat.d \
./Drivers/ST25R3916/st25r3916_com.d \
./Drivers/ST25R3916/st25r3916_irq.d \
./Drivers/ST25R3916/st25r3916_led.d \
./Drivers/ST25R3916/timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/ST25R3916/%.o Drivers/ST25R3916/%.su Drivers/ST25R3916/%.cyclo: ../Drivers/ST25R3916/%.c Drivers/ST25R3916/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DST25R3916B -c -I../Core/Inc -I../Drivers/ST25R3916 -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/rfal/Inc -I../Middlewares/ST/rfal/Src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-ST25R3916

clean-Drivers-2f-ST25R3916:
	-$(RM) ./Drivers/ST25R3916/rfal_rfst25r3916.cyclo ./Drivers/ST25R3916/rfal_rfst25r3916.d ./Drivers/ST25R3916/rfal_rfst25r3916.o ./Drivers/ST25R3916/rfal_rfst25r3916.su ./Drivers/ST25R3916/st25r3916.cyclo ./Drivers/ST25R3916/st25r3916.d ./Drivers/ST25R3916/st25r3916.o ./Drivers/ST25R3916/st25r3916.su ./Drivers/ST25R3916/st25r3916_aat.cyclo ./Drivers/ST25R3916/st25r3916_aat.d ./Drivers/ST25R3916/st25r3916_aat.o ./Drivers/ST25R3916/st25r3916_aat.su ./Drivers/ST25R3916/st25r3916_com.cyclo ./Drivers/ST25R3916/st25r3916_com.d ./Drivers/ST25R3916/st25r3916_com.o ./Drivers/ST25R3916/st25r3916_com.su ./Drivers/ST25R3916/st25r3916_irq.cyclo ./Drivers/ST25R3916/st25r3916_irq.d ./Drivers/ST25R3916/st25r3916_irq.o ./Drivers/ST25R3916/st25r3916_irq.su ./Drivers/ST25R3916/st25r3916_led.cyclo ./Drivers/ST25R3916/st25r3916_led.d ./Drivers/ST25R3916/st25r3916_led.o ./Drivers/ST25R3916/st25r3916_led.su ./Drivers/ST25R3916/timer.cyclo ./Drivers/ST25R3916/timer.d ./Drivers/ST25R3916/timer.o ./Drivers/ST25R3916/timer.su

.PHONY: clean-Drivers-2f-ST25R3916

