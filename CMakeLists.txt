cmake_minimum_required(VERSION 3.25)

project(EmbedonixLibraries
  VERSION 0.1.0 # https://semver.org/spec/v0.1.0.html
  DESCRIPTION "Collection of simple yet useful c++ libraries by EMBEDONIX"
  # https://www.embedonix.com ""
  LANGUAGES CXX
)

set(CMAKE_DEBUG_POSTFIX d)

set(EMBEDONIX_LIBRARY_FILE_PREFIX "lib")

add_library(${EMBEDONIX_LIBRARY_FILE_PREFIX}Info SHARED
        Embedonix/Info.cpp Embedonix/Info.h)
add_library(${EMBEDONIX_LIBRARY_FILE_PREFIX}InfoStatic STATIC
        Embedonix/Info.cpp Embedonix/Info.h)


# Some good sources to read
#https://stackoverflow.com/questions/2152077/is-it-possible-to-get-cmake-to-build-both-a-static-and-shared-library-at-the-sam