#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isShorter(const std::string &str1, const std::string &str2) {
  return str1.size() < str2.size() ? true : false;
}
void elim_dups(std::vector<std::string> &strs) {
  std::sort(strs.begin(), strs.end());
  auto end_unique = std::unique(strs.begin(), strs.end());
  strs.erase(end_unique, strs.end());
}

int main() {
  std::vector<std::string> str_vec{"Susan", "Alan",  "Brad",   "Rebecca",
                                   "Troy",  "Roger", "Andrew", "Anthony"};

  elim_dups(str_vec);
  // Lambda usage HERE
  //  stable sort compares two elements at a time.
  std::stable_sort(str_vec.begin(), str_vec.end(),
                   [](const std::string &str_val, const std::string &str_val2) {
                     return str_val.size() < str_val2.size() ? true : false;
                   });
  for (const auto &word : str_vec) {
    std::cout << word << ", ";
  }
  std::cout << std::endl;
}
