#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>

bool check_size(const std::string &s, std::string::size_type sz) {
  return s.size() >= sz;
}

int main() {
  // auto newCallable = bind(callable, arg_list);

  auto check6 = std::bind(check_size, std::placeholders::_1, 6);

  std::string str = "Hello";
  bool b1 = check6(str);
  std::cout << "Hello is greater than 6 chars?" << std::boolalpha << b1
            << std::endl;
  return 0;
}
