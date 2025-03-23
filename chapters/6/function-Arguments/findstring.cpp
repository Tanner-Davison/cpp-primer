#include "./Headers/FindString.hpp"
// occurs keeps track of occurence count;
std::string::size_type find_char(const std::string &str, char c,
                                 std::string::size_type &occurs) {
  auto ret = str.size();
  for (decltype(ret) i = 0; i != str.size(); ++i) {
    if (str[i] == c) {
      if (ret == str.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}
