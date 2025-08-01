#include <iostream>
#include <map>
#include <vector>

int main() {
  std::map<int, std::vector<std::string>> example_map;
  example_map[1] = {"initial"};
  auto map_it = example_map.begin();
  map_it->second =
      std::vector<std::string>{"this", "is", "my", "example", "string"};

  std::cout << "vector size: " << map_it->second.size() << std::endl;
  for (const auto &word : map_it->second) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  return 0;
}
