#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
  std::set<std::string> badWords{"shit", "fucking", "damnit", "tits",
                                 "damn", "fuck",    "cunt",   "bitch"};
  std::ostream_iterator<std::string> output(std::cout, " ");
  std::vector<std::string> input_container;
  std::string input;

  while (std::cin >> input && input != "1") {
    auto found = badWords.find(input);
    if (found == badWords.end()) {
      input_container.push_back(input);
    } else {
      input.assign(input.size(), '*');
      input_container.push_back(input);
    }
  }
  for (const auto &word : input_container) {
    output = word;
  }
  return 0;
}
