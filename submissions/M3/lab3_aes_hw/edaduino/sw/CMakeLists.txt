cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

SET(CMAKE_TOOLCHAIN_FILE
    "cmake/_tumeda/toolchain.cmake"
)
project(targetsoftware.elf)
include(cmake/EdaDuinoTarget.cmake)

ADD_EXECUTABLE_( ${PROJECT_NAME}
	main.c 
	app/aes.c )

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE app/)


########### DOCU ####################

OPTION(BUILD_DOC "Build doc target for this project" OFF)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR})
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/app)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/bsp)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/bsp/src)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/bsp/inc)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/cmake/_tumeda)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/cmake/edaduino/sw/libs/string_lib/inc)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/cmake/edaduino/sw/libs/string_lib/src)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/cmake/edaduino/sw/libs/sys_lib/inc)
SET(DOX_LOCATIONS ${DOX_LOCATIONS} ${PROJECT_SOURCE_DIR}/cmake/edaduino/sw/libs/sys_lib/src)
IF(BUILD_DOC)
FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
	STRING(REPLACE ";" " " P_DOX_LOCATIONS "${DOX_LOCATIONS}")
	CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cmake/doc/doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/doc/doxyfile @ONLY)
	ADD_CUSTOM_TARGET(doc
		${DOXYGEN_EXECUTABLE} doc/doxyfile
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen" VERBATIM
	)
ELSE()
    MESSAGE(WARNING "Doxygen could not be found. Build target 'doc' (e.g. make doc) will not be available")
ENDIF()
ENDIF()
