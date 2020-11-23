
# - Try to find SystemC
# Once done, this will define
#
#  VERILATOR_FOUND - system has SystemC
#  VERILATOR_INCLUDE_DIRS - the SystemC include directories
#  
# and the following imported targets:


  find_path(VERILATOR_INCLUDE_DIR
    NAMES verilated.h verilated_sc.h
    PATHS ${VERILATOR_PREFIX}
    PATH_SUFFIXES include
  )

  set(VERILATOR_FOUND TRUE)
  set(VERILATOR_INCLUDE_DIRS ${VERILATOR_INCLUDE_DIR})
  
  #set(VERILATOR_SRCS 
  #      #${VERILATOR_INCLUDE_DIR}/verilated_cov.cpp
  #      ${VERILATOR_INCLUDE_DIR}/verilated.cpp
  #      ${VERILATOR_INCLUDE_DIR}/verilated_dpi.cpp
        #${VERILATOR_INCLUDE_DIR}/verilated_fst_c.cpp
        #${VERILATOR_INCLUDE_DIR}/verilated_save.cpp
        #${VERILATOR_INCLUDE_DIR}/verilated_threads.cpp
        #${VERILATOR_INCLUDE_DIR}/verilated_vcd_c.cpp
        #${VERILATOR_INCLUDE_DIR}/verilated_vcd_sc.cpp
        #${VERILATOR_INCLUDE_DIR}/verilated_vpi.cpp
 #   )


  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(VERILATOR
    FOUND_VAR VERILATOR_FOUND
    REQUIRED_VARS VERILATOR_INCLUDE_DIRS
  )

  #if (NOT TARGET VERILATOR::dummylib)
  #add_library(VERILATOR::dummylib INTERFACE IMPORTED)
  #set_target_properties(VERILATOR::dummylib PROPERTIES
  #  INTERFACE_INCLUDE_DIRECTORIES "${VERILATOR_INCLUDE_DIRS}"
  #)
  #endif()
