#include "../../headers/Anscii.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
// color with initialization defaults color [static function load(like lazy
// load)]
const std::string& orange() {
   static const std::string c = ANSIColors::ORANGE();
   return c;
}

const std::string& crimson() {
   static const std::string c = ANSIColors::CRIMSON();
   return c;
}
const std::string& yellow() {
   static const std::string c = ANSIColors::SUNSET_YELLOW();
   return c;
}

static const std::string white = ANSIColors::WHITE;
static const std::string bold  = ANSIColors::BOLD;
static const std::string reset = ANSIColors::RESET;

std::map<std::string, std::string> buildMap(std::ifstream& map_file) {
   std::map<std::string, std::string> trans_map;

   std::string key;
   std::string value;

   while (map_file >> key && getline(map_file, value)) {
      auto print_error = [&](const std::string& e_msg) {
         std::cerr << crimson() << "[!Error] ";
         std::cerr << orange() << e_msg;
         std::cerr << yellow() << "[" << key << "]";
         std::cerr << reset << std::endl;
      };

      if (value.size() > 1 && value.find_first_not_of(" \t") != std::string::npos) {
         if (!trans_map.insert({key, value.substr(1)}).second) {
            print_error("Duplicate key found: ");
         }
         //  <---[ Success No Errors] ---> */
      } else {
         print_error("Rule has been set with NO value: ");
      }
   }
   return trans_map;
}

const std::string& transform(const std::string& s, const std::map<std::string, std::string>& m) {
   auto map_it = m.find(s);
   if (map_it != m.end()) {
      return map_it->second;
   } else {
      return s;
   }
}

void word_transform(std::ifstream& map_file, std::ifstream& text_input) {
   auto trans_map = buildMap(map_file);

   std::string text;

   while (getline(text_input, text)) {
      std::istringstream stream(text);

      std::string word;

      bool firstword = true;
      while (stream >> word) {
         if (firstword)
            firstword = false;
         else
            std::cout << " ";

         std::cout << bold << transform(word, trans_map) << reset;
      }
      std::cout << std::endl;
   }
}

int main() {
   std::ifstream rules_input("./rules.txt");
   std::ifstream text_input("./text.txt");

   if (!rules_input)
      throw std::runtime_error("No Rules found");
   if (!text_input)
      throw std::runtime_error("No text file found");

   word_transform(rules_input, text_input);

   return 0;
}
