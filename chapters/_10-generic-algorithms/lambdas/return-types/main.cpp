#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> numbers{0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
  std::vector<int> absolute_values;

  std::transform(numbers.begin(), numbers.end(),
                 std::back_inserter(absolute_values), [](int i) -> int {
                   if (i < 0)
                     return -i;
                   else
                     return i;
                 });
  for (const auto &num : absolute_values) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  return 0;
}
