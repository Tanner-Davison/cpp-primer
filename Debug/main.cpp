#include "DebugEx.hpp"
#include <conio.h>
#include <cstring>
#include <fstream>
#include <iostream>

bool writetofile(const std::string &filename, const Debug debug) {
  // std::fstream file(filename);
  std::ofstream file(filename);
  if (!file.is_open()) {
    if (debug.any()) {
      std::cerr << "[DEBUG] Failed to open: " << filename << std::endl;
      std::cerr << "[DEBUG] Error: " << strerror(errno) << std::endl;
    }
    return false;
  }
  try {
    char ch;
    while ((ch = _getch()) != 27) {
      if (debug.any()) {
        std::cerr << "[DEBUG] Got Character: " << static_cast<int>(ch)
                  << std::endl;
      }
      file.put(ch);
    }
    // file << data;
  } catch (const std::exception &e) {
    if (debug.any()) {
      std::cerr << "[DEBUG] write operation failed" << std::endl;
      std::cerr << "[DEBUG] Exception: " << e.what() << std::endl;
      // std::cerr << "[DEBUG] Attempted to write: " << ch << "bytes" <<
      // std::endl;
    }
  }
  return true;
};

int main() {
  constexpr Debug io_sub(false, true, false);
  constexpr Debug prod;

  writetofile("./testing.txt", io_sub);

  // writetofile("./regular.txt", "seeing if this still writes", prod);

  return 0;
}
