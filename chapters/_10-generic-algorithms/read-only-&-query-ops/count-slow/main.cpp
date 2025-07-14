#include <algorithm>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
// latest
//
int main() {
  std::vector<int> nums{1, 2, 2, 2, 3, 4, 4, 4,  5, 5, 5, 6, 6,
                        6, 7, 8, 9, 3, 2, 1, 23, 3, 2, 1, 2, 4};
  std::vector<std::pair<int, int>> num_pairs;

  for (const auto &num : nums) {
    int count_per_num = count(begin(nums), end(nums), num);
    std::pair<int, int> curr_pair = std::make_pair(num, count_per_num);

    if (std::find(begin(num_pairs), end(num_pairs), curr_pair) !=
        num_pairs.end()) {
      continue;
    } else {
      num_pairs.emplace_back(std::make_pair(num, count_per_num));
    }
  }
  for (const auto &pair : num_pairs) {
    std::cout << pair.first << " apears " << pair.second << " times."
              << std::endl;
  }
  return 0;
};
