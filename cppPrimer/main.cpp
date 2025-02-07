
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdio.h>
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
class Resource {
public:
  Resource() { std::cout << "Resource constructed\n"; }

  ~Resource() { std::cout << "Resource destroyed\n"; }

  // Prevent copying
  Resource(const Resource &) = delete;
  Resource &operator=(const Resource &) = delete;
};
int main() {
  // Saving the array
  //  Create an array of Resources
  alignas(Resource) unsigned char buffer[sizeof(Resource) * 3];
  Resource *resources = reinterpret_cast<Resource *>(buffer);

  // Construct the Resources
  for (std::size_t i = 0; i < 3; ++i) {
    new (resources + i) Resource();
  }

  std::cout << "Resources constructed, now destroying...\n";

  // Use ranges::destroy to properly destroy the objects
  std::ranges::destroy(resources, resources + 3);
  int(*myIntPtr)[10] = func();
  char(*charArr)[10] = stringFunc();
  for (auto i : *myIntPtr) {
    std::cout << (*myIntPtr)[i] << std::endl;
  }
  for (int i = 0; i < 10; ++i) {
    std::cout << (*charArr)[i];
  }

  std::cout << "\nprogram starts here: " << std::endl;
  printf("line");
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
  std::ranges::destroy;
  std::cout << "Program Ends Here -> \n";
  return 0;
}
