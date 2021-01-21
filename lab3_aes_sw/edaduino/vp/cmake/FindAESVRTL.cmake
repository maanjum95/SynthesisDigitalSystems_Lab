
# - Try to find AESVRTL
# Once done, this will define
#
#  AESVRTL_FOUND
#  AESVRTL_INCLUDE_DIRS
#  AESVRTL_LIBRARIES
#
# and the following imported targets:
#
#  AESVRTL::Vaes16_bidir - The Verilated and compiled library of AES HA


find_path(AESVRTL_INCLUDE_DIR
  NAMES Vaes16_bidir.h
  PATHS ${AESVRTL_PREFIX} ${AESVRTL_HOME}
  PATH_SUFFIXES include
)

find_library(AESVRTL_LIBRARY
  NAMES Vaes16_bidir
  PATHS ${AESVRTL_PREFIX}
  PATH_SUFFIXES lib
)

if(NOT AESVRTL_LIBRARY)
  message(FATAL_ERROR
    "AESVRTL alias Vaes16_bidir not found. Please set AESVRTL_PREFIX to its install location"
  )
endif()

set(AESVRTL_FOUND TRUE)
set(AESVRTL_INCLUDE_DIRS ${AESVRTL_INCLUDE_DIR})
set(AESVRTL_LIBRARIES ${AESVRTL_LIBRARY})


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AESVRTL
  FOUND_VAR AESVRTL_FOUND
  REQUIRED_VARS AESVRTL_INCLUDE_DIRS AESVRTL_LIBRARIES
)

if (NOT TARGET AESVRTL::Vaes16_bidir)
  add_library(AESVRTL::Vaes16_bidir INTERFACE IMPORTED)
  set_target_properties(AESVRTL::Vaes16_bidir PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${AESVRTL_INCLUDE_DIRS}"
    INTERFACE_LINK_LIBRARIES "${AESVRTL_LIBRARIES}"
  )
endif()
