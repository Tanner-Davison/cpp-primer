#include "../DebugEx.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void process_input(std::istream &in, std::string &valp) {
  while (std::getline(in, valp)) {
    if (!valp.empty()) {
      std::cout << std::unitbuf;
      std::cout << "\n" << valp;
    }
  };
  std::cout << std::nounitbuf;
  std::cout << std::endl;
}

int main() {
  Debug io_db(false, true, false);
  std::string filename = "./testing.txt";
  std::string report = "./log.txt";
  std::ifstream inFile(filename);
  std::ofstream out("log.txt", std::ios::app);
  if (!inFile) {
    if (io_db.any()) {
      std::cerr << "No input file has been found with file name: " << filename
                << std::endl;
    }
    throw std::runtime_error("No input file found");
  } else {
    std::cout << "Input File is open!" << std::endl;
  }

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
  if (inFile.is_open()) {
    inFile.close();
    std::cout << "Input File Closed!" << std::endl;
  }
  return 0;
}
