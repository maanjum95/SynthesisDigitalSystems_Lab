set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR EdaDuino)

IF(NOT RISCV_ELF_GCC_PREFIX)
  MESSAGE("RISCV: " $ENV{RISCV})
  SET(RISCV_ELF_GCC_PREFIX $ENV{RISCV})
ENDIF()

string(FIND ${RISCV_ELF_GCC_PREFIX} "/usr/local/labs/SDS" RV32)

if(RV32 EQUAL -1)
    set(DEFAULT_BASENAME "riscv64-unknown-elf")
else()
    set(DEFAULT_BASENAME "riscv32-unknown-elf")
endif()

set(RISCV_ELF_GCC_BASENAME ${DEFAULT_BASENAME} CACHE STRING "base name of the toolchain executables")

set(CMAKE_C_COMPILER ${RISCV_ELF_GCC_PREFIX}/bin/${RISCV_ELF_GCC_BASENAME}-gcc${EXE_EXT})
set(CMAKE_CXX_COMPILER ${RISCV_ELF_GCC_PREFIX}/bin/${RISCV_ELF_GCC_BASENAME}-g++${EXE_EXT})
set(CMAKE_OBJCOPY ${RISCV_ELF_GCC_PREFIX}/bin/${RISCV_ELF_GCC_BASENAME}-objcopy${EXE_EXT})

add_definitions(-D__riscv__)
add_definitions(-march=rv32im)
add_definitions(-mabi=ilp32)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -march=rv32im -mabi=ilp32")
