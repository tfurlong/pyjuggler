# - try to find JCCL 1.5 library
# Requires VPR 2.3 (thus FindVPR23.cmake)
# Optionally uses Flagpoll and FindFlagpoll.cmake
#
# This library is a part of VR Juggler 3.1 - you probably want to use
# find_package(VRJuggler31) instead, for an easy interface to this and
# related scripts.  See FindVRJuggler31.cmake for more information.
#
#  JCCL15_LIBRARY_DIR, library search path
#  JCCL15_INCLUDE_DIR, include search path
#  JCCL15_LIBRARY, the library to link against
#  JCCL15_FOUND, If false, do not try to use this library.
#
# Plural versions refer to this library and its dependencies, and
# are recommended to be used instead, unless you have a good reason.
#
# Useful configuration variables you might want to add to your cache:
#  JCCL15_ROOT_DIR - A directory prefix to search
#                    (a path that contains include/ as a subdirectory)
#
# This script will use Flagpoll, if found, to provide hints to the location
# of this library, but does not use the compiler flags returned by Flagpoll
# directly.
#
# The VJ_BASE_DIR environment variable is also searched (preferentially)
# when searching for this component, so most sane build environments should
# "just work."  Note that you need to manually re-run CMake if you change
# this environment variable, because it cannot auto-detect this change
# and trigger an automatic re-run.
#
# Original Author:
# 2009-2010 Ryan Pavlik <rpavlik@iastate.edu> <abiryan@ryand.net>
# http://academic.cleardefinition.com
# Iowa State University HCI Graduate Program/VRAC
# Updated for VR Juggler 3.0 by:
# Brandon Newendorp <brandon@newendorp.com>
# Updated for VR Juggler 3.1 by:
# Carsten Neumann <carsten_neumann@gmx.net>


set(_HUMAN "JCCL 1.5")
set(_FP_PKG_NAME jccl)
set(_RELEASE_NAMES)
set(_DEBUG_NAMES)
foreach(VER 1_5 1_5_0 1_5_1)
	list(APPEND _RELEASE_NAMES ${_FP_PKG_NAME}-${VER})
	list(APPEND _DEBUG_NAMES ${_FP_PKG_NAME}_d-${VER})
endforeach()
set(_DIR jccl-1.5)
set(_HEADER jccl/jcclConfig.h)

include(SelectLibraryConfigurations)
include(CreateImportedTarget)
include(CleanLibraryList)
include(CleanDirectoryList)

if(JCCL15_FIND_QUIETLY)
	set(_FIND_FLAGS "QUIET")
else()
	set(_FIND_FLAGS "")
endif()

# Try flagpoll.
find_package(Flagpoll QUIET)

if(FLAGPOLL)
	flagpoll_get_include_dirs(${_FP_PKG_NAME} NO_DEPS)
	flagpoll_get_library_dirs(${_FP_PKG_NAME} NO_DEPS)
endif()

set(JCCL15_ROOT_DIR
	"${JCCL15_ROOT_DIR}"
	CACHE
	PATH
	"Root directory to search for JCCL")
if(DEFINED VRJUGGLER31_ROOT_DIR)
	mark_as_advanced(JCCL15_ROOT_DIR)
endif()
if(NOT JCCL15_ROOT_DIR)
	set(JCCL15_ROOT_DIR "${VRJUGGLER31_ROOT_DIR}")
endif()

set(_ROOT_DIR ${JCCL15_ROOT_DIR})

find_path(JCCL15_INCLUDE_DIR
	${_HEADER}
	HINTS
	"${_ROOT_DIR}"
	${${_FP_PKG_NAME}_FLAGPOLL_INCLUDE_DIRS}
	PATH_SUFFIXES
	${_DIR}
	include/${_DIR}
	include/
	DOC
	"Path to ${_HUMAN} includes root")

find_library(JCCL15_LIBRARY_RELEASE
	NAMES
	${_RELEASE_NAMES}
	HINTS
	"${_ROOT_DIR}"
	${${_FP_PKG_NAME}_FLAGPOLL_LIBRARY_DIRS}
	PATH_SUFFIXES
	${_VRJ_LIBSUFFIXES}
	DOC
	"${_HUMAN} release library full path")

find_library(JCCL15_LIBRARY_DEBUG
	NAMES
	${_DEBUG_NAMES}
	HINTS
	"${_ROOT_DIR}"
	${${_FP_PKG_NAME}_FLAGPOLL_LIBRARY_DIRS}
	PATH_SUFFIXES
	${_VRJ_LIBDSUFFIXES}
	DOC
	"${_HUMAN} debug library full path")

select_library_configurations(JCCL15)

# Dependency
if(NOT VPR23_FOUND)
	find_package(VPR23 ${_FIND_FLAGS})
endif()

# handle the QUIETLY and REQUIRED arguments and set xxx_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(JCCL15
	DEFAULT_MSG
	JCCL15_LIBRARY
	JCCL15_INCLUDE_DIR
	VPR23_FOUND
	VPR23_LIBRARIES
	VPR23_INCLUDE_DIR)

if(JCCL15_FOUND)
	set(_DEPS ${VPR23_LIBRARIES})

	set(JCCL15_INCLUDE_DIRS ${JCCL15_INCLUDE_DIR})
	list(APPEND JCCL15_INCLUDE_DIRS ${VPR23_INCLUDE_DIRS})
	clean_directory_list(JCCL15_INCLUDE_DIRS)

	if(VRJUGGLER31_CREATE_IMPORTED_TARGETS)
		create_imported_target(JCCL15 ${_DEPS})
	else()
		clean_library_list(JCCL15_LIBRARIES)
	endif()

	mark_as_advanced(JCCL15_ROOT_DIR)
endif()

mark_as_advanced(JCCL15_LIBRARY_RELEASE
	JCCL15_LIBRARY_DEBUG
	JCCL15_INCLUDE_DIR)
