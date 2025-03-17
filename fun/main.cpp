#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> ivec;
  std::list<int> ilist;
  for (int i = 0; i < 11; ++i) {
    ivec.push_back(ia[i]);
    ilist.push_back(ia[i]);
  }
  auto vecIt = ivec.begin();
  auto listIt = ilist.begin();
  while (vecIt != ivec.end()) {
    if (*vecIt % 2) {
      vecIt = ivec.erase(vecIt);
    } else {
      ++vecIt;
    }
  }
  while (listIt != ilist.end()) {
    if (*listIt % 2 == 0) {
      listIt = ilist.erase(listIt);
    } else {
      ++listIt;
    }
  }

  std::cout << "Evens: ";
  for (const auto &num : ivec) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  std::cout << "Odds: ";
  for (const auto &num : ilist) {
    std::cout << num << ",";
  }
  std::cout << std::endl;
  std::list<int> my_strings{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto erased = std::erase_if(my_strings, [](int num) { return num % 2; });

  std::cout << erased << " numbers removed from (erase_if)" << std::endl;
  return 0;
}
