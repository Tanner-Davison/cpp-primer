#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elim_dups(std::vector<std::string> &strs) {
  std::sort(strs.begin(), strs.end());
  auto end_unique = std::unique(strs.begin(), strs.end());
  strs.erase(end_unique, strs.end());
}
int main() {
  std::vector<std::string> str_vec{"Sally", "Sally", "Tom",  "Tanner",
                                   "Roger", "Jared", "Jared"};
  elim_dups(str_vec);
  for (const auto &word : str_vec) {
    std::cout << word << ", ";
  }
  std::cout << std::endl;
}
