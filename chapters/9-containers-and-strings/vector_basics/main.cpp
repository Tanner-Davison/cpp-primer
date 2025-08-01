// Sequential Containers - vectors, deques, lists
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  // Vector basics
  std::vector<std::string> days_of_week{"Monday",   "Tuesday", "Wednesday",
                                        "Thursday", "Friday",  "Saturday",
                                        "Sunday"};

  // Vector construction from range
  std::vector<std::string> c(days_of_week.begin() + 2, days_of_week.end() - 3);

  std::vector<int> nums{3, 4, 5, 2, 1, 6, 8, 7};

  // List containing deques
  std::list<std::deque<int>> my_list{{1, 3, 4, 6, 5, 9, 7, 8},
                                     {3, 2, 4, 1, 5, 6}};

  // Sort each deque in the list
  for (auto &dq : my_list) {
    std::sort(dq.begin(), dq.end());
  }

  // Sort vector in descending order
  std::sort(nums.begin(), nums.end(), std::greater<int>());

  // Display results
  std::cout << "Mid week days: ";
  for (const auto &s : c) {
    std::cout << s << " ";
  }
  std::cout << std::endl;

  std::cout << "Sorted nums: ";
  for (const auto &num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "List of sorted deques:\n";
  for (const auto &dq : my_list) {
    for (const auto &num : dq) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
