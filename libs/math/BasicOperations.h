//
// Created by YAZDANI on 21.04.2023.
//

#pragma once

/**
 * @brief Contains basic math operations
 */
namespace embedonix::simplelibs::math::basicoperations {

  /**
   * @brief Adds two values
   * @tparam T Value Type
   * @param lhs First (left side) argument
   * @param rhs Second (right side) argument
   * @return Values Added together
   */
  template<typename T>
  T addValues(const T& lhs, const T& rhs) {
    return ( lhs + rhs );
  }

}