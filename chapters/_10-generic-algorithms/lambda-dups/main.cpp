
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Lambdas syntax [capture list](parameter list) -> return type {function body};

bool isShorter(const std::string &str1, const std::string &str2) {
  return str1.size() < str2.size() ? true : false;
}
void elim_dups(std::vector<std::string> &strs) {
  std::sort(strs.begin(), strs.end());
  auto end_unique = std::unique(strs.begin(), strs.end());
  strs.erase(end_unique, strs.end());
}
void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  elim_dups(words);
  stable_sort(begin(words), end(words), isShorter);
};

int main() {
  std::vector<std::string> str_vec{"Susan", "Alan",  "Brad",   "Rebecca",
                                   "Troy",  "Roger", "Andrew", "Anthony"};

  elim_dups(str_vec);
  std::stable_sort(str_vec.begin(), str_vec.end(), isShorter);
  for (const auto &word : str_vec) {
    std::cout << word << ", ";
  }

  std::cout << std::endl;
  return 0;
}
