#include "../../headers/Anscii.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
const std::string crimson = ANSIColors::CRIMSON();
const std::string orange  = ANSIColors::ORANGE();
const std::string yellow  = ANSIColors::SUNSET_YELLOW();
const std::string white   = ANSIColors::WHITE;
const std::string bold    = ANSIColors::BOLD;
const std::string reset   = ANSIColors::RESET;

std::map<std::string, std::string> buildMap(std::ifstream& map_file) {
   std::map<std::string, std::string> trans_map;
   std::string key;
   std::string value;

   while (map_file >> key && getline(map_file, value)) {
      auto print_error = [&](const std::string& e_msg) {
         std::cerr << crimson << "[!Error] " << orange << e_msg << yellow << "[" << key << "]" << reset << std::endl;
      };

      if (value.size() > 1 && value.find_first_not_of(" \t") != std::string::npos) {
         if (!trans_map.insert({key, value.substr(1)}).second) {
            // Duplicate key found
            print_error("Duplicate key found: ");
         }
         /* <---[ Success No Errors] ---> */
      } else {
         // Rule exists but no value/definition given
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
         if (firstword) {
            firstword = false;
         } else {
            std::cout << " ";
         }
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
