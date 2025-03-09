// FIND STRING CPP
#include "./Headers/FindString.hpp"
using std::string;

std::string::size_type find_char(const string &s, char c,
                                 string::size_type &occurs) {
  auto ret = s.size();
  for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
      if (ret == s.size()) { // clever way to only read first iteration.
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}
