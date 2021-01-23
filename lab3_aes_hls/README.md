# AES High-level Synthesis

## Directory:

- aes_hls/c_src:     The C++ library of AES
- aes_hls/hls:       The HLS Top-level function with interface directives
- aes_hls/testbench: Testbench files for C++ model and HLS-RTL (aes_hls/testbench/aes_test.cpp) and for the VRTL SystemC (aes_hls/testbench/aes_test.cpp/systemc)
- aes_hls_prj:       Vivado-HLS project. Can be also generated from Console by invoking the tcl-script: `vivado_hls -f run_hls.tcl`

## Usage:

Gnu Make: aes_hls/Makefile

Dependencies (Linux host):
- Verilator Version >= 4.023
- SystemC Version   >= 2.3.4 compiled with C++17 (!!!)

Environment:

`export SYSTEMC=<SystemC-install-dir>`

`export VERILATOR_ROOT=<Verilator-install-dir>`

- build/cc_aes_test:    (C++ test: Performs the test on HLS top-level function)

`make test`	

- build/vrtl/:          (SystemC-VRTL model: Invokes HLS and Verilator ot build SystemC VRTL)

`make SOL=<solution-name> vrtl`

- build/sc_aes_test:    (SystemC test: Performs the test on SystemC VRTL model. aes_hls/aes.vcd contains trace data for GTK wave)

`make SOL=<solution-name> sc_test`	

- All:	      		

`make SOL=<solution-name>`		

The tests compare the models' output with a golden output file (aes_test/testbench/golden.out.dat) and report a PASS or FAIL.
