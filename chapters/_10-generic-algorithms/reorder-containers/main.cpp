#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  // empty vector
  std::vector<std::string> fill_me;
  std::string storytwo = "the quick red fox jumps over the slow red turtle";
  std::string word;
  std::stringstream ss(storytwo);
  // fill container
  while (ss >> word) {
    fill_me.emplace_back(word);
  }

  // std::sort duplicate words to be next to eachother with sort
  std::sort(begin(fill_me), end(fill_me));
  for (const auto &word : fill_me) {
    std::cout << word << "|";
  }
  std::cout << std::endl;

  // now make unique
  std::cout << "shifting duplicates to end with std::unique(beg, end)"
            << std::endl;
  auto end_unique = std::unique(fill_me.begin(), fill_me.end());
  for (const auto &word : fill_me) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  fill_me.erase(end_unique, end(fill_me));
  for (const auto &word : fill_me) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  return 0;
}
