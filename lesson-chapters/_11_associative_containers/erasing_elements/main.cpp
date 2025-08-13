/*
 * Copyright (c) 2025 Tanner Davison. All Rights Reserved.
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

void fill_map(auto &mapv, const auto &vec) {
  int success_count = 0;
  for (const auto &word : vec) {
    auto [it, success] = mapv.try_emplace(word, word.size());
    if (!success) {
      std::cout << "[!error] Failed to add " << word << " element to map!"
                << std::endl;
    } else {
      ++success_count;
    }
  }
  std::cout << "[fill_map]: \n\tSuccessfully filled map with: " << success_count
            << " elements!\n"
            << std::endl;
}

void remove_words_from_map(auto &map) {
  const static std::set<std::string> remove_list{"eight", "nine"};
  std::cout << "[remove_words_from_map]:" << std::endl;

  for (const auto &word : remove_list) {
    auto it = map.erase(word);
    if (it > 0) {
      std::cout << "\terased: ['" << word << "'] from map." << std::endl;
    } else {
      std::cout << word << " not found" << std::endl;
    }
  }

  std::cout << "\n====Map's Result=========== \n" << std::endl;
  for (const auto &[key, val] : map) {
    std::cout << "   [" << val << "] chars in word: '" << key << "'"
              << std::endl;
  }
  std::cout << "\n==========================" << std::endl;
}

int main() {
  std::map<std::string, int> mapped_str;
  const std::vector<std::string> list_one{"one",  "two", "three", "four",
                                          "five", "six", "seven", "eight",
                                          "nine", "ten"};
  fill_map(mapped_str, list_one);
  remove_words_from_map(mapped_str);

  return 0;
}
