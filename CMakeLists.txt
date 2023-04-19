cmake_minimum_required(VERSION 3.25)

project(EmbedonixLibraries
  VERSION 0.1.0 # https://semver.org/spec/v0.1.0.html
  DESCRIPTION "Collection of simple yet useful c++ libraries by EMBEDONIX"
  # https://www.embedonix.com ""
  LANGUAGES CXX
)

add_library(libinfo
        Embedonix/LibInfo.cpp Embedonix/LibInfo.h)


