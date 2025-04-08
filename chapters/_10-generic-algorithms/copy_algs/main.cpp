#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> my_ints{1, 2, 3, 4, 5};
  std::vector<int> copy_ints{2, 4, 6, 8, 10};
  // copy example
  auto it = std::back_inserter(my_ints);
  std::copy(begin(copy_ints), end(copy_ints), it);
  // copy can take in a destination which can also be an insert iterator like
  // back_inserter
  for (const auto num : my_ints) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  return 0;
}
