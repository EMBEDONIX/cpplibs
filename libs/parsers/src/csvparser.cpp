//
// Created by Saeid Yazdani on 4/22/2023.
//

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "embedonix/simplelibs/parsers/csvparser.h"
#include <embedonix/simplelibs/math/basic.h>

namespace embedonix::simplelibs::parsers {

std::vector<std::vector<std::string>> parseCsvFile(std::string_view source,
                                                   char delimeter) {
  /*
   * This parser should follow the guideline here
   * https://www.rfc-editor.org/rfc/rfc4180#page-2
   */

  auto result = std::vector<std::vector<std::string>>(); // To save results
  std::istringstream source_stream(source.data());

  for (std::string line;
       std::getline(source_stream, line);
    /* No terminate cond */) {
    std::istringstream stream(line);
    std::string token;
    std::vector<std::string> lineVector;
    while (std::getline(stream, token, delimeter)) {
      lineVector.push_back(token);
    }
    result.push_back(lineVector);
  }

  return result;
}

std::vector<std::vector<std::string>>
parseWrappedCsvFile(std::string_view source, char delimeter, char wrapper) {
  auto result = std::vector<std::vector<std::string>>(); // To save results
  std::istringstream source_stream(source.data());

  auto currentLineNumber = 1; // We asume lines start from one :)
  for (std::string line;
       std::getline(source_stream, line);
       ++currentLineNumber) {

    // Make sure we have even number of wrapper characters
    auto numWrappersPerLine = std::count(line.begin(), line.end(),
                                         wrapper);
    if (not math::basicoperations::isEven(numWrappersPerLine)) {
      auto msg = std::string("Invalid wrapper character count at line ") +
                 std::string(std::to_string(currentLineNumber));
      throw std::runtime_error(msg.c_str());
    }

    std::istringstream stream(line);
    std::string token;
    std::vector<std::string> lineVector;
    while (std::getline(stream, token, delimeter)) {
      lineVector.push_back(token);
    }
    result.push_back(lineVector);
  }

  return result;
}
} // End namespace embedonix::simplelibs::io::parsers
