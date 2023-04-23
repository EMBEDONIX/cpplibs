# Description: Top level CMake file for Embedonix SimpleLibs
# Author: Saeid Yazdani
# Organization: EMBEDONIX.COM
# Date: 21 Apr 2023

cmake_minimum_required(VERSION 3.5...3.20)

# The default build type must be set before project()
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

project(embedonix_simplelibs
  VERSION 0.1.0 # https://semver.org/spec/v0.1.0.html
  DESCRIPTION "Collection of simple yet useful C++ libraries by EMBEDONIX"
  # https://www.embedonix.com ""
  LANGUAGES CXX
)

set(CMAKE_INSTALL_PREFIX F:/Embedonix/SimpleLibs)
set(EMBEDONIX_SIMPLELIBS_FAKE_EXEC "pwd"
        CACHE
        STRING
        "A Fake command to be called as executable when calling RUN from IDEs")

# Add library subfodlers to compile
add_subdirectory(./libs/parsers)
add_subdirectory(./libs/fileio)




# Some good sources to read
#https://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-library-at-the-sam