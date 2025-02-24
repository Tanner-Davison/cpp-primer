#include "../debug-class-example/DebugEx.hpp"
#include <iostream>

void process_input(std::istream &in, int &valp) {
  in >> valp;
  std::cout << "value: " << valp << std::endl;
}

int main() {
  Debug io_db(false, true, false);
  int val;

  while (true) {
    auto old_state = std::cin.rdstate();
    std::cin.clear();

    process_input(std::cin, val);

    if (!std::cin.good()) {
      if (io_db.any()) {
        std::cerr
            << "Failed to read input from std::cin. Expected type: ( INT )\n"
            << "error state: " << std::cin.rdstate() << std::endl;
        break;
      }
    }

    std::cin.setstate(old_state);
  }

  return 0;
}
