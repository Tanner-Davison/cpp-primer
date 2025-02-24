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

  std::ifstream in_file(filename);
  std::ofstream out("log.txt", std::ios::app);
  std::string line;

  if (!in_file) {
    if (io_db.any()) {
      std::cerr << "No input file has been found with file name: " << filename
                << std::endl;
    }
    throw std::runtime_error("No input file found");
  } else {
    std::cout << "Input File is open!" << std::endl;
  }

  while (true) {
    auto old_state = in_file.rdstate();
    in_file.clear(in_file.rdstate() & ~in_file.failbit & ~in_file.badbit);

    process_input(in_file, line);

    if (!in_file.good()) {
      if ((in_file.rdstate() == std::ios::eofbit) | std::ios::failbit) {
        if (io_db.any()) {
          std::cerr << "- end of file -" << std::endl;
        }
      } else {
        if (io_db.any()) {
          std::cerr
              << "Failed to read input from std::cin. Expected type: ( INT )\n"
              << "\terror state: " << in_file.rdstate() << std::endl;
        }
      }
      break;
    }

    in_file.setstate(old_state);
  }
  if (in_file.is_open()) {
    in_file.close();
    std::cout << "Input File Closed!" << std::endl;
  }
  return 0;
}
