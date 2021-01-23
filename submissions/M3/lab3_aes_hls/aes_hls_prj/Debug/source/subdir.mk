################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/c_src/aes.c \
/nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/hls/top_aes.c 

OBJS += \
./source/aes.o \
./source/top_aes.o 

C_DEPS += \
./source/aes.d \
./source/top_aes.d 


# Each subdirectory must supply rules for building sources it contributes
source/aes.o: /nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/c_src/aes.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -I/nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls -I/nfs/tools/xilinx/Vivado/2019.1/include -I/nfs/tools/xilinx/Vivado/2019.1/lnx64/tools/systemc/include -I/nfs/tools/xilinx/Vivado/2019.1/include/etc -I/nfs/tools/xilinx/Vivado/2019.1/lnx64/tools/auto_cc/include -I/nfs/tools/xilinx/Vivado/2019.1/include/ap_sysc -I/data/home.local/repos/labsds/aes_hls -I/nas/ei/home/ge29noy/repos/labsds/aes_hls -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/top_aes.o: /nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls/hls/top_aes.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -I/nas/ei/share/TUEIEDA/LabSDS/SS20/ge29noy/labsds/aes_hls -I/nfs/tools/xilinx/Vivado/2019.1/include -I/nfs/tools/xilinx/Vivado/2019.1/lnx64/tools/systemc/include -I/nfs/tools/xilinx/Vivado/2019.1/include/etc -I/nfs/tools/xilinx/Vivado/2019.1/lnx64/tools/auto_cc/include -I/nfs/tools/xilinx/Vivado/2019.1/include/ap_sysc -I/data/home.local/repos/labsds/aes_hls -I/nas/ei/home/ge29noy/repos/labsds/aes_hls -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


