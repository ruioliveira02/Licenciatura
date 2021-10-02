################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Ficha50.c \
../src/teste.c 

OBJS += \
./src/Ficha50.o \
./src/teste.o 

C_DEPS += \
./src/Ficha50.d \
./src/teste.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/rui-oliveira/Universidade/1º Ano/2º Semestre/PI/Ficha 50 Questões/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


