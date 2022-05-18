################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Producto.c \
../src/Track_Prod.c \
../src/Tracking.c \
../src/Usuario.c \
../src/main.c \
../src/utn.c 

C_DEPS += \
./src/Producto.d \
./src/Track_Prod.d \
./src/Tracking.d \
./src/Usuario.d \
./src/main.d \
./src/utn.d 

OBJS += \
./src/Producto.o \
./src/Track_Prod.o \
./src/Tracking.o \
./src/Usuario.o \
./src/main.o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Producto.d ./src/Producto.o ./src/Track_Prod.d ./src/Track_Prod.o ./src/Tracking.d ./src/Tracking.o ./src/Usuario.d ./src/Usuario.o ./src/main.d ./src/main.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

