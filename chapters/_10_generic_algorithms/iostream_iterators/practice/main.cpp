#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

int main() {
  std::fstream file("input.txt");
  if (!file) {
    throw std::runtime_error("No file found");
  }
  std::vector<std::string> container;

  std::copy(std::istream_iterator<std::string>(file),
            std::istream_iterator<std::string>(),
            std::back_inserter(container));

  std::sort(container.begin(), container.end());

  std::unique_copy(container.begin(), container.end(),
                   std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
