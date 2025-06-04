#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  // start with an empty vector
  std::vector<std::string> container_to_fill;
  std::string storyTwo = "the quick red fox jumps over the slow red turtle";
  std::string word;
  std::stringstream ss(storyTwo);
  // fill vector Container
  while (ss >> word) {
    container_to_fill.emplace_back(word);
  }

  // std::sort duplicate words to be next to eachother with sort
  std::sort(begin(container_to_fill), end(container_to_fill));
  for (const auto &word : container_to_fill) {
    std::cout << word << "|";
  }
  std::cout << std::endl;

  // now make unique
  std::cout << "shifting duplicates to end with std::unique(beg, end)"
            << std::endl;
  auto end_unique =
      std::unique(container_to_fill.begin(), container_to_fill.end());
  for (const auto &word : container_to_fill) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  container_to_fill.erase(end_unique, end(container_to_fill));
  for (const auto &word : container_to_fill) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  return 0;
}
