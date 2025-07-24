#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  // implementation
  std::ostream_iterator<int> out_iter(std::cout, "\n");
  std::vector<int> random_nums{3, 5, 44, 2, 3, 1, 5, 9, 7, 8, 6};
  for (const auto &num : random_nums) {
    out_iter = num;
  }

  // better implementation
  std::ostream_iterator<int> out_iter_2(std::cout, ", ");
  std::ostream_iterator<int> out_iter_3(std::cout, ", ");
  std::ostream_iterator<int> out_iter_4(std::cout, ", ");
  std::copy(random_nums.begin(), random_nums.end(), out_iter_2);
  std::cout << std::endl;
  std::unique_copy(random_nums.begin(), random_nums.end(), out_iter_3);
  std::cout << std::endl;
  std::unique_copy(random_nums.begin(), random_nums.end(), out_iter_4,
                   [](int x, int y) { return x > y; });
  return 0;
}
