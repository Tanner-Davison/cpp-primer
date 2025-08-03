#include "../../../references/Anscii.hpp"
#include <iostream>
#include <map>
#include <set>
#include <windows.h>
// Shows two ways of word_count (UPDATED TO INCLUDE ANSIColors)

// 1. uses insert with the check from the pointer to the position and the
// boolean whether it passed or failed

// 2nd uses the subscript operator with no check.

int main() {

  /*Endables ANSI*/
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode = 0;
  GetConsoleMode(hOut, &dwMode);
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
  std::map<std::string, std::size_t> word_count;
  std::set<std::string> exclude_list{"The", "But", "And", "Or", "An", "A",
                                     "the", "but", "and", "or", "a"};
  std::string word;

  while (std::cin >> word && word != "1") {
    if (exclude_list.find(word) == exclude_list.end()) {
      auto word_it = word_count.insert({word, 1});
      if (!word_it.second) {
        ++(word_it.first->second);
      }
      // ++word_count[word];
    }
  }
  for (const auto &words : word_count) {
    std::cout << "'" << ANSIColors::BRIGHT_BLACK << words.first << "'"
              << " occurs: " << ANSIColors::SILVER() << words.second
              << ANSIColors::PURPLE()
              << ((words.second > 1) ? " times.\n" : " time.\n")
              << ANSIColors::RESET;
  }
  ANSIColors::printRainbow("SO F**KING COOL");
  std::cout << std::endl;

  return 0;
}
