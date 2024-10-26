//
// Created by Saeid Yazdani on 4/22/2023.
//

#include <sstream>

#include <embedonix/simplelibs/stringtools/trim.h>
#include <embedonix/simplelibs/stringtools/split.h>
#include <embedonix/simplelibs/math/basic.h>

#include "embedonix/simplelibs/parsers/csvparser.h"


namespace embedonix::simplelibs::parsers {
    std::vector<std::vector<std::string> > csv_file(std::string_view source,
                                                    char delimiter) {
        /*
         * This parser should follow the guideline here
         * https://www.rfc-editor.org/rfc/rfc4180#page-2
         */

        std::istringstream source_stream(source.data()); // Content to be parsed
        auto result = std::vector<std::vector<std::string> >(); // To save results


        for (std::string line;
             std::getline(source_stream, line);
             /* no condition */) {
            // Now we have a line
            std::istringstream stream(line);
            std::string token;
            std::vector<std::string> lineVector;
            while (std::getline(stream, token, delimiter)) {
                // Parse line
                lineVector.push_back(token);
            }
            result.push_back(lineVector);
        }

        return result;
    }

    std::vector<std::vector<std::string> >
    csv_file_with_wrapper(std::string_view source, char delimiter, char wrapper,
                          bool skipHeader) {
        /*
         * looking for end of a field and beginning of next field
         * it should be like
         * example 1          : "ab","cd"
         * double-quoutes     : ↑--↑-↑--↑
         * char index         : 012345678
         * string size        : 123456789
         */

        std::istringstream source_stream(source.data()); // Content to be parsed
        auto rawResults = std::vector<std::vector<std::string/*_view*/> >(); // To save results
        //  auto firstLineCopy = std::string(source.begin(), source.find('\n'));
        auto firstLineCopy = std::string();
        using size_type = std::string::size_type;

        for (std::string lineToParse;
             std::getline(source_stream, lineToParse);
             /* no operation */) {
            // Now we have a line

            auto line = stringtools::trim::both_sides_copy(lineToParse);
            // Save first line
            if (firstLineCopy.size() == 0) { firstLineCopy = line; }

            // Find position of all wrappers (e.g. double-qoutes)
            auto wrappers = std::vector<size_type>(); // default is '"' double-qoute
            auto delimiters = std::vector<size_type>(); // default is ',' comma

            /* Go over the line and find position of real delimiters
             * while we might have fake delimiters within the wrappers!
             */
            for (size_type i = 0; i < line.size(); ++i) {
                if (line[i] == wrapper) {
                    wrappers.push_back(i);
                } else if (line[i] == delimiter) {
                    /**
                     * if so far we only have an ODD number of wrappers, it means the
                     * delimiter is part of the field! e.g:
                     * """a,
                     * that is two wrappers that mean a escaped wrapper
                     */
                    if (!math::basic_operations::is_odd(wrappers.size())) {
                        delimiters.push_back(i);
                    }
                }
            }

            auto chunks = std::vector<std::string>();

            // If there are no delimiters on the line, means CSV has 1 field per line :)
            if (delimiters.empty()) {
                chunks.emplace_back(line);
            }

            /*
             * This loop will ENTER if we have at least 1 delimiter (hence why we did not
             * used if/else or return if there are no delimiters on the line
             */

            for (size_t i = 0; i < delimiters.size(); ++i) {
                if (i == 0) {
                    chunks.emplace_back(&line[0], delimiters[i]); // first field
                } else {
                    chunks.emplace_back(&line[delimiters[i - 1] + 1],
                                        delimiters[i] - delimiters[i - 1] - 1);
                }
            }

            // Add the last element from the last delimiter to the end of the line
            // Note: The last element will have the wrapper character at its end, wo
            // we need to remove it manually by skipping one character at end
            chunks.emplace_back(&line[delimiters.back() + 1],
                                line.size() - delimiters.back() - (1 /*skip wrapper*/));

            // Add chunks to final result
            rawResults.push_back(chunks);
        }

        auto processesResults = std::vector<std::vector<std::string> >();

        // Skip first row regarless if skipHeader is true or false
        for (size_t i = 1; i < rawResults.size(); ++i) {
            auto processedRow = std::vector<std::string>();
            for (size_t j = 0; j < rawResults[i].size(); ++j) {
                // FIXME Avoid converting to string just to trim space and delimiers
                std::string field{rawResults[i][j]};
                stringtools::trim::both_sides(field);
                // Remove wrappers from beginining and end of the field
                processedRow.push_back({field.begin() + 1, field.end() - 1});
            }
            processesResults.push_back(processedRow);
        }

        /*
         * If skip header was false, then we need to re-read the first line because
         * all of the trimming and removal of wrapper characters have rendered the
         * first element of the return vector useless :)
         */
        if (not skipHeader) {
            auto splitted = stringtools::split::by_token(firstLineCopy, ',');
            auto firstRowProcessed = std::vector<std::string>();
            for (auto &&field: splitted) {
                firstRowProcessed.emplace_back(
                    stringtools::trim::both_sides_copy(std::string(field)));
            }

            // TODO insert might be expensive since it will potentially re-allocates the whole vector
            processesResults.insert(processesResults.begin(), firstRowProcessed);
        }


        return processesResults;
    }
} // End Namespace embedonix::simplelibs::parsers
