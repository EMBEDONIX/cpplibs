# Description: CMake file for SimpleLibs examples
# Author: Saeid Yazdani
# Organization: EMBEDONIX.COM
# Date: 7 May 2023

cmake_minimum_required(VERSION 3.5...3.20)

project(embedonix_simplelibs_examples VERSION 0.1.0 LANGUAGES CXX)

add_executable(csvparsers
        parsers/csvparser.cpp)

target_link_directories(csvparsers PRIVATE "F:\\Embedonix\\simplelibs-dbg")
target_link_libraries(csvparsers PRIVATE embedonix_simplelibs_parsers
                                 PRIVATE embedonix_simplelibs_fileio
                                 PRIVATE embedonix_simplelibs_stringtools)
target_include_directories(csvparsers PUBLIC "F:\\Embedonix\\simplelibs-dbg\\include")

add_executable(math
        math/math.cpp)
target_link_directories(math PRIVATE "F:\\Embedonix\\simplelibs-dbg")
target_link_libraries(math PRIVATE embedonix_simplelibs_math)
target_include_directories(math PUBLIC "F:\\Embedonix\\simplelibs-dbg\\include")