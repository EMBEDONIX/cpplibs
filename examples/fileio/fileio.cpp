//
// Created by Saeid Yazdani on 12/23/2023.
//

#include <iostream>
#include <thread>
#include <chrono>


#include "embedonix/simplelibs/fileio/filereader.h"
#include "embedonix/simplelibs/utilities/benchmark.h"

void sleepFunction(int milli) {
    // Convert seconds to a std::chrono duration
    std::chrono::milliseconds duration(milli);

    // Sleep for the specified duration
    std::this_thread::sleep_for(duration);
}

void read_file_saya(std::string path) {
    volatile auto content = embedonix::simplelibs::fileio
    ::readers::read_file_bytes(path);
//    sleepFunction(100);
}

void read_file_mila(std::string path, std::vector<std::byte> &buffer) {
    volatile auto result = embedonix::simplelibs::fileio::readers::read_file_bytes_caller_alloc(
            path, buffer);
    if (!result) {
        exit(1);
    }

//    sleepFunction(100);
}

void read_file_string(std::string path) {
    volatile auto result = embedonix::simplelibs::fileio::readers::
    read_file(path);
}

int main(int argc, char **argv) {

    // Allocate a big enough buffer for files up to 10MB
    auto buffer = std::vector<std::byte>(11'000'000);

    auto fileToRead = "../resources/random-files/ten-mb-file";

    for (size_t i = 0; i < 10; ++i) {
        std::cout << "read_file_bytes_caller_alloc read:\t\t" <<
                  embedonix::simplelibs::utilities::benchmark::measure::
                  function_execution_time(read_file_mila,
                                          fileToRead,
                                          buffer)
                  << std::endl;
    }

    for (size_t i = 0; i < 10; ++i) {
        std::cout << "read_file_bytes read:\t\t\t\t" <<
                  embedonix::simplelibs::utilities::benchmark::measure::
                  function_execution_time(read_file_saya,
                                          fileToRead)
                  << std::endl;
    }

    for (size_t i = 0; i < 10; ++i) {
        std::cout << "read_file read:\t\t\t\t\t" <<
                  embedonix::simplelibs::utilities::benchmark::measure::
                  function_execution_time(read_file_string,
                                          fileToRead)
                  << std::endl;
    }


    return 0;
}