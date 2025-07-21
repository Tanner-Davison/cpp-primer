#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std::placeholders;

std::ostream &print(std::ostream &os, const std::string &str, char c) {
  return os << str << " " << c;
}
int main() {
  std::vector<std::string> words{"Sally", "is", "super", "nice", "to", "me"};

  std::for_each(words.begin(), words.end(),
                bind(print, ref(std::cout), _1, ' '));

  return 0;
}
