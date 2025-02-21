#include "C.hpp"
#include "NoDefault.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<Tracker> vec(10);
  for (auto &n : vec) {
    std::cout << n.get_id() << std::endl;
  }
  return 0;
}
