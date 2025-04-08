#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main() {
  std::vector<int> my_ints{1, 2, 3, 4, 5};
  std::vector<int> copy_ints{2, 4, 6, 8, 10};
  // std::copy with c arrays
  int my_int_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int my_copy[sizeof(my_int_arr) / sizeof(*my_int_arr)];
  auto ret = std::copy(std::begin(my_int_arr), std::end(my_int_arr), my_copy);
  // copy example
  auto it = std::back_inserter(my_ints);
  std::copy(begin(copy_ints), end(copy_ints), it);
  // copy can take in a destination which can also be an insert iterator like
  // back_inserter
  std::cout
      << "\n std::copy(beg, end, back_inserter || destination) vector --> "
      << std::endl;
  for (const auto num : my_ints) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  // std::replace()
  std::vector<int> my_nums{1, 2, 3, 4, 5};
  std::cout << "\nstd::replace(beg, end, 3, 0) --> " << std::endl;
  std::replace(begin(my_nums), end(my_nums), 3, 0);
  for (const auto &num : my_nums) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  // std::replace_copy()
  std::vector<int> my_nums_two{1, 2, 3, 4, 5};
  std::vector<int> dest_nums;
  auto it_dest = std::back_inserter(dest_nums);
  std::cout << "\nstd::replace_copy(beg, end, 3, 0) --> " << std::endl;
  // difference is i gave a back_inserter / destination to copy to.
  std::replace_copy(begin(my_nums_two), end(my_nums), it_dest, 3, 0);
  for (const auto &num : my_nums) {
    std::cout << num << ",";
  }
  std::cout << std::endl;

  return 0;
}
