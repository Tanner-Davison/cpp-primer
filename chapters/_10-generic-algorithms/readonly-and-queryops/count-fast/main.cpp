#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<int> nums{1, 2, 2, 17, 18, 2, 3, 4, 4,  4, 5, 5, 5, 6,
                        6, 6, 7, 8,  9,  3, 2, 1, 23, 3, 2, 1, 2, 4};

  std::unordered_map<int, int> count_map;

  // assigns each unique number once and increments its mapped value by one
  for (const auto &num : nums) {
    count_map[num]++;
  }
  for (const auto &[number, count] : count_map) {
    std::cout << number << " appears " << count << std::endl;
  }
  return 0;
};
