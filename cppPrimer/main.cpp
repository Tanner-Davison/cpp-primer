
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::cout << "program starts here: " << std::endl;

  std::fstream inFile("./hextest.txt");
  if (!inFile) {
    std::cout << "Error no infile found" << std::endl;
    return 1;
  }
  std::string line;

  while (std::getline(inFile, line)) {
    std::stringstream s(line);
    std::string word;
    while (s >> word) {
      std::cout << word << std::endl;
    }
  }
  std::cout << "Program Ends Here -> \n";
  return 0;
}
