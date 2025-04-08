#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<std::string> my_strs{"one", "two", "three", "four", "five"};
  auto it = std::back_inserter(my_strs);
  *it = "six";
  *it = "seven";
  *it = "eight";
  // back inserter is used to add elements to the back of the container
  // assaigned by a reference to the container
  for (const auto &str : my_strs) {
    std::cout << str << ", ";
  }
  std::cout << std::endl;
  return 0;
}
