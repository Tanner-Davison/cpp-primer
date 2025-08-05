
#include "../../../headers/Anscii.hpp"
#include <set>
#include <unordered_map>
#include <vector>
#include <windows.h>

/*
   unordered_map example including an exclude list

     1. uses insert with the check from the pointer to the position and the
        boolean whether it passed or failed

     2. uses the subscript operator with no check.

 */

int main() {
   std::string white = ANSIColors::BRIGHT_CYAN;
   std::string black = ANSIColors::BRIGHT_BLACK;
   std::string red   = ANSIColors::BRIGHT_MAGENTA;
   std::string reset = ANSIColors::RESET;

   std::unordered_map<std::string, std::size_t> word_count;
   std::set<std::string> exclude_list{"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "a"};
   std::vector<std::string> read_words{"hello", "world", "hello", "word", "word", "doing", "doing",
                                       "I",     "I",     "I",     "I",    "so",   "word"};
   auto word = read_words.begin();
   while (word != read_words.end()) {
      if (exclude_list.find(*word) == exclude_list.end()) {
         auto word_it = word_count.insert({*word, 1});
         if (!word_it.second) {
            ++(word_it.first->second);
         }
      }
      ++word;
   }
   std::cout << ANSIColors::CLEAR_SCREEN;
   for (const auto& words : word_count) {
      std::cout << black << "'" << white << words.first << black << "'"
                << " occurs: " << red << words.second << reset << black
                << ((words.second > 1) ? " times.\n" : " time.\n") << reset;
   }

   std::cout << std::endl;
   ANSIColors::printRainbow("SO F**KING COOL");

   return 0;
}
