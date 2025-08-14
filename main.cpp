#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

std::map<std::string, std::string> buildMap(std::ifstream& codes) {
   std::map<std::string, std::string> transmap;

   std::string key, line;

   while (codes >> key && getline(codes, line)) {
      if (line.size() > 1 && line.find_first_not_of(" \t") != std::string::npos) {
         if (!transmap.insert({key, line.substr(1)}).second) {
            std::cerr << "Duplicate key found!" << std::endl;
         }

      } else {
         std::cerr << "Rule has been set with no value" << std::endl;
      }
   }

   return transmap;
}

std::string translation(const std::map<std::string, std::string>& transMap, std::string& word) {
   auto target = transMap.find(word);
   if (target != transMap.end()) {
      return target->second;
   } else {
      return word;
   }
}

void manage_translation(std::ifstream& codes, std::ifstream& text) {
   auto transMap = buildMap(codes);

   std::string line;

   while (getline(text, line)) {
      std::string       word, msg;
      std::stringstream s(line);

      while (s >> word) {
         msg = translation(transMap, word);
         std::cout << msg << " ";
      }
      std::cout << std::endl;
   }
};

int main() {
   std::ifstream codes("./out1.txt");
   std::ifstream message("./out2.txt");
   if (!codes || !message) {
      std::cout << "cannot read input files" << std::endl;
      throw std::runtime_error("cannot open Input files");
   }
   manage_translation(codes, message);
   return 0;
}
