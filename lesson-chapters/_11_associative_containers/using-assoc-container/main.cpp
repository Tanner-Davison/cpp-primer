#include "../../../headers/Anscii.hpp"
#include <iostream>
#include <map>
#include <set>
#include <windows.h>
/*
    1. Uses insert with the check from the pointer
         to the position and the boolean whether it
         passed or failed.
    2. Uses the subscript operator with no check.
    3. Custom ASNIColor class usage.
*/
int main() {
   static const std::string white = ANSIColors::BRIGHT_CYAN;
   static const std::string black = ANSIColors::BRIGHT_BLACK;
   static const std::string red   = ANSIColors::BRIGHT_MAGENTA;
   static const std::string reset = ANSIColors::RESET;

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
   std::cout << ANSIColors::CLEAR_SCREEN;
   for (const auto& words : word_count) {
      std::cout << black << "'" << white << words.first << black << "'"
                << " occurs: " << red << words.second << reset << black
                << ((words.second > 1) ? " times.\n" : " time.\n") << reset;
   }
   ANSIColors::printFire("\nEnd Program------->");
   std::cout << std::endl;
   return 0;
}
