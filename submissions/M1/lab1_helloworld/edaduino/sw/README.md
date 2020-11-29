# SW: EDAduino Target Software

## Contents

- `./README.md` This file.
- `./bsp/` Board support package (bsp) and peripheral drivers
- `./cmake/` edaduino and riscv driver and linker library. Additional CMake files.
- `./main.c` Target software C main file
- `./CMakeLists.txt` CMake main file.

## Build

1.  Make a new build directory: 

    `mkdir build`    

2.  Change into build directory:

    `cd build`     

3.  Generate (G-)Makefiles with CMake:

    `cmake -DCMAKE_BUILD_TYPE=Debug -DRISCV_ELF_GCC_PREFIX=<path-to-risv32-gnu-toolchain> ..`    

4.  Build with GMake:
    
    `make` 

## Build @SDS-Lab

0.  Source environment:

```    
    source ../environment.sh
```

1.  Make a new build directory: 

```
    mkdir build
```

2.  Change into build directory:

```
    cd build     
```

3.  Generate (G-)Makefiles with CMake:

```
    cmake -DCMAKE_BUILD_TYPE=Debug -DRISCV_ELF_GCC_PREFIX=$RISCV .. 
```

4.  Build with GMake:
    
```
    make 
```
    
## Usage

See VP: Run the compiled `targetsoftware.elf` binary on EDAduino VP (helper scripts are provided with vp).
