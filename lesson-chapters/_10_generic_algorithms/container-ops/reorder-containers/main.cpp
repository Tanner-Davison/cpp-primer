#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  // Start with an empty vector to hold words
  std::vector<std::string> words;
  std::string text = "the quick red fox jumps over the slow red turtle";

  // Parse the string into individual words
  std::string word;
  std::stringstream ss(text);
  while (ss >> word) {
    words.emplace_back(word);
  }

  std::cout << "Original words: ";
  for (const auto &w : words) {
    std::cout << w << " ";
  }
  std::cout << "\n\n";

  // Step 1: Sort to group duplicates together
  std::sort(words.begin(), words.end());

  std::cout << "After sorting: ";
  for (const auto &w : words) {
    std::cout << w << " ";
  }
  std::cout << "\n\n";

  // Step 2: Move duplicates to the end, get iterator to new end
  std::cout << "After std::unique (duplicates moved to end):\n";
  auto new_end = std::unique(words.begin(), words.end());

  // Show the full vector (including duplicates at end)
  std::cout << "Full vector: ";
  for (const auto &w : words) {
    std::cout << w << " ";
  }
  std::cout << "\n";

  // Step 3: Erase the duplicate elements
  words.erase(new_end, words.end());

  std::cout << "Final unique words: ";
  for (const auto &w : words) {
    std::cout << w << " ";
  }
  std::cout << "\n";

  return 0;
}
