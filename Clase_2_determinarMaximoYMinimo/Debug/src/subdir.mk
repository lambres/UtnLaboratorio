################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Clase_2_determinarMaximoYMinimo.c 

C_DEPS += \
./src/Clase_2_determinarMaximoYMinimo.d 

OBJS += \
./src/Clase_2_determinarMaximoYMinimo.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Clase_2_determinarMaximoYMinimo.d ./src/Clase_2_determinarMaximoYMinimo.o

.PHONY: clean-src

