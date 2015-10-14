# FindOGLplus - attempts to locate the OGLplus library
#
# This module defines the following variables (on success):
#   OGLplus_INCLUDE_DIRS  - where to find oglplus/all.hpp
#   OGLPLUS_FOUND         - if the library was successfully located
#
# It is trying a few standard installation locations, but can be customized
# with the following variables:
#   OGLplus_ROOT_DIR  - root directory of a OGLplus installation
#                       Headers are expected to be found in:
#                       <OGLplus_ROOT_DIR>/include/oglplus/all.hpp
#                       This variable can either be a cmake or environment
#                       variable. Note however that changing the value
#                       of the environment varible will NOT result in
#                       re-running the header search and therefore NOT
#                       adjust the variables set by this module.

#=============================================================================
# Copyright 2014 Carsten Neumann
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

# default search dirs
set(_oglplus_HEADER_SEARCH_DIRS
    "/usr/include"
    "/usr/local/include")

# check environment variable
set(_oglplus_env_ROOT_DIR "$ENV{OGLplus_ROOT_DIR}")

if(NOT OGLplus_ROOT_DIR AND _oglplus_env_ROOT_DIR)
    set(OGLplus_ROOT_DIR "${_oglplus_env_ROOT_DIR}")
endif()

# put user specified location at beginning of search
if(OGLplus_ROOT_DIR)
    set(_oglplus_HEADER_SEARCH_DIRS
        "${OGLplus_ROOT_DIR}/include"
        ${_oglplus_HEADER_SEARCH_DIRS})
endif()

# locate header
find_path(OGLplus_INCLUDE_DIR "oglplus/all.hpp"
    PATHS ${_oglplus_HEADER_SEARCH_DIRS})

include("FindPackageHandleStandardArgs")
find_package_handle_standard_args(OGLplus DEFAULT_MSG
    OGLplus_INCLUDE_DIR)

if(OGLPLUS_FOUND)
    set(OGLplus_INCLUDE_DIRS "${OGLplus_INCLUDE_DIR}")

    if(NOT OGLplus_FIND_QUIETLY)
        message(STATUS "OGLplus_INCLUDE_DIR.. ${OGLplus_INCLUDE_DIR}")
    endif()
endif()

include("FeatureSummary")
set_package_properties(OGLplus PROPERTIES
    DESCRIPTION "C++ wrapper for OpenGL"
    URL "http://oglplus.org"
)
