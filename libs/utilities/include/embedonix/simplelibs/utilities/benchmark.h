//
// Created by Saeid Yazdani on 5/7/2023.
//

#pragma once

#include <chrono>
#include <utility>

namespace embedonix::simplelibs::utilities::benchmark::measure {
    /**
     * Measure execution time of a function in microseconds
     * @tparam F Function Type
     * @tparam Args Arguments Type
     * @param func Function name
     * @param args Arguments to the function
     * @return
     */
    template<typename F, typename... Args>
    double function_execution_time(F func, Args &&... args) {
        auto startTime =
                std::chrono::high_resolution_clock::now();
        // Execute the function
        func(std::forward<Args>(args)...);
        return std::chrono::duration_cast<std::chrono::microseconds>
                (std::chrono::high_resolution_clock::now() - startTime).count();
    }
}