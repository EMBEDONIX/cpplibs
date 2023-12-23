# Description: CMake file for SimpleLibs examples
# Author: Saeid Yazdani
# Organization: EMBEDONIX.COM
# Date: 7 May 2023

cmake_minimum_required(VERSION 3.5...3.20)

project(embedonix_simplelibs_examples VERSION 0.1.0 LANGUAGES CXX)

# Get resource dir that resides above current folder
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH RESOURCES_DIR)

# Example fileio
add_executable(fileio
        fileio/fileio.cpp)

target_link_directories(fileio PRIVATE "F:\\Embedonix\\simplelibs-dbg")
target_link_libraries(fileio PRIVATE embedonix_simplelibs_fileio
        PRIVATE embedonix_simplelibs_fileio
        PRIVATE embedonix_simplelibs_stringtools)
target_include_directories(fileio PUBLIC "F:\\Embedonix\\simplelibs-dbg\\include")

install(DIRECTORY "${RESOURCES_DIR}/examples/resources/random-files"
        DESTINATION "${CMAKE_BINARY_DIR}/resources")

# Example csvparsers
add_executable(csvparser
        parsers/csvparser.cpp)

target_link_directories(csvparser PRIVATE "F:\\Embedonix\\simplelibs-dbg")
target_link_libraries(csvparser PRIVATE embedonix_simplelibs_parsers
        PRIVATE embedonix_simplelibs_fileio
        PRIVATE embedonix_simplelibs_stringtools)
target_include_directories(csvparser PUBLIC "F:\\Embedonix\\simplelibs-dbg\\include")

install(DIRECTORY "${RESOURCES_DIR}/examples/resources/csv-files"
        DESTINATION "${CMAKE_BINARY_DIR}/resources")

add_executable(math
        math/math.cpp)
target_link_directories(math PRIVATE "F:\\Embedonix\\simplelibs-dbg")
target_link_libraries(math PRIVATE embedonix_simplelibs_math)
target_include_directories(math PUBLIC "F:\\Embedonix\\simplelibs-dbg\\include")