
# - Try to find SystemC
# Once done, this will define
#
#  SYSTEMC_FOUND - system has SystemC
#  SYSTEMC_INCLUDE_DIRS - the SystemC include directories
#  SYSTEMC_LIBRARIES - link these to use SystemC
#
# and the following imported targets:
#
#  SystemC::systemc - The SystemC library



set(SystemCLanguage_DIR "${SYSTEMC_PREFIX}/lib/cmake/SystemCLanguage")
find_package(SystemCLanguage CONFIG)

if (NOT TARGET SystemC::systemc)
  find_path(SYSTEMC_INCLUDE_DIR
    NAMES systemc
    PATHS ${SYSTEMC_PREFIX} ${SYSTEMC_HOME}
    PATH_SUFFIXES include
  )

  find_library(SYSTEMC_LIBRARY
    NAMES systemc
    PATHS ${SYSTEMC_PREFIX} ${SYSTEMC_HOME}
    PATH_SUFFIXES lib-linux64 lib
  )

  if(NOT SYSTEMC_LIBRARY)
    message(FATAL_ERROR
      "SystemC not found. Please set SYSTEMC_PREFIX to its install location"
    )
  endif()

  set(SYSTEMC_FOUND TRUE)
  set(SYSTEMC_INCLUDE_DIRS ${SYSTEMC_INCLUDE_DIR})
  set(SYSTEMC_LIBRARIES ${SYSTEMC_LIBRARY})


  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(SystemC
    FOUND_VAR SYSTEMC_FOUND
    REQUIRED_VARS SYSTEMC_INCLUDE_DIRS SYSTEMC_LIBRARIES
  )

  if (NOT TARGET SystemC::systemc)
    add_library(SystemC::systemc UNKNOWN IMPORTED)
    set_target_properties(SystemC::systemc PROPERTIES
      IMPORTED_LOCATION "${SYSTEMC_LIBRARIES}"
      INTERFACE_INCLUDE_DIRECTORIES "${SYSTEMC_INCLUDE_DIRS}"
    )
  endif()
endif()
