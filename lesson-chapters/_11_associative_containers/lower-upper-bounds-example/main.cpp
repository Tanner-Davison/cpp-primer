
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

int main() {
  std::multimap<char, std::string> map_str;
  std::vector<std::string> str_vec{"Tom", "Brad", "Rob",
                                   "Tim", "Alan", "Jessica"};
  for (const auto &str : str_vec) {
    map_str.insert({*str.begin(), str});
  }

  try {
    auto lower = map_str.lower_bound('T');
    auto upper = map_str.upper_bound('T');

    while (lower != upper) {
      std::cout << lower->second << std::endl;
      ++lower;
    }
  } catch (std::out_of_range &e) {
    std::cout << e.what() << " out of range check!" << std::endl;
  }

  auto it = map_str.cbegin();
  while (it != map_str.cend()) {
    std::cout << " " << it->first << " : " << it->second << std::endl;
    ++it;
  }

  return 0;
}
