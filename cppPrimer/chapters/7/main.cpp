#include "Person.hpp"
#include "Sales_data.hpp"
#include <fstream>
#include <iostream>

int main() {
  std::fstream inFile("./chapters/7/input.txt");
  std::fstream inFile_person("./chapters/7/person.txt");
  if (!inFile) {
    inFile.clear();
    inFile.open("./input.txt");
    if (!inFile) {
      throw std::runtime_error("Could not open input file in either location");
    }
  }
  if (!inFile_person) {
    inFile_person.clear();
    inFile_person.open("./person.txt");
    if (!inFile_person) {
      throw std::runtime_error("No Person data found!");
    }
  }
  Sales_data total;
  Person person;
  if (read(inFile, total)) {
    Sales_data trans;
    while (read(inFile, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total);
        total = trans;
      }
    }
    print(std::cout, total);
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  inFile.close();

  if (read_person(inFile_person, person)) {
    std::cout << "Person Data Available" << std::endl;
    print_person(std::cout, person);
  }

  return 0;
}
