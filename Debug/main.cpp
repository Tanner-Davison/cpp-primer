#include "DebugEx.hpp"
#include <conio.h>
#include <cstring>
#include <fstream>
#include <iostream>

bool writetofile(const std::string &filename, const Debug debug) {
  // std::fstream file(filename);
  std::ofstream file(filename);
  std::string buffer;
  if (!file.is_open()) {
    if (debug.any()) {
      std::cerr << "[DEBUG] Failed to open: " << filename << std::endl;
      std::cerr << "[DEBUG] Error: " << strerror(errno) << std::endl;
    }
    return false;
  }
  try {
    char ch;
    const char ESC_KEY = 27;
    while ((ch = _getch()) != ESC_KEY) {
      if (ch == '\r' || ch == 13) { // Enter key
        if (debug.any()) {
          std::cerr << "[DEBUG] Return detected" << std::endl;
        }
        file << buffer << '\n';
        buffer.clear();
        std::cout << '\n';
        continue;
      }

      if (ch == '\b' || ch == 8) { // Backspace
        if (!buffer.empty()) {
          if (debug.any()) {
            std::cerr << "[DEBUG] Backspace detected" << std::endl;
          }
          buffer.pop_back();
          std::cout << "\b \b";
        }
        continue;
      }

      if (debug.any()) {
        std::cerr << "[DEBUG] Got character: " << static_cast<int>(ch)
                  << std::endl;
      }

      buffer += ch;
      std::cout << ch;
    }

    if (!buffer.empty()) {
      file << buffer;
    }

  } catch (const std::exception &e) {
    if (debug.any()) {
      std::cerr << "[DEBUG] Write operation failed" << std::endl;
      std::cerr << "[DEBUG] Faied to write to file: " << filename << std::endl;
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
  writetofile("./test.html", io_sub);

  // writetofile("./regular.txt", "seeing if this still writes", prod);

  return 0;
}
