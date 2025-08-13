#include <iostream>
#include <map>
#include <string>
#include <utility>
int main() {
  std::map<size_t, std::map<std::string, size_t>> mapofmap;
  std::string str = "hello world";
  mapofmap[1][str] = str.size();

  std::cout << "=== NESTED MAP CONTENTS ===" << std::endl;
  std::cout << "Outer key: 1" << std::endl;
  std::cout << "Inner key: \"" << str << "\"" << std::endl;
  std::cout << "Value: " << str.size() << std::endl;
  std::cout << std::endl;

  // Direct access (chained find)
  auto target = mapofmap.find(1)->second.find(str);
  std::cout << "=== DIRECT ACCESS ===" << std::endl;
  std::cout << "Key: \"" << target->first << "\"" << std::endl;
  std::cout << "Value: " << target->second << std::endl;
  std::cout << std::endl;

  // Safer version with iterator checks
  std::cout << "=== SAFE ACCESS ===" << std::endl;
  auto outer_it = mapofmap.find(1);
  if (outer_it != mapofmap.end()) {
    std::cout << "Found outer key: " << outer_it->first << std::endl;

    auto inner_it = outer_it->second.find(str);
    if (inner_it != outer_it->second.end()) {
      std::cout << "Found inner key: \"" << inner_it->first << "\""
                << std::endl;
      std::cout << "Value: " << inner_it->second << std::endl;
    } else {
      std::cout << "Inner key not found!" << std::endl;
    }
  } else {
    std::cout << "Outer key not found!" << std::endl;
  }

  return 0;
}
