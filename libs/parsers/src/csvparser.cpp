//
// Created by Saeid Yazdani on 4/22/2023.
//

#include <embedonix/simplelibs/csvparser.h>
#include <fstream>
#include <sstream>

namespace embedonix::simplelibs::parsers {

std::vector<std::vector<std::string>> parseCsvFile(std::string_view source,
                                                   char valueSeparator) {
    /*
     * This parser should follow the guideline here
     * https://www.rfc-editor.org/rfc/rfc4180#page-2
     */

    auto result = std::vector<std::vector<std::string>>(); // To save results
    std::istringstream source_stream(source.data());

    for(std::string line;
        std::getline(source_stream, line);
        /* No terminate cond */) {
        std::istringstream stream(line);
        std::string token;
        std::vector<std::string> lineVector;
        while(std::getline(stream, token, valueSeparator)) {
            lineVector.push_back(token);
        }
        result.push_back(lineVector);
    }

    return result;
}
} // End namespace embedonix::simplelibs::io::parsers
