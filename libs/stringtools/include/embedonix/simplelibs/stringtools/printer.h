//
// Created by Saeid Yazdani on 4/30/2023.
//

#pragma once

#include <iostream>
#include <ranges>

namespace embedonix::simplelibs::stringtools {

/**
 * Prints all elements of a container to stdout
 * @tparam CONTAINER A Container compatible with std containers
 * @tparam ELEMENT_TYPE Type of the element in the container
 * @tparam SEPARATOR Type of printable to be put between each element when
 * printing
 * @param container Container to print
 * @param delimiter A Character or string to separate each element
 * @param addNewLine Add a new line when done printing
 * @param os The stream to print into
 */

template<class CONTAINER, typename DELIMITER = char>
void print_container(const CONTAINER& container, DELIMITER delimiter = ' ',
                     bool addNewLine = true,
                     std::ostream& os = std::cout) {
  auto it = std::begin(container);
  auto end = std::end(container);

  if (it != end) { // There is at least one element available :)
    os << *it; // Print first element
    for (++it; it != end; ++it) { // Print the rest, if available
      os << delimiter << *it;
    }
    if(addNewLine) {
      os << std::endl;
    }
  }
}


} // End namespace embedonix::simplelibs::stringtools