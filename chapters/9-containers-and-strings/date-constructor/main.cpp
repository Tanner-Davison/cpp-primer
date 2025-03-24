#include "Date.hpp"

int main() {
  std::vector<std::string> tests = {
      "November, 10, 1995", "11/10/1995",  "Nov 10, 1995",    "11-10-1995",
      "1995.11.10",         "Nov 10 1995", "10 November 1995"};

  for (const auto &test : tests) {
    Date date(test);
    std::cout << "Input: " << test << " Output: -> ";
    date.display();
  }

  return 0;
}
