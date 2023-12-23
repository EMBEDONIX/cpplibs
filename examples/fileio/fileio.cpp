//
// Created by Saeid Yazdani on 12/23/2023.
//

#include <iostream>


#include "embedonix/simplelibs/fileio/filereader.h"
#include "embedonix/simplelibs/utilities/benchmark.h"

void read_file_saya(std::string path) {
    volatile auto content = embedonix::simplelibs::fileio::readers::read_file(
            "../resources/random-files/one-mb-file"
    );
}
void read_file_mila(std::string path) {

}

int main(int argc, char** argv) {




    std::cout << "The size of content is:" << content.size() << std::endl;

    return 0;
}