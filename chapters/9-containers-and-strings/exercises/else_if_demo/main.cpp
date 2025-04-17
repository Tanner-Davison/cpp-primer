#include <cassert>
#include <iostream>
#include <list>
#include <ranges>
#include <vector>
// demo on else if using preprocessor macros
int main() {
  auto head = std::list{1, 2, 3, 4};
  const auto tail = std::vector{-5, -6, -7};
#ifdef __cpp_lib_containers_ranges
  head.append_range(tail);
#else
  head.insert(head.end(), tail.cbegin(), tail.cend());
#endif
  assert((head == std::list{1, 2, 3, 4, -5, -6, -7}));
  for (const auto &num : head) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
}
