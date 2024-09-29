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

    /**
    * Measures average execution time of a function for given number
    * of executions in microseconds
    * @tparam F Function Type
    * @tparam Args Arguments Type
    * @param runTimes Number of times to execute the function
    * @param func Function name
    * @param args Arguments to the function
    * @return Average duration it took to execute @b{func} for
    */
    template<typename F, typename... Args>
    double function_average_execution_time(size_t runTimes, F func, Args &&... args) {
        auto sum = 0.0;
        for (size_t i = 0; i < runTimes; ++i) {
            auto startTime =
                    std::chrono::high_resolution_clock::now();
            // Execute the function
            func(std::forward<Args>(args)...);
            sum += std::chrono::duration_cast<std::chrono::microseconds>
                    (std::chrono::high_resolution_clock::now() - startTime).count();
        }
        return (sum / runTimes);
    }


    /**
     * Starts a timer for a future use
     * @tparam Clock Type of the clock to be used
     * @param timer time_point for the timer
     */
    template<typename Clock>
    void start_timer(std::chrono::time_point<Clock>& timer) {
        timer = Clock::now();
    }

    /**
     * Stops a perviously set time_point and returns the duration
     * @tparam Clock Type of the clock to be used
     * @tparam Duration Resolution of the duration
     * @param timer The timer object holding the start time
     * @return
     */
    template<typename Clock, typename Duration = std::chrono::microseconds>
    double stop_timer(std::chrono::time_point<Clock>& timer) {
        return std::chrono::duration_cast<Duration>
         (Clock::now() - timer).count();
    }

}