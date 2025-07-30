#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::map<std::string, std::vector<int>>
buildWordMap(const std::string &filename) {
  std::map<std::string, std::vector<int>> word_to_lines;
  std::ifstream file(filename);
  std::string line;
  int line_number = 1;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string word;

    // Extract each word from the line
    while (iss >> word) {
      // Remove punctuation (optional)
      word.erase(std::remove_if(word.begin(), word.end(), ::ispunct),
                 word.end());

      // Convert to lowercase (optional)
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);

      if (!word.empty()) {
        word_to_lines[word].push_back(line_number);
      }
    }
    line_number++;
  }

  return word_to_lines;
}

int main() {
  auto word_map = buildWordMap("input.txt");

  // Print results
  for (const auto &[word, lines] : word_map) {
    std::cout << "'" << word << "' appears on lines: ";
    for (size_t i = 0; i < lines.size(); ++i) {
      std::cout << lines[i];
      if (i < lines.size() - 1)
        std::cout << ", ";
    }
    std::cout << std::endl;
  }

  return 0;
}
