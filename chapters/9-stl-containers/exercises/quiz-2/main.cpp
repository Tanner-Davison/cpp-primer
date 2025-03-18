#include <cassert>
#include <iostream>
#include <list>
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

// explain the difference between a vector's capacity and its size

//    Answer:
//    A vectors capacity is how much actual memory is allocated to the
//    container not how many elements their are.
//    size is the number of element count of actual items that are in said
//    container could be less than the capacity but never will be more.
