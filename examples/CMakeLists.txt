# Description: CMake file for SimpleLibs examples
# Author: Saeid Yazdani
# Organization: EMBEDONIX.COM
# Date: 7 May 2023

cmake_minimum_required(VERSION 3.5...3.20)

project(embedonix_simplelibs_examples VERSION 0.1.0 LANGUAGES CXX)

add_executable(csvparsers
        parsers/csvparser.cpp)



