#include <iostream>
#include <iterator>
#include <vector>
int main() {

  // use reverse iterators to print a vector in reverse order?
  std::ostream_iterator<int> print(std::cout, ", ");
  std::vector<int> num_list{1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto rev_it = num_list.rbegin(); rev_it != num_list.rend(); ++rev_it) {
    print = *rev_it;
  }

  // now print the elements in reverse order using ordinary iterators
  auto start = num_list.begin();
  auto end = num_list.end();
  std::cout << "\n" << std::endl;
  while (end != start) {
    end--;
    print = *end;
  }
  return 0;
}
