# FindOpenImageIO - attempts to locate the Open Image IO library
#
# This module defines the following varaibles (on success):
#   OpenImageIO_INCLUDE_DIR  - where to find Open Image IO headers
#   OpenImageIO_LIBRARY      - Open Image IO library
#   OPENIMAGEIO_FOUND        - if the library was successfully located
#
# It is trying a few standard installation locations, but can be customized
# with the following variables:
#   OpenImageIO_ROOT_DIR  - root directory of an OpenImageIO installation.
#                           Headers are expected to be found in:
#                           <OpenImageIO_ROOT_DIR>/include/OpenImageIO
#                           This variable can either be a cmake or environment
#                           variable. Note however that changing the value
#                           of the environment varible will NOT result in
#                           re-running the header search and therefore NOT
#                           adjust the variables set by this module.

#=============================================================================
# Copyright 2012 Carsten Neumann
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
SET(_oiio_HEADER_SEARCH_DIRS "/usr/include"
                             "/usr/local/include")

SET(_oiio_LIBRARY_SEARCH_DIRS "/usr/lib"
                              "/usr/lib64"
                              "/usr/local/lib"
                              "/usr/local/lib64")

# check environment variable
SET(_oiio_ENV_ROOT_DIR "$ENV(OpenImageIO_ROOT_DIR)")

IF(NOT OpenImageIO_ROOT_DIR AND _oiio_ENV_ROOT_DIR)
    SET(OpenImageIO_ROOT_DIR "${_oiio_ENV_ROOT_DIR}")
ENDIF(NOT OpenImageIO_ROOT_DIR AND _oiio_ENV_ROOT_DIR)

# put user specified location at beginning of search
IF(OpenImageIO_ROOT_DIR)
    SET(_oiio_HEADER_SEARCH_DIRS  "${OpenImageIO_ROOT_DIR}/include"
                                  ${_oiio_HEADER_SEARCH_DIRS})
    SET(_oiio_LIBRARY_SEARCH_DIRS "${OpenImageIO_ROOT_DIR}/lib"
                                  "${OpenImageIO_ROOT_DIR}/lib64"
                                  ${_oiio_LIBRARY_SEARCH_DIRS})
ENDIF(OpenImageIO_ROOT_DIR)

# locate header
FIND_PATH(OpenImageIO_INCLUDE_DIR "OpenImageIO/imageio.h"
          PATHS ${_oiio_HEADER_SEARCH_DIRS}
          DOC "Path to the directory that contains OpenImageIO/imageio.h")

# locate library
FIND_LIBRARY(OpenImageIO_LIBRARY NAMES "OpenImageIO"
             PATHS ${_oiio_LIBRARY_SEARCH_DIRS}
             DOC "Path to the OpenImageIO library")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OpenImageIO DEFAULT_MSG
                                  OpenImageIO_INCLUDE_DIR
                                  OpenImageIO_LIBRARY)

IF(OPENIMAGEIO_FOUND)
    SET(OpenImageIO_INCLUDE_DIRS "${OpenImageIO_INCLUDE_DIR}")
    SET(OpenImageIO_LIBRARIES    "${OpenImageIO_LIBRARY}")

    MESSAGE(STATUS "OpenImageIO_INCLUDE_DIR.. ${OpenImageIO_INCLUDE_DIR}")
    MESSAGE(STATUS "OpenImageIO_LIBRARIES.... ${OpenImageIO_LIBRARIES}")
ENDIF(OPENIMAGEIO_FOUND)
