
/nfs/tools/xilinx/Vivado/2019.1/bin/xelab xil_defaultlib.apatb_aes16_bidir_top glbl -prj aes16_bidir.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm --initfile "/nfs/tools/xilinx/Vivado/2019.1/data/xsim/ip/xsim_ip.ini" --lib "ieee_proposed=./ieee_proposed" -s aes16_bidir 
/nfs/tools/xilinx/Vivado/2019.1/bin/xsim --noieeewarnings aes16_bidir -tclbatch aes16_bidir.tcl

