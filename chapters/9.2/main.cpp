#include <cctype>
#include <iostream>
#include <map>
#include <utility>
int main() {

  std::map<std::string, std::pair<std::string, int>> test;
  test["tanner"] = std::make_pair("pretty cool", 30);
  test["ben"] = std::make_pair("average", 20);
  for (const auto &item : test) {
    const auto &key = item.first;
    std::string tempname = key;
    tempname[0] = std::toupper(tempname[0]);
    const auto &the_pair = item.second;
    std::cout << "Map key (Name): " << tempname
              << "\n Pair.first (personality type): " << the_pair.first
              << " \nPair.second: " << the_pair.second << std::endl;
    ;
  }
  std::cout << std::endl;

  return 0;
}
