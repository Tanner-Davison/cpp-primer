#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::list<int> my_strings{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto erased = std::erase_if(my_strings, [](int num) { return num % 2; });
  std::cout << erased << std::endl;
  return 0;
}
