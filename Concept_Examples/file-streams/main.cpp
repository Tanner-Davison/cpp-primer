// MAKE SURE TO SET THIS FILE AS YOUR PWD WHEN COMPILING
#include "../Debug-example/DebugEx.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
// testing
Debug io_db(false, true, false);

void process_input(std::istream &in, std::vector<std::string> &lines_container,
                   const std::string &filename) {
  if (::io_db.any()) {
    std::cerr << "\nFilename: [" << filename << " ]\n\tFILE START-----------> "
              << std::endl;
  }
  std::string line;
  while (getline(in, line)) {
    if (!line.empty()) {
      lines_container.push_back(line);
      std::cout << "\n" << line;
    }
  }
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> all_lines;
  std::string test = "./text-files/input_file_1.txt",
              test2 = "./text-files/input_file_2.txt",
              file_operation_logs = "./text-files/file-error-logger.txt";

  const std::string err_msg = "Failed to open file";
  std::ifstream file1(test), file2(test2);
  std::ofstream out(file_operation_logs);
  std::vector<std::pair<std::ifstream &, std::string>> file_pairs = {
      {file1, test}, {file2, test2}};

  for (auto &[file, name] : file_pairs) {
    io_db.file_check(file, name, std::runtime_error(err_msg), out);
    while (true) {
      auto old_state = file.rdstate();
      file.clear(file.rdstate() & ~file.failbit & ~file.badbit);
      process_input(file, all_lines, name);
      if (!file.good()) {
        if (file.rdstate() == (std::ios::eofbit | std::ios::failbit)) {
          if (io_db.any()) {
            std::cerr << "\n <---------- END OF FILE \n" << std::endl;
          }
        } else {
          if (io_db.any()) {
            const std::string err_msg("Failed reading input from: ");
            io_db.log_error(out, name, std::runtime_error(err_msg));
            std::cerr << err_msg << "\terror state: " << file.rdstate()
                      << std::endl;
          }
        }
        break;
      }
      file.setstate(old_state);
    }
    if (file.is_open()) {
      file.close();
      io_db.log_message(out, "Input File Closed!", name);
    }
  }
  return 0;
}
