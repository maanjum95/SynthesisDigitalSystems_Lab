# VP: EDAduino Virtual Prototype

## Contents

- `./README.md` This file.
- `./src/` EDAduino source files
- `./include/` EDAduino header files
- `./ini/` VP runtime configuration files
- `./.tmp/` VP temporary directory for POSIX FIFOs
- `./cmake/` Package finder CMake scripts
- `./main.cpp` EDAduino main Cpp file
- `./CMakeLists.txt` CMake main file.
- `./run_vp_tgb.sh` Reduced helper script for target GDB support

## Build

1.  Make a new build directory: 

    `mkdir <build-dir>`    

2.  Change into build directory:

    `cd <build-dir>`     

3.  Generate (G-)Makefiles with CMake (>v3.15.0):

    `cmake -DETISS_PREFIX=<path-to-ETISS-installdir> -DMinresSCC_PREFIX=<path-to-MinresSCC-installdir> -DSYSTEMC_PREFIX=<path-to-SystemC-installdir> -DETISS_VPLIB_PREFIX=<path-to-ETISS-VPlib-installdir> ..`

4.  Build with GMake:
    
    `make` 

## Build @SDS-Lab

0.  Source environment:
    
    `source ../environment.sh`

1.  Make a new build directory: 

    `mkdir <build-dir>`    

2.  Change into build directory:

    `cd <build-dir>`     

3.  Generate (G-)Makefiles with CMake:

    `$CMAKE_HOME/bin/cmake -DETISS_PREFIX=$ETISS_HOME -DMinresSCC_PREFIX=$SCC_MINRES_HOME -DSYSTEMC_PREFIX=$SYSTEMC_HOME -DETISS_VPLIB_PREFIX=$ETISS_VPLIB_HOME ..`    

4.  Build with GMake:
    
    `make` 
    
## Usage
The VP is configured by various 'ini'-files. If the location of the target software ELF file differs from the path specified in `ini/elf.ini`, the path has to adapted.

### Run in terminal:

    `<build-dir>/edaduino_vp -iini/base.ini -iini/elf.ini`
    
### Run in terminal with target GDB:
        
    `<build-dir>/edaduino_vp -iini/base.ini -iini/elf.ini -iini/remote.ini` 
    
    
The ETISS GDB core will halt the target software on main entry. `ini/remote.ini` sets the TCP port value, e.g. 2222. A remote GDB debugger can then connect to local TCP port 2222. Launch a target GDB session and connect to ETISS GDB server with:

    `<path-to-riscv-toolchain>/bin/*gdb` -ex "tar rem :2222" ../sw/<build-dir>/targetsoftware.elf`
    
### Read out UART port:

If stdin/stdout is used in target software, i.e. 
`printf()` the VP routes these messages to the virtual UART port. VP's UART opens a POSIX FIFO (named process pipeline) that can be read out from terminal or by other applications that support standard file read/write. To test the UART you can simply use `cat`

    `cat .tmp/uartdevicefifoout`
    
    
