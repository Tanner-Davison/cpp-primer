#pragma once
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Debug {
public:
  constexpr Debug() : hw(false), io(false), other(false) {};
  constexpr Debug(bool hwp, bool iop, bool otherp)
      : hw(hwp), io(iop), other(otherp) {};
  constexpr Debug(bool h) : hw(h), io(false), other(false) {};
  constexpr Debug(bool h, bool i) : hw(h), io(i), other(false) {};

  constexpr bool any() const { return hw || io || other; }
  void set_io(bool i) { io = i; }
  void set_hw(bool h) { hw = h; }
  void set_other(bool o) { other = o; }
  inline void log_error(std::ostream &out, std::string &filename,
                        std::runtime_error err = std::runtime_error("unknown"));
  inline void log_message(std::ostream &out, const std::string &message,
                          const std::string &filename);
  inline bool file_check(const std::ifstream &is,
                         std::string filename = "unknown",
                         std::runtime_error err = std::runtime_error("unknown"),
                         std::ostream &os = std::cout);

private:
  bool hw, io, other;
};

// inline functions
void Debug::log_error(std::ostream &out, std::string &filename,
                      std::runtime_error err) {
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  struct tm timeinfo;
#ifdef _WIN32
  localtime_s(&timeinfo, &time);
#else
  localtime_r(&time, &timeinfo);
#endif
  out << "\n=========================\n"
      << "\nERROR!\n"
#ifdef _WIN32
      << "\t" << std::put_time(&timeinfo, "%Y-%m-%d\n %I:%M %p")
#else
      << "\t" << std::put_time(&timeinfo, "%Y-%m-%d\n %I:%M %p")
#endif

      << "\n\tdescription: " << err.what() << " : " << filename << "\n( END )\n"
      << "\n=========================\n";
}
void Debug::log_message(std::ostream &out, const std::string &message,
                        const std::string &filename = "") {
  static std::string current_file = "";
  // If we're switching to a new file
  if (current_file != filename && !current_file.empty()) {
    // Add END marker for the previous file
    out << "\n";
  }

  // If this is a new file, print the file header
  if (current_file != filename && !filename.empty()) {
    out << "=========================\n" << "\nFile: \n\t" << filename << "\n";
  }
  // Update current file tracking
  current_file = filename;

  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  struct tm timeinfo;
#ifdef _WIN32
  localtime_s(&timeinfo, &time);
#else
  localtime_r(&time, &timeinfo);
#endif
  out << std::put_time(&timeinfo, "%I:%M %p") << ": \n\tMessage: [ " << message
      << " ]"
      << "\n";
}
bool Debug::file_check(const std::ifstream &is, std::string filename,
                       std::runtime_error err, std::ostream &os) {

  if (!is) {
    if (any()) {
      std::cerr << err.what() << std::endl;
      log_error(os, filename, err);
    }
    return false;
  } else {
    if (any()) {
      log_message(os, "opened!", filename);
      return true;
    }
    return true;
  }
  return false;
}
