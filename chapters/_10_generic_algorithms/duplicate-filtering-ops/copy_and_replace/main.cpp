#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  // Initialize vectors
  std::vector<int> my_ints{1, 2, 3, 4, 5};
  std::vector<int> copy_ints{2, 4, 6, 8, 10};

  // std::copy with C arrays
  int my_int_arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int my_copy[sizeof(my_int_arr) / sizeof(*my_int_arr)];
  std::copy(std::begin(my_int_arr), std::end(my_int_arr), my_copy);

  // std::copy with back_inserter
  std::copy(std::begin(copy_ints), std::end(copy_ints),
            std::back_inserter(my_ints));

  // Display results of copy
  std::cout << "\nstd::copy(beg, end, back_inserter || destination) vector --> "
            << std::endl;
  for (const auto &num : my_ints) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;

  // std::replace example
  std::vector<int> my_nums{1, 2, 3, 4, 5};
  std::cout << "\nstd::replace(beg, end, 3, 0) --> " << std::endl;
  std::replace(std::begin(my_nums), std::end(my_nums), 3, 0);
  for (const auto &num : my_nums) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;

  // std::replace_copy example
  std::vector<int> my_nums_two{1, 2, 3, 4, 5};
  std::vector<int> dest_nums;

  std::cout << "\nstd::replace_copy(beg, end, dest, 3, 0) --> " << std::endl;
  std::replace_copy(std::begin(my_nums_two), std::end(my_nums_two),
                    std::back_inserter(dest_nums), 3, 0);

  for (const auto &num : dest_nums) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;

  return 0;
}
