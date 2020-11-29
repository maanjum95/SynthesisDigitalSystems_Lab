
# - Try to find ETISSVP
# Once done, this will define
#
#  ETISSVP_FOUND
#  ETISSVP_INCLUDE_DIRS
#  ETISSVP_LIBRARIES
#
# and the following imported targets:
#
#  ETISSVP::etissvp - The etiss library


find_path(ETISSVP_INCLUDE_DIR
  NAMES etissvp
  PATHS ${ETISS_VPLIB_PREFIX} ${ETISS_VPLIB_HOME}
  PATH_SUFFIXES include
)

find_library(ETISSVP_LIBRARY
  NAMES etissvp
  PATHS ${ETISS_VPLIB_PREFIX} ${ETISS_VPLIB_HOME}
  PATH_SUFFIXES lib
)

if(NOT ETISSVP_LIBRARY)
  message(FATAL_ERROR
    "ETISSVP not found. Please set ETISS_VPLIB_PREFIX to its install location"
  )
endif()

set(ETISSVP_FOUND TRUE)
set(ETISSVP_INCLUDE_DIRS ${ETISSVP_INCLUDE_DIR})
set(ETISSVP_LIBRARIES ${ETISSVP_LIBRARY})


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ETISSVP
  FOUND_VAR ETISSVP_FOUND
  REQUIRED_VARS ETISSVP_INCLUDE_DIRS ETISSVP_LIBRARIES
)

if (NOT TARGET ETISSVP::etissvp)
  add_library(ETISSVP::etissvp INTERFACE IMPORTED)
  set_target_properties(ETISSVP::etissvp PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${ETISSVP_INCLUDE_DIRS}"
    INTERFACE_LINK_LIBRARIES "${ETISSVP_LIBRARIES}"
  )
endif()
