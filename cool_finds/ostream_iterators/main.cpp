#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::ostream_iterator<int> intWriter(std::cout, "\n");
  *intWriter = 42;
  intWriter++;
  *intWriter = 100;

  return 0;
}
