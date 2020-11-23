SET(_TOOLCHAIN_DIR ${CMAKE_CURRENT_LIST_DIR})

MACRO(_SETTINGS_PRE)
    SET(_LIB ${_TOOLCHAIN_DIR}/edaduino/sw)
    SET(_LIB_TUMEDA ${_TOOLCHAIN_DIR}/_tumeda)
    SET(_INCLUDES
         ${_LIB}/libs
         ${_LIB}/libs/sys_lib/inc
         ${_LIB}/libs/string_lib/inc
         ${PROJECT_SOURCE_DIR}/bsp/inc
    )

    SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
ENDMACRO()

MACRO(_SETTINGS_POST TARGET_NAME)
    TARGET_INCLUDE_DIRECTORIES(${TARGET_NAME} PUBLIC ${_INCLUDES})
    TARGET_COMPILE_OPTIONS(${TARGET_NAME} PUBLIC
        $<$<COMPILE_LANGUAGE:CXX>:-std=c++17>
        $<$<COMPILE_LANGUAGE:C>:-std=gnu99>
    )
ENDMACRO()

MACRO(ADD_LIBRARY_ TARGET_NAME)
    _SETTINGS_PRE()

    SET(ARGS "${ARGN}")
    SET(SRC_FILES ${ARGS})
    ADD_LIBRARY(${TARGET_NAME} ${SRC_FILES})

    _SETTINGS_POST(${TARGET_NAME})
ENDMACRO()

MACRO(ADD_EXECUTABLE_INTERNAL TARGET_NAME ADD_PLATFORM_FILES)
    _SETTINGS_PRE()

    # to forbid cmake running a RISCV program on host for initial compiler-probe
    SET(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

    SET(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles \
        -L ${_LIB}/ref/ \
        -T ${_LIB_TUMEDA}/edaduino.link.ld"
    )

    SET(CMAKE_TOOLCHAIN_FILE
        "${_LIB_TUMEDA}/toolchain.cmake"
    )

    PROJECT(${TARGET_NAME} LANGUAGES C CXX ASM)

    IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        ADD_DEFINITIONS(-DDEBUG_SYSTEM)
    ENDIF()
    IF(ETISS_LOGGER_ADDR)
        ADD_DEFINITIONS(-DETISS_LOGGER_ADDR=${ETISS_LOGGER_ADDR})
    ENDIF()

    IF(NOT _ROM_START)
        SET(_ROM_START 0x0)
    ENDIF()
    IF(NOT _ROM_SIZE)
        SET(_ROM_SIZE  0x00080000)
    ENDIF()
    IF(NOT _RAM_START)
        SET(_RAM_START 0x00080000)
    ENDIF()
    IF(NOT _RAM_SIZE)
        SET(_RAM_SIZE  0x00080000)
    ENDIF()
    IF(NOT _STACK_SIZE)
        SET(_STACK_SIZE 0x4000)
    ENDIF()
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
        -Xlinker --defsym=_ROM_START=${_ROM_START} \
        -Xlinker --defsym=_ROM_SIZE=${_ROM_SIZE} \
        -Xlinker --defsym=_RAM_START=${_RAM_START} \
        -Xlinker --defsym=_RAM_SIZE=${_RAM_SIZE} \
        -Xlinker --defsym=_STACK_SIZE=${_STACK_SIZE} \
    ")
    MATH(EXPR DD_ARG_SKIP "${_RAM_START}" OUTPUT_FORMAT DECIMAL)

    SET(ARGS "${ARGN}")
    SET(SRC_FILES ${ARGS})
    IF(${ADD_PLATFORM_FILES})
        LIST(APPEND SRC_FILES
            ${_LIB_TUMEDA}/edaduino.crt0.s
            ${_LIB}/libs/sys_lib/src/uart.c
            ${_LIB}/libs/sys_lib/src/timer.c
            ${PROJECT_SOURCE_DIR}/bsp/src/bsp.c
            ${PROJECT_SOURCE_DIR}/bsp/src/cust_print.c
            ${PROJECT_SOURCE_DIR}/bsp/src/exception.c
            ${PROJECT_SOURCE_DIR}/bsp/src/clint_drv.c
            ${PROJECT_SOURCE_DIR}/bsp/src/uart_drv.c
            ${_LIB}/libs/string_lib/src/qprintf.c
        )
    ENDIF()

    ADD_EXECUTABLE(${TARGET_NAME} ${SRC_FILES})

    _SETTINGS_POST(${TARGET_NAME})

    SET_TARGET_PROPERTIES(${TARGET_NAME} PROPERTIES LINK_DEPENDS ${_LIB_TUMEDA}/edaduino.link.ld)
    IF(NOT CMAKE_OBJCOPY)
        # CMake does not set this on first invocation, because the toolchain file is included
        # in the CMakeLists.txt when it should be given as cmdline argument.
        STRING(REGEX REPLACE "gcc$" "objcopy" CMAKE_OBJCOPY ${CMAKE_C_COMPILER})
    ENDIF()
    IF(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
        SET(DD_CMD ${_TOOLCHAIN_DIR}/../../../../bin/copy_binary.exe)
    ELSE()
        SET(DD_CMD dd)
    ENDIF()
    ADD_CUSTOM_COMMAND(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY}
            ARGS -O binary ${TARGET_NAME} ${TARGET_NAME}.bin
        COMMAND ${DD_CMD}
            ARGS bs=1 count=524288 if=${TARGET_NAME}.bin of=${TARGET_NAME}.rom
        COMMAND ${DD_CMD}
            ARGS bs=1 skip=${DD_ARG_SKIP} if=${TARGET_NAME}.bin of=${TARGET_NAME}.ram
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    )
    SET_PROPERTY(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
        "${TARGET_NAME}.bin"
        "${TARGET_NAME}.ram"
        "${TARGET_NAME}.rom"
    )
ENDMACRO()

MACRO(ADD_EXECUTABLE_ TARGET_NAME)
    ADD_EXECUTABLE_INTERNAL(${TARGET_NAME} ON ${ARGN})
ENDMACRO()

MACRO(ADD_EXECUTABLE_RAW TARGET_NAME)
    ADD_EXECUTABLE_INTERNAL(${TARGET_NAME} OFF ${ARGN})
ENDMACRO()
