#include <iostream>
#include <map>
#include <sstream>
#include <string>
int main() {
  std::string line;

  std::map<std::string, int> word_count;
  while (std::getline(std::cin, line) && !line.empty()) {
    std::stringstream ss(line);
    std::string key;
    while (ss >> key) {
      word_count[key]++;
    }
  }

  auto word_it = word_count.begin();
  while (word_it != word_count.end()) {
    std::cout << "key " << word_it->first << " occurs: " << word_it->second
              << std::endl;
    ++word_it;
  }

  return 0;
}
