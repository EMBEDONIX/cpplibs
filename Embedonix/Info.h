//
// Created by Saeid Yazdani on 4/19/2023.
//

#pragma once

#include <string>

namespace embedonix {
  /**
   * Get the version of library
   * @return Library version
   */
  std::string libraryVersion();
  /**
   * Get the library name
   * @return Library name
   */
  std::string libraryName();
  /**
   * Get the library description
   * @return Library description
   */
  std::string libraryDescription();
}
