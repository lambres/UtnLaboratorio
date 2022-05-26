################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Hashtag.c \
../src/Posteo.c \
../src/Posteo_Hashtag.c \
../src/SabadoClase5Ejercicio5-1.c \
../src/Usuario.c \
../src/Usuario_Posteo.c \
../src/utn.c 

C_DEPS += \
./src/Hashtag.d \
./src/Posteo.d \
./src/Posteo_Hashtag.d \
./src/SabadoClase5Ejercicio5-1.d \
./src/Usuario.d \
./src/Usuario_Posteo.d \
./src/utn.d 

OBJS += \
./src/Hashtag.o \
./src/Posteo.o \
./src/Posteo_Hashtag.o \
./src/SabadoClase5Ejercicio5-1.o \
./src/Usuario.o \
./src/Usuario_Posteo.o \
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
	-$(RM) ./src/Hashtag.d ./src/Hashtag.o ./src/Posteo.d ./src/Posteo.o ./src/Posteo_Hashtag.d ./src/Posteo_Hashtag.o ./src/SabadoClase5Ejercicio5-1.d ./src/SabadoClase5Ejercicio5-1.o ./src/Usuario.d ./src/Usuario.o ./src/Usuario_Posteo.d ./src/Usuario_Posteo.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

