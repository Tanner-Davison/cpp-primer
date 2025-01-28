
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int (*func())[10] {
  static int tempArr[10];
  for (int i = 0; i < 10; ++i) {
    tempArr[i] = i;
  }
  return &tempArr;
}
char (*stringFunc())[10] {
  static char nameTemp[10];
  for (int i = 0; i < 10; ++i) {
    nameTemp[i] = ('A' + i);
  }
  return &nameTemp;
}

int main() {
  int(*myIntPtr)[10] = func();
  char(*charArr)[10] = stringFunc();
  for (auto i : *myIntPtr) {
    std::cout << (*myIntPtr)[i] << std::endl;
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << (*charArr)[i];
  }

  std::cout << "\nprogram starts here: " << std::endl;
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
