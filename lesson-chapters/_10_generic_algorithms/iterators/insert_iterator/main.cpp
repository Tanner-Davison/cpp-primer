/*
 * ╔═══════════════════════════════════════════════════════════════════════════════╗
 * ║                           Insert Iterator Types ║
 * ╠═══════════════════════════════════════════════════════════════════════════════╣
 * ║ ║ ║  Three types of insert iterators for adding elements to containers: ║
 * ║ ║ ║  📌 back_inserter ║ ║     └─► Uses push_back() to add elements at the
 * end                          ║ ║     └─► Example: std::back_inserter(vec) ║
 * ║ ║ ║  📌 front_inserter ║ ║     └─► Uses push_front() to add elements at the
 * beginning                   ║ ║     └─► Example: std::front_inserter(deque) ║
 * ║ ║ ║  📌 inserter ║ ║     └─► Uses insert(iterator, value) to add elements
 * at specific position    ║ ║     └─► Takes two parameters: container and
 * iterator position                 ║ ║     └─► Example: std::inserter(set,
 * set.begin())                             ║ ║ ║
 * ╚═══════════════════════════════════════════════════════════════════════════════╝
 */

#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

int main() {
  std::list<int> lst{5, 10, 15, 20};
  std::list<int> lst_1, lst_2, lst_3;

  std::vector<std::pair<std::string, const std::list<int> *>> all_lists{
      {"Starting List", &lst},
      {"After front_inserter()", &lst_1},
      {"After inserter(lst_2, lst_2.begin())", &lst_2},
      {"After back_inserter(lst_3)", &lst_3}};

  std::copy(lst.begin(), lst.end(), std::front_inserter(lst_1));
  std::copy(lst.begin(), lst.end(), std::inserter(lst_2, lst_2.begin()));
  std::copy(lst.begin(), lst.end(), std::back_inserter(lst_3));

  for (const auto &list : all_lists) {
    std::cout << "\n" << list.first << std::endl;

    for (const auto &num : *list.second) {
      std::cout << num << ", ";
    }
    std::cout << std::endl;
  };
  std::cout << std::endl;
  return 0;
}
