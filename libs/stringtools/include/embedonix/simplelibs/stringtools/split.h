//
// Created by Saeid Yazdani on 05/06/2023.
//

#pragma once

#include <iostream>
#include <ranges>
#include <string_view>

namespace embedonix::simplelibs::stringtools::split {

/**
 * Split a string by the given token
 * @param content A Sequence of characters
 * @param token Token to split by
 * @return A Container filled with splitted parts of the content
 */
constexpr auto by_token(auto content, std::string_view token) {
  using namespace std::ranges;
  return content
         | views::split(token)
         | views::transform([](auto&& str) {
    return std::string_view(&*str.begin(), distance(str));
  });
}

/**
 * Split a string by the given token
 * @param content A Sequence of characters
 * @param token Token to split by
 * @return A Container filled with splitted parts of the content
 */
constexpr auto by_token(auto content, char token) {
  using namespace std::ranges;
  return content
         | views::split(token)
         | views::transform([](auto&& str) {
    return std::string_view(&*str.begin(), distance(str));
  });
}

/*
Another possible method:
     constexpr std::string_view words{"Hello^_^C++^_^20^_^!"};
    constexpr std::string_view delim{"^_^"};

    for (const auto word : std::views::split(words, delim))
        std::cout << std::quoted(std::string_view{word.begin(), word.end()}) << ' ';
 */

} // End namespace namespace embedonix::simplelibs::stringtools