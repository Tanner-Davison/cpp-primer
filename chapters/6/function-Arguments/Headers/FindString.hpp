// FIND STRING HEADER
#pragma once
#include <string>

std::string::size_type find_char(const std::string &str, char c,
                                 std::string::size_type &occurs) {
  auto ret = str.size();
  for (decltype(ret) i = 0; i != str.size(); ++i) {
    if (str[i] == c) {
      if (ret == str.size()) { // clever way to only read first iteration.
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}
