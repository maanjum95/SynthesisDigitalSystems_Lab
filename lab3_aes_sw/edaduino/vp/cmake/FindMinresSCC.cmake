
# - Try to find MinresSCC
# Once done, this will define
#
#  MinresSCC_FOUND - system has MinresSCC
#  MinresSCC_INCLUDE_DIRS - the MinresSCC include directories
#  MinresSCC_LIBRARIES - link these to use MinresSCC
#
# and the following imported targets:
#
#  Minres::SCC - The MinresSCC library



find_path(MinresSCC_INCLUDE_DIR
  NAMES scc
  PATHS ${MinresSCC_PREFIX} ${MinresSCC_HOME}
  PATH_SUFFIXES include
)

find_library(MinresSCC_LIBRARY
  NAMES scc
  PATHS ${MinresSCC_PREFIX} ${MinresSCC_HOME}
  PATH_SUFFIXES lib lib/static/
)

if(NOT MinresSCC_LIBRARY)
  message(FATAL_ERROR
    "Minres::SCC not found. Please set MinresSCC_PREFIX to its install location"
  )
endif()

set(MinresSCC_FOUND TRUE)
set(MinresSCC_INCLUDE_DIRS ${MinresSCC_INCLUDE_DIR})
set(MinresSCC_LIBRARIES ${MinresSCC_LIBRARY})


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MinresSCC
  FOUND_VAR MinresSCC_FOUND
  REQUIRED_VARS MinresSCC_INCLUDE_DIRS MinresSCC_LIBRARIES
)

if (NOT TARGET Minres::SCC)
  add_library(Minres::SCC UNKNOWN IMPORTED)
  set_target_properties(Minres::SCC PROPERTIES
    IMPORTED_LOCATION "${MinresSCC_LIBRARIES}"
    INTERFACE_INCLUDE_DIRECTORIES "${MinresSCC_INCLUDE_DIRS}"
  )
endif()
