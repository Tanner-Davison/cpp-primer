#include "Person.hpp"
#include "Sales_data.hpp"
#include <fstream>
#include <iostream>

int main() {
  // Try primary file paths first, fall back to local directory if needed
  std::fstream inFile("./chapters/7/input.txt");
  std::fstream inFile_person("./chapters/7/person.txt");

  // Attempt to open sales data file in alternate location if primary fails
  if (!inFile) {
    inFile.clear();
    inFile.open("./input.txt");
    if (!inFile) {
      throw std::runtime_error("Could not open input file in either location");
    }
  }

  Sales_data total;
  Person person;

  // Process sales data, accumulating transactions for matching ISBNs
  if (read(inFile, total)) {
    Sales_data trans;

    // Combine consecutive transactions with matching ISBNs
    while (read(inFile, trans)) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total);
        total = trans;
      }
    }
    // Print final transaction after loop
    print(std::cout, total);
    // Record processing completion time
    trans.logTime(std::cout);
  } else {
    std::cerr << "No data?!" << std::endl;
  }

  inFile.close();

  // Attempt to open person data file in alternate location if primary fails
  if (!inFile_person) {
    inFile_person.clear();
    inFile_person.open("./person.txt");
    if (!inFile_person) {
      throw std::runtime_error("No Person data found!");
    }
  }

  const char *checkmark = " ✓ ";

  // Display person data if successfully read from file
  if (read_person(inFile_person, person)) {
    std::cout << "---- Person Data Available " << checkmark << "----"
              << std::endl;
    print_person(std::cout, person);
  }

  return 0;
}
