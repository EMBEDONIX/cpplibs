# Description: CMake file for SimpleLibs FILEIO Library
# Author: Saeid Yazdani
# Organization: EMBEDONIX.COM
# Date: 23 Apr 2023

cmake_minimum_required(VERSION 3.5...3.20)

project(embedonix_simplelibs_fileio VERSION 0.1.0 LANGUAGES CXX)

add_library(embedonix_simplelibs_fileio
        src/filereader.cpp)
add_library(embedonix::simplelibs::fileio ALIAS embedonix_simplelibs_fileio)

target_compile_features(embedonix_simplelibs_fileio PUBLIC cxx_std_20)
target_include_directories(embedonix_simplelibs_fileio PUBLIC include)

install(TARGETS embedonix_simplelibs_fileio
        # CONFIGURATIONS Debug ## Commented out because I want same for both releaes and debug
        DESTINATION /)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/"
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.h")