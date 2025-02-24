#include "../DebugEx.hpp"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

void printTime(std::ostream &out, std::string &file,
               std::runtime_error err = std::runtime_error("")) {
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  struct tm timeinfo;
  localtime_s(&timeinfo, &time);
  if (err.what() != std::string("")) {
    out << "ERROR!" << "\t" << std::put_time(&timeinfo, "%Y-%m-%d %I:%M %p")
        << "\n\tdescription: " << err.what() << " : " << file << "\n( END )\n"
        << "\n=========================\n\n";
  } else {
    out << "File: [" << file << "]\n"
        << "\tOpened :" << std::put_time(&timeinfo, "%Y-%m-%d %I:%M %p");
  }
}
void process_input(std::istream &in, std::string &valp) {
  while (std::getline(in, valp)) {
    if (!valp.empty()) {
      std::cout << "\n" << valp;
    }
  };
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
    printTime(out, filename, std::runtime_error("No input file found"));
  } else {
    printTime(out, filename);
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
          out << "Failed to Read input From " << filename << std::endl;
          std::cerr << "Failed to read input from std::ifstream \n"
                    << "\terror state: " << in_file.rdstate() << std::endl;
        }
      }
      break;
    }

    in_file.setstate(old_state);
  }
  if (in_file.is_open()) {
    in_file.close();
    out << "\n\tInput File Closed!" << "\n ( END )\n"
        << "=========================\n"
        << std::endl;
  }
  return 0;
}
