//
// Created by Saeid Yazdani on 5/7/2023.
//

#pragma once

#include <chrono>
#include <utility>

namespace embedonix::simplelibs::utilities::benchmark::measure {
    template<typename F, typename... Args>
    double function_execution_time(F func, Args &&... args) {
        std::chrono::high_resolution_clock::time_point t1 =
                std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::high_resolution_clock::now() - t1).count();
    }
}