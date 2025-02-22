#include "DebugEx.hpp"
#include <cstring>
#include <fstream>
#include <iostream>

bool writetofile(const std::string &filename, const std::string &data,
                 const Debug debug) {
  std::fstream file(filename);
  if (!file.is_open()) {
    if (debug.any()) {
      std::cerr << "[DEBUG] Failed to open: " << filename << std::endl;
      std::cerr << "[DEBUG] Error: " << strerror(errno) << std::endl;
    }
    return false;
  }
  try {
    file << data;
  } catch (const std::exception &e) {
    if (debug.any()) {
      std::cerr << "[DEBUG] write operation failed" << std::endl;
      std::cerr << "[DEBUG] Exception: " << e.what() << std::endl;
      std::cerr << "[DEBUG] Attempted to write: " << data.length() << "bytes"
                << std::endl;
    }
  }
  return true;
};

int main() {
  constexpr Debug io_sub(false, true, false);
  constexpr Debug prod(false);

  writetofile("./testing.tx", "This is a critical message", io_sub);

  writetofile("./regular.txt", "seeing if this still writes", prod);

  return 0;
}
