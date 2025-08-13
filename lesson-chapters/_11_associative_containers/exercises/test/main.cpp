
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
  std::vector<std::string> str_vec{"One", "Two", "Three", "Four", "Five"};
  std::set<std::string> ms_str;
  // std::copy(str_vec.begin(), str_vec.end(),
  //           std::inserter(ms_str, ms_str.end()));

  std::copy(ms_str.begin(), ms_str.end(), std::back_inserter(str_vec));

  auto it = ms_str.cbegin();
  while (it != ms_str.cend()) {
    std::cout << *it << std::endl;
    ++it;
  }
  return 0;
}
