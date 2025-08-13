#include <iostream>
#include <iterator>

// an example of using reverse iterators to
int main() {
  std::ostream_iterator<std::string> print_after_last_comma(std::cout, "\n");
  std::ostream_iterator<std::string> print_before_first_comma(std::cout, "\n");
  std::string line{"this is my,comma,seperated,list"};

  auto rcomma = std::find(line.rbegin(), line.rend(), ',');
  auto bcomma = std::find(line.cbegin(), line.cend(), ',');

  print_before_first_comma = std::string(line.cbegin(), bcomma);
  print_after_last_comma = std::string(rcomma.base(), line.end());

  return 0;
}
