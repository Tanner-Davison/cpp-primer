#include <deque>
#include <iostream>
#include <list>
#include <vector>
int main() {
  std::list<std::string> my_strings{"String_1", "String_2", "String_3"};
  my_strings.pop_back();
  auto start = my_strings.begin();
  std::advance(
      start,
      1); // advances bidirectional containers which dont accept random access

  my_strings.erase(start);

  for (const auto &str : my_strings) {
    std::cout << str << std::endl;
  };

  return 0;
}
