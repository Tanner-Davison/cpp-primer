#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool fiveOrMore(const std::string &str1) { return str1.size() >= 5; }

int main() {
  std::vector<std::string> str_vec{"Susan", "Alan",  "Brad",   "Rebecca",
                                   "Troy",  "Roger", "Andrew", "Anthony"};

  auto el = std::partition(str_vec.begin(), str_vec.end(), fiveOrMore);

  std::cout << "These words contain five characters or more\n" << std::endl;
  for (auto it = str_vec.begin(); it != el; ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
}
