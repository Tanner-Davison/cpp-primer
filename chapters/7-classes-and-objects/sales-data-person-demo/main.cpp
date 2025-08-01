#include "Person.hpp"
#include "Sales_data.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string input_path = (argc > 1) ? argv[1] : "./input.txt";
  std::string input_person = (argc > 2) ? argv[2] : "./person.txt";
  std::fstream inFile(input_path);
  std::fstream inFile_person(input_person);

  if (!inFile) {
    throw std::runtime_error("Could not open input file in either location");
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
    // final trans
    print(std::cout, total);
    // log time
    trans.logTime(std::cout);
  } else {
    std::cerr << "No data?!" << std::endl;
  }

  inFile.close();

  if (!inFile_person) {
    throw std::runtime_error("No Person data found!");
  }

  const char *checkmark = " ✓ ";
  // person data display
  if (read_person(inFile_person, person)) {
    std::cout << "---- Person Data Available " << checkmark << "----"
              << std::endl;
    print_person(std::cout, person);
  }

  return 0;
}
