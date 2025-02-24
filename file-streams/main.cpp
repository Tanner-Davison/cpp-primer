#include "../debug-class-example/DebugEx.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void process_input(std::istream &in, std::string &valp) {
  while (std::getline(in, valp)) {
    if (!valp.empty()) {
      std::cout << "\n" << valp << std::endl;
    }
  };
}

int main() {
  std::fstream inFile("./testing.txt");
  if (!inFile)
    throw std::runtime_error("No input file found");
  Debug io_db(false, true, false);
  std::string val;

  while (true) {
    auto old_state = inFile.rdstate();
    inFile.clear(inFile.rdstate() & ~inFile.failbit & ~inFile.badbit);

    process_input(inFile, val);

    if (!inFile.good()) {
      if ((inFile.rdstate() == std::ios::eofbit) | std::ios::failbit) {
        if (io_db.any()) {
          std::cerr << "- end of file -" << std::endl;
        }
      } else {
        if (io_db.any()) {
          std::cerr
              << "Failed to read input from std::cin. Expected type: ( INT )\n"
              << "\terror state: " << inFile.rdstate() << std::endl;
        }
      }
      break;
    }

    inFile.setstate(old_state);
  }

  return 0;
}
