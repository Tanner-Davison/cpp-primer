#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

int main() {
  std::list<int> number_list{1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> unique_nums;
  std::list<int> even_nums;

  std::vector<std::pair<const std::string, std::list<int> *>> all_lists{
      {"starting number list: ", &number_list},
      {"unique_copy even numbers back_inserter:", &unique_nums},
      {"unique_copy (even nums lamda predicate compare:", &even_nums}};

  std::unique_copy(number_list.begin(), number_list.end(),
                   std::back_inserter(unique_nums));
  std::unique_copy(number_list.begin(), number_list.end(),
                   std::back_inserter(even_nums),
                   [](int a, int b) { return (a % 2) == (b % 2); });

  // Loop through vector of lists
  for (const auto &list : all_lists) {
    std::cout << list.first << std::endl;
    for (const auto &num : *list.second) {
      std::cout << num << ", ";
    }
    std::cout << "\n" << std::endl;
  }

  std::cout << std::endl;
  return 0;
}
