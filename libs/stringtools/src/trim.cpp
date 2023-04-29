#include <cctype>
#include <embedonix/simplelibs/stringtools/trim.h>

namespace embedonix::simplelibs::stringtools {

void left_trim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                  [](unsigned char ch) {
                                    return !std::isspace(ch);
                                  }));
}

void right_trim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) {
                         return !std::isspace(ch);
                       }).base(), s.end());
}

void trim(std::string &s) {
  right_trim(s);
  left_trim(s);
}

std::string left_trim_copy(std::string s) {
  left_trim(s);
  return s;
}

std::string right_trim_copy(std::string s) {
  right_trim(s);
  return s;
}

std::string trim_copy(std::string s) {
  trim(s);
  return s;
}

} // End namespace namespace embedonix::simplelibs::stringtools