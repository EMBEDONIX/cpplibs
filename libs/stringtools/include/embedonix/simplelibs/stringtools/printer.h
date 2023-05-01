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
 * @param separator A Character or string to separate each element
 * @param addNewLineAtEnd Add a new line when done printing
 * @param stream The stream to print into
 */
template
    <
        template<typename...> typename CONTAINER,
        typename ELEMENT_TYPE,
        typename SEPARATOR = char // need the hint for default parameter type
    >
void print_container(const CONTAINER<ELEMENT_TYPE>& container,
                     SEPARATOR separator = ' ',
                     bool addNewLineAtEnd = true,
                     std::ostream& stream = std::cout) {

  // Keep track of how many elements have been printed out
  typename CONTAINER<ELEMENT_TYPE>::size_type index = 0;
  // we do not want to print separator after last element, so this is the stop
  typename CONTAINER<ELEMENT_TYPE>::size_type lastIndex = container.size() - 1;

  for (const auto& element: container) {
    stream << element;
    if (index < lastIndex) { // If not the last element, add separator
      stream << separator;
    }
    index++;
  }

  if (addNewLineAtEnd) {
    stream << std::endl;
  }

}

} // End namespace embedonix::simplelibs::stringtools