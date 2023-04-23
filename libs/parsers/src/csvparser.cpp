//
// Created by Saeid Yazdani on 4/22/2023.
//

#include <embedonix/simplelibs/csvparser.h>

namespace embedonix::simplelibs::parsers {

std::vector<std::vector<std::string>> parseCsvFile() {
    return {
            {"GOD", "DAMN", "IT"},
            {"four", "five", "six"}
    };
}
} // End namespace embedonix::simplelibs::io::parsers
