#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::string word;
  int num;
  std::vector<std::pair<std::string, int>> str_int_pairs;

  while (std::cin >> word >> num && word != "z") {
    str_int_pairs.emplace_back(std::make_pair(word, num));
  }
  if (!str_int_pairs.empty()) {
    for (const auto &[word, num] : str_int_pairs) {
      std::cout << " number: " << num << " " << word << "\n";
    }
  }
  return 0;
}
