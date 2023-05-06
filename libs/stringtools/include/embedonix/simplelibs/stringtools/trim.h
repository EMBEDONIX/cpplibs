//
// Created by Saeid Yazdani on 4/29/2023.
//

#pragma once

#include <string>

namespace embedonix::simplelibs::stringtools::trim {

/**
 * Trim a string from left side
 * @param s
 */
void left(std::string& s);

/**
 * Trim a string from right side
 * @param s
 */
void right(std::string& s);

/**
 * Trim a string from both side
 * @param s String to be trimmed
 */
void both_sides(std::string& s);

/**
 * Trim copy of a string from left side
 * @param s The string to be trimmed
 * @return Left trimmed copy of the string
 */
std::string left_copy(std::string s);

/**
 * Trim copy of a string from right side
 * @param s The string to be trimmed
 * @return Right trimmed copy of the string
 */
std::string right_copy(std::string s);

/**
 * Trim copy of a string from both side
 * @param s The string to be trimmed
 * @return Trimmed copy of the string
 */
std::string both_sides_copy(std::string s);

} // End namespace namespace embedonix::simplelibs::stringtools