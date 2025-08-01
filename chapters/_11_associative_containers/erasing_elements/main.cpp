// this solution includes C++ 20's abbreviated function templates
#include <iostream>
#include <map>
#include <vector>

void fill_map(auto &mapv, const auto &vec) {

  for (const auto &word : vec) {
    auto [it, success] = mapv.try_emplace(word, word.size());
    if (!success) {
      std::cout << "failed to emplace: '" << word << "' into mappped_str"
                << std::endl;
    } else {
      std::cout << "(" << it->second << "): " << it->first << std::endl;
    }
  }
}
int main() {
  std::map<std::string, int> mapped_str;
  const std::vector<std::string> list_one{"one",  "two", "three", "four",
                                          "five", "six", "seven", "eight",
                                          "nine", "ten"};
  fill_map(mapped_str, list_one);

  return 0;
}
