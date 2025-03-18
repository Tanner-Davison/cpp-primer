#include <cctype>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
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
  std::cout << "\n\n" << std::endl;

  std::vector<std::string> test_names{"Sarah", "Andrew", "Kate", "Perry"};
  std::vector<std::string> test_swap{"Tanner", "Trump", "ELON", "MUSK"};
  std::vector<std::string> empty_cont;
  std::initializer_list<std::string> il{"tanner", "worlds", "without",
                                        "number"};
  auto beg = test_swap.begin() + 1;
  auto end = test_swap.end() - 1;

  test_names.assign(beg, end);
  std::swap(test_names, empty_cont);
  std::swap(test_swap, empty_cont);

  for (auto &name : empty_cont) {
    std::cout << name << ", ";
  }
  std::cout << "\n\n" << std::endl;
  return 0;
}
