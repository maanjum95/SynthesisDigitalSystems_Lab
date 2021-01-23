################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/testbench/aes_test.c 

OBJS += \
./testbench/aes_test.o 

C_DEPS += \
./testbench/aes_test.d 


# Each subdirectory must supply rules for building sources it contributes
testbench/aes_test.o: /nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/testbench/aes_test.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls -I/nfs/tools/xilinx/Vivado/2019.1/include -I/nfs/tools/xilinx/Vivado/2019.1/lnx64/tools/systemc/include -I/nfs/tools/xilinx/Vivado/2019.1/include/etc -I/nfs/tools/xilinx/Vivado/2019.1/lnx64/tools/auto_cc/include -I/nfs/tools/xilinx/Vivado/2019.1/include/ap_sysc -O0 -g3 -Wall -Wno-unknown-pragmas -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"testbench/aes_test.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


