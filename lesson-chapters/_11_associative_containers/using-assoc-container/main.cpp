#include "../../../headers/Anscii.hpp"
#include <iostream>
#include <map>
#include <set>
#include <windows.h>
/*
 * Word frequency counter with exclusion filtering and colored output.
 *
 *    Copyright (c) 2025 Tanner Davison. All rights reserved.
 *
 * 1. Uses map::insert() to check if word exists - returns pair<iterator, bool>
 *    where the boolean indicates if insertion occurred (new word) or failed
 * (existing word).
 * 2. Increments count for existing words using the returned iterator.
 * 3. Filters out common words (articles, conjunctions) using a set for O(log n)
 * lookup.
 * 4. Uses static const strings for ANSI color codes to avoid repeated string
 * construction.
 * 5. Outputs colored word frequency report with grammatically correct
 * pluralization.
 */
int main() {
  static const std::string white = ANSIColors::BRIGHT_CYAN;
  static const std::string black = ANSIColors::BRIGHT_BLACK;
  static const std::string red = ANSIColors::BRIGHT_MAGENTA;
  static const std::string reset = ANSIColors::RESET;

  std::map<std::string, size_t> word_count;
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
  std::cout << ANSIColors::CLEAR_SCREEN;
  for (const auto &words : word_count) {
    std::cout << black << "'" << white << words.first << black << "'"
              << " occurs: " << red << words.second << reset << black
              << ((words.second > 1) ? " times.\n" : " time.\n") << reset;
  }
  ANSIColors::printFire("\nEnd Program------->");
  std::cout << std::endl;
  return 0;
}
