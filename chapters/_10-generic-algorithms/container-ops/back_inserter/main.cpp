#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  /* std::back_inserter() example */
  std::vector<std::string> my_strs{"one", "two", "three", "four", "five"};
  auto it = std::back_inserter(my_strs);
  *it = "six";
  *it = "seven";
  *it = "eight";
  /* - - - - - - - - - - - - - - - - - - */
  for (const auto &str : my_strs) {
    std::cout << str << ", ";
  }
  std::cout << "\n" << std::endl;
  ;
  /* using back_inserter as a way to fill containers */
  std::vector<int> my_ints;
  std::fill_n(std::back_inserter(my_ints), 10, 5);
  /*  - - - - - - - - - - - - - - - - - - - - - - -  */
  std::cout << "using back_inserter to fill my_ints {}" << std::endl;
  for (const auto &num : my_ints) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  std::cout << "\n=========Example using a lambda to back fill squared nums "
               "=========\n"
            << std::endl;

  std::vector<int> numbers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> squared_nums;

  std::transform(numbers.begin(), numbers.end(),
                 std::back_inserter(squared_nums),
                 [](int num) { return num * num; });
  for (const auto &val : squared_nums) {
    std::cout << val << ", ";
  }

  std::cout << std::endl;
  return 0;
}
