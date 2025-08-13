#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// list the 5 iterator categories:
//
// 1.Input Iter
// 2.Output Iter
// 3.Forward Iter
// 4.Bi-directional Iter
// 5.Random_access Iter
//
int main() {

  // use reverse iterators to print a vector in reverse order?

  std::ostream_iterator<int> print(std::cout, ", ");
  std::vector<int> num_vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "\n\nprint in reverse from a vector using reverse iterators"
            << std::endl;
  for (auto rev_it = num_vec.rbegin(); rev_it != num_vec.rend(); ++rev_it) {
    print = *rev_it;
  }

  // now print the elements in reverse order using ordinary iterators

  auto start = num_vec.begin();
  auto end = num_vec.end();
  std::cout << "\n\nprint a vector  in reverse using ordinary iterators:"
            << std::endl;
  while (end != start) {
    end--;
    print = *end;
  }

  // given a vector that has ten elements, copy the elements from positions 3 -
  // 7 in reverse order to a list

  std::list<int> num_list;
  auto revStart = num_vec.crbegin() + 3;
  auto revEnd = num_vec.crend() - 2;
  std::copy(revStart, revEnd, std::back_inserter(num_list));
  std::cout
      << "\n\ncopy elements from position 3-7 into a list in reverse order"
      << std::endl;
  for (const auto &num : num_list) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  return 0;
}
