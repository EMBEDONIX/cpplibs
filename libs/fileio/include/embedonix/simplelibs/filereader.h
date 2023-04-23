//
// Created by Saeid Yazdani on 4/23/2023.
//

#pragma once

#include <iostream>
#include <vector>


namespace embedonix::simplelibs::fileio::readers {

/**
 * Read a file as raw vector of std::byte®r
 * @param filepath Path to thee file to read
 * @return Content of the file as raw std::byte vector
 */
std::vector<std::byte> read_file_bytes(std::string_view filepath);

auto read_file(std::string_view path) -> std::string;

std::string read_file_string(std::string_view filepath);

} // End Namespace embedonix::simplelibs::fileio::readers