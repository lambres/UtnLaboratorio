################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayPassenger.c \
../src/Passenger_Flight.c \
../src/TP2.c \
../src/eFlight.c \
../src/utn.c 

C_DEPS += \
./src/ArrayPassenger.d \
./src/Passenger_Flight.d \
./src/TP2.d \
./src/eFlight.d \
./src/utn.d 

OBJS += \
./src/ArrayPassenger.o \
./src/Passenger_Flight.o \
./src/TP2.o \
./src/eFlight.o \
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
	-$(RM) ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/Passenger_Flight.d ./src/Passenger_Flight.o ./src/TP2.d ./src/TP2.o ./src/eFlight.d ./src/eFlight.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

