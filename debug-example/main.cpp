#include "../DebugEx.hpp"
#include <conio.h>
#include <cstring>
#include <fstream>
#include <iostream>

constexpr char ESC_KEY = 27;
// fixed
//
bool writeToFile(const std::string &filename, const Debug &debug) {
  std::ofstream file(filename, std::ios::app);
  std::string buffer;

  if (!file.is_open()) {
    if (debug.any()) {
      std::cerr << "[DEBUG] Failed to open file" << std::endl;
    }
    return false;
  }

  try {
    while (true) {
      if (_kbhit()) {
        char ch = _getch();

        if (ch == ESC_KEY)
          break;

        if (ch == '\r' || ch == 13) {
          if (debug.any()) {
            std::cerr << "[DEBUG] Return detected" << std::endl;
          }
          file << buffer << '\n';
          buffer.clear();
          std::cout << '\n';
          continue;
        }

        if (ch == '\b' || ch == 8) {
          if (!buffer.empty()) {
            buffer.pop_back();
            std::cout << "\b \b";
          }
          continue;
        }
        buffer += ch;
        std::cout << ch;
      }
    }

    if (!buffer.empty()) {
      file << buffer;
    }

  } catch (const std::exception &e) {
    if (debug.any()) {
      std::cerr << "[DEBUG] Write failed: " << e.what() << std::endl;
    }
    file.close();
    return false;
  }

  file.close();
  return true;
}
int main() {
  Debug io_sub(false, false, false);
  constexpr Debug prod;
  std::string db_option;
  std::cout << "Set Debug? (y)yes/(n)no : " << std::endl;
  std::getline(std::cin, db_option);
  if (db_option == "y" || db_option == "Y") {
    io_sub.set_io(true);
  }
  writeToFile("./testing.txt", io_sub);

  // writetofile("./regular.txt", "seeing if this still writes", prod);

  return 0;
}
