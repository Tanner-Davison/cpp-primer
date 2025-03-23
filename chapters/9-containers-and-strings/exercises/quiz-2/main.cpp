#include <cassert>
#include <list>
#include <ranges>
#include <vector>

int main() {
  auto head = std::list{1, 2, 3, 4};
  const auto tail = std::vector{-5, -6, -7};
#ifdef __cpp_lib_containers_ranges
  head.append_range(tail);
#else
  head.insert(head.end(), tail.cbegin(), tail.cend());
#endif
  assert((head == std::list{1, 2, 3, 4, -5, -6, -7}));
}
