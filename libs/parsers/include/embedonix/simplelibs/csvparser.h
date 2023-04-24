//
// Created by Saeid Yazdani on 4/22/2023.
//

#pragma once

#include <iostream>
#include <vector>

namespace embedonix::simplelibs::parsers {
/**
 * Parse a Character Separated Value (default separator is comma ',').
 * @param source The content to parse.
 * @param valueSeparator The separator which separates elements (default is
 * a comma).
 * @param valueWrapper The character that wraps elements (default is none).
 * @return Parsed values as vector of string vector
 */
std::vector<std::vector<std::string>> parseCsvFile(std::string_view source,
                                                   char valueSeparator = ',');

}