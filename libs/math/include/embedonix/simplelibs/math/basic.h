//
// Created by YAZDANI on 21.04.2023.
//

#pragma once

#include <type_traits>

/**
 * @brief Contains basic math operations
 */
namespace embedonix::simplelibs::math::basicoperations {

template<class T>
concept IntegralNumber = std::is_integral_v<T>;

/**
 * @brief Adds two values
 * @tparam T Value Type
 * @param lhs First (left side) argument
 * @param rhs Second (right side) argument
 * @return Values Added together
 */
template<typename T>
T addValues(const T &lhs, const T &rhs) {
  return (lhs + rhs);
}

/**
 * Check if a numeric value is even.
 * @tparam T Type of the parameter
 * @param t value of the parameter
 * @return true if value is even
 */
template<IntegralNumber T>
 constexpr bool isEven(T t) {
  return ((t % 2) == 0);
}

template<IntegralNumber T>
constexpr bool isOdd(T t) {
  return (not isEven(t));
}

 bool isEven(bool) = delete; // Do not allow bool to be used as argument

 bool isOdd(bool) = delete; // Do not allow bool to be used as argument

}