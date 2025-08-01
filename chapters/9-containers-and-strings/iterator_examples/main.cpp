// Iterator operations and traversal
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> days_of_week{"Monday",   "Tuesday", "Wednesday",
                                        "Thursday", "Friday",  "Saturday",
                                        "Sunday"};

  // Iterator-based traversal - weekdays only
  std::cout << "Weekdays (using iterators): ";
  auto it = days_of_week.begin();
  auto end = days_of_week.begin() + 5;
  while (it < end) {
    std::string comma = ((it + 1) == end) ? "" : ", ";
    std::cout << *it++ << comma;
  }
  std::cout << std::endl;

  // Iterator-based traversal - weekends only
  std::cout << "Weekends (using iterators): ";
  auto begin = (days_of_week.end() - 2);
  end = days_of_week.end();
  while (begin < end) {
    std::string comma = ((begin + 1) == end) ? "" : ", ";
    std::cout << *begin++ << comma;
  }
  std::cout << std::endl;

  return 0;
}
