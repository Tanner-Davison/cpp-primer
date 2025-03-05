#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::vector<std::string> my_list{"Stephanie", "Jamie",  "Monty",    "Rebecca",
                                   "James",     "Arthur", "Zacharias"};
  std::vector<int> nums{3, 4, 5, 2, 1, 6, 8, 7};

  std::sort(my_list.begin(), my_list.end(), std::greater<std::string>());
  std::sort(nums.begin(), nums.end(), std::greater<int>());

  for (auto &name : my_list) {
    std::cout << name << ", ";
  }
  std::cout << std::endl;
  for (auto &num : nums) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  return 0;
}
