//
// Created by Saeid Yazdani on 4/22/2023.
//

#include <sstream>
#include <algorithm>

#include "embedonix/simplelibs/parsers/csvparser.h"
#include <embedonix/simplelibs/math/basic.h>

namespace embedonix::simplelibs::parsers {

std::vector<std::vector<std::string>> parseCsvFile(std::string_view source,
                                                   char delimiter) {
  /*
   * This parser should follow the guideline here
   * https://www.rfc-editor.org/rfc/rfc4180#page-2
   */

  std::istringstream source_stream(source.data()); // Content to be parsed
  auto result = std::vector<std::vector<std::string>>(); // To save results


  for (std::string line;
       std::getline(source_stream, line);
    /* no condition */) { // Now we have a line
    std::istringstream stream(line);
    std::string token;
    std::vector<std::string> lineVector;
    while (std::getline(stream, token, delimiter)) { // Parse line
      lineVector.push_back(token);
    }
    result.push_back(lineVector);
  }

  return result;
}

std::vector<std::vector<std::string>>
parseWrappedCsvFile(std::string_view source, char delimiter, char wrapper) {

  auto result = std::vector<std::vector<std::string>>(); // To save results
  std::istringstream source_stream(source.data());

  auto currentLineNumber = 1; // We asume lines start from one :)
  for (std::string line;
       std::getline(source_stream, line);
       ++currentLineNumber) {

    /* RFC-4180 -> If double-quotes are used to enclose fields, then a
     * double-quote appearing inside a field must be escaped by preceding it
     * with another double quote.
     * Example - Lets say a field should be:
     *
     * item,name,price
     * "monitor","SAMSUNG UL2780 27""","270$"
     *
     */


    auto numWrappersPerLine = std::count(line.begin(), line.end(),
                                         wrapper);


    /*
     * looking for end of a field and beginning of next field
     * it should be like
     * example 1          : "ab","cd"
     * double-quoutes     : ↑--↑-↑--↑
     * char index         : 012345678
     * string size        : 123456789
     *
     */

    // Find position of all wrappers (e.g. double-qoutes)
    auto wrapperPositions = std::vector<int>();
    for (auto i = 0; i < line.size(); ++i) {
      if(line[i] == wrapper) {
        wrapperPositions.push_back(i);
      }
    }

    auto chunks = std::vector<std::string>();
    for (auto pos = 0; pos < line.size(); ++pos) {
      if(line[pos] == wrapper) {
        int nextWrapperPos = line.find("\",", pos); // find closing wrapper
        if(nextWrapperPos not_eq std::string::npos) {
          chunks.push_back({line[pos], line[nextWrapperPos]});
        }
      }
    }





    auto stream = std::istringstream(line);
    auto token = std::string(); // To be filled by getline()
    auto choppedValues = std::vector<std::string>(); // to contain parts

    // TODO Check between wrapper characters to see there is any delimiter!
    while (std::getline(stream, token, delimiter)) {
      choppedValues.push_back(token);
    }

    result.push_back(choppedValues);
  }

  return result;
}
} // End Namespace embedonix::simplelibs::parsers
