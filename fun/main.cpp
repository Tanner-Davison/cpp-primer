#include <deque>
#include <iostream>
#include <list>
#include <vector>

void remove_odds(std::list<int> &strs) {
  if (!strs.empty()) {
    auto it = strs.begin();
    while (it != strs.end()) {
      if (*it % 2) {
        it = strs.erase(it);
      } else {
        ++it;
      }
    }
  }
  for (const auto &num : strs) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}
int main() {
  std::list<int> my_strings{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  remove_odds(my_strings);
  return 0;
}
