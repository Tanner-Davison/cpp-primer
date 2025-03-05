// Chapter 9 Sequential Containers
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::vector<std::string> days_of_week{"Monday",   "Tuesday", "Wednesday",
                                        "Thursday", "Friday",  "Saturday",
                                        "Sunday"};
  std::vector<int> nums{3, 4, 5, 2, 1, 6, 8, 7};
  std::list<std::deque<int>> my_list{{1, 3, 4, 6, 5, 9, 7, 8},
                                     {3, 2, 4, 1, 5, 6}};
  for (auto &dq : my_list) {
    std::sort(dq.begin(), dq.end());
  }

  std::sort(days_of_week.begin(), days_of_week.end());
  std::sort(nums.begin(), nums.end(), std::greater<int>());
  std::cout << "Weekdays (vector): " << "\n\t";

  // looping using iterator less conventional
  auto it = days_of_week.begin();
  auto end = days_of_week.end();
  while (it < end) {
    std::cout << *it++ << ", ";
  }

  std::cout << "\n\nNums (vector): \t";
  for (auto &num : nums) {
    std::cout << num << ", ";
  }
  std::cout << "\n\nDequed List of Nums:\n\t";

  for (auto &dq : my_list) {
    for (auto &num : dq) {
      std::cout << num << ", ";
    }
    std::cout << "\n\t";
  }
  return 0;
}
