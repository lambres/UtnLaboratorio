################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Passenger.c \
../main.c \
../parser.c \
../utn.c 

C_DEPS += \
./Controller.d \
./Passenger.d \
./main.d \
./parser.d \
./utn.d 

OBJS += \
./Controller.o \
./Passenger.o \
./main.o \
./parser.o \
./utn.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Controller.d ./Controller.o ./Passenger.d ./Passenger.o ./main.d ./main.o ./parser.d ./parser.o ./utn.d ./utn.o

.PHONY: clean--2e-

