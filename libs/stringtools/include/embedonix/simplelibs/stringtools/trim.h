//
// Created by Saeid Yazdani on 4/29/2023.
//

#pragma once

#include <string>

namespace embedonix::simplelibs::stringtools {

/**
 * Trim a string from left side
 * @param s
 */
void left_trim(std::string &s);

/**
 * Trim a string from right side
 * @param s
 */
void right_trim(std::string &s);

/**
 * Trim a string from both side
 * @param s String to be trimmed
 */
void trim(std::string &s);

/**
 * Trim copy of a string from left side
 * @param s The string to be trimmed
 * @return Left trimmed copy of the string
 */
std::string left_trim_copy(std::string s);

/**
 * Trim copy of a string from right side
 * @param s The string to be trimmed
 * @return Right trimmed copy of the string
 */
std::string right_trim_copy(std::string s);

/**
 * Trim copy of a string from both side
 * @param s The string to be trimmed
 * @return Trimmed copy of the string
 */
std::string trim_copy(std::string s);

} // End namespace namespace embedonix::simplelibs::stringtools