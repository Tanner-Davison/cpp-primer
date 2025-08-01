// Associative containers - map and unordered_set
#include <iostream>
#include <map>
#include <unordered_set>

int main() {
  // Unordered set example
  std::unordered_set<int> my_set_example{3, 2, 1, 5, 6, 9, 7, 19, 8};

  std::cout << "Unordered set contents: ";
  for (const auto &num : my_set_example) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // Find element in set
  if (my_set_example.find(19) != my_set_example.end()) {
    std::cout << "Number " << *my_set_example.find(19)
              << " was found in the unordered set!" << std::endl;
  }

  // Map example
  std::map<char, int> map1{{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}};

  std::cout << "Map contents (key: value):" << std::endl;
  for (const auto &pair : map1) {
    std::cout << "  " << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}
