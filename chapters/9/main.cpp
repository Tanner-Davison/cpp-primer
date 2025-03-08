// Chapter 9 Sequential Containers
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

template <typename T>
typename std::vector<T>::iterator find_(typename std::vector<T>::iterator begin,
                                        typename std::vector<T>::iterator end,
                                        const T &target) {
  return std::find(begin, end, target);
}

int main() {
  // Vector
  std::vector<std::string> days_of_week{"Monday",   "Tuesday", "Wednesday",
                                        "Thursday", "Friday",  "Saturday",
                                        "Sunday"};
  std::vector<std::string> lookup_lib{"hello", "Tom", "Ransom", "Ben",
                                      "Tougher"};
  std::vector<std::string> c(days_of_week.begin() + 2, days_of_week.end() - 3);
  // Set
  std::unordered_set<int> my_set_example{3, 2, 1, 5, 6, 9, 7, 19, 8};
  std::cout << "'Set' Example\n\t";
  for (auto num : my_set_example) {
    std::cout << num << ", ";
  }
  if (my_set_example.find(19) != my_set_example.end()) {
    std::cout << "\nNumber " << *my_set_example.find(19)
              << " was found in the unordered set!" << std::endl;
  }
  std::cout << std::endl;

  // MAP
  std::map<char, int> map1{{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}};
  std::cout << "Map Testing:\n\t " << std::endl;
  for (auto &pair : map1) {
    std::cout << pair.first << ", " << pair.second << std::endl;
  }
  std::cout << std::endl;

  std::vector<int> nums{3, 4, 5, 2, 1, 6, 8, 7};

  // List
  std::list<std::deque<int>> my_list{{1, 3, 4, 6, 5, 9, 7, 8},
                                     {3, 2, 4, 1, 5, 6}};
  for (auto &dq : my_list) {
    std::sort(dq.begin(), dq.end());
  }

  std::sort(nums.begin(), nums.end(), std::greater<int>());
  std::cout << "Weekdays (vector): " << "\n\t";

  // looping using iterator only WEEKDAYS
  auto it = days_of_week.begin();
  auto end = days_of_week.begin() + 5;
  while (it < end) {
    std::string comma = ((it + 1) == end) ? "" : ", ";
    std::cout << *it++ << comma;
  }
  // only weekends
  std::cout << "\nWeekend: \n\t";
  auto begin = (days_of_week.end() - 2);
  end = days_of_week.end();

  while (begin < end) {
    std::string comma = ((begin + 1) == end) ? "" : ", ";
    std::cout << *begin++ << comma;
  }
  // Mid week
  std::cout << "\nMID WEEK\n\t";
  for (auto &s : c) {
    std::cout << s << ", ";
  }
  std::cout << std::endl;

  // Nums Vector
  std::cout << "\n\nNums (vector): \t";
  for (auto &num : nums) {
    std::cout << num << ", ";
  }
  auto numTarget = find_<int>(nums.begin(), nums.end(), 3);
  if (numTarget == nums.end()) {
    std::cout << "\nTarget Number Not Found" << std::endl;
  } else {
    std::cout << "\nTarget: [" << *numTarget << "] found!" << std::endl;
  }
  std::cout << "\n\nDequed List of Nums:\n\t";

  // std::list of std::deques reading
  for (auto &dq : my_list) {
    for (auto &num : dq) {
      std::cout << num << ", ";
    }
    std::cout << "\n\t";
  }

  // using iterators and std::find() to find target match
  auto l_begin = lookup_lib.begin();
  auto l_end = lookup_lib.end();
  auto result = find_<std::string>(l_begin, l_end, "Ben");
  if (result == l_end) {
    std::cout << "\nTarget not found." << std::endl;
  } else {
    std::cout << "\nTarget: [" << *result << "] Found!" << std::endl;
  }
  return 0;
}
