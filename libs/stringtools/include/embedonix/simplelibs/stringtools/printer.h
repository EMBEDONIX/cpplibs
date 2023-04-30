//
// Created by Saeid Yazdani on 4/30/2023.
//

#pragma once

#include <iostream>
#include <ranges>

namespace embedonix::simplelibs::stringtools {

/**
 * Prints all elements of a container to stdout
 * @tparam CONTAINER
 * @tparam ELEMENT_TYPE
 * @tparam SEPARATOR
 * @param container
 * @param separator
 */
template
    <
        template<typename...> typename CONTAINER,
        typename ELEMENT_TYPE,
        typename SEPARATOR
    >
void print_container(const CONTAINER<ELEMENT_TYPE>& container,
                     SEPARATOR separator = ' ',
                     FILE *stream = stdout) {

  // Keep track of how many elements have been printed out
  typename CONTAINER<ELEMENT_TYPE>::size_type index = 0;
  // we do not want to print separator after last element, so this is the stop
  typename CONTAINER<ELEMENT_TYPE>::size_type lastIndex = container.size() - 1;

  for (const auto& element: container) {
    if (stream == stdout) {
      std::cout << element;
      if (index < lastIndex) {
        std::cout << separator;
      }
    } else if (stream == stderr) {
      std::cerr << element;
      if (index < lastIndex) {
        std::cerr << separator;
      }
    }
    index++;
  }
}
} // End namespace embedonix::simplelibs::stringtools