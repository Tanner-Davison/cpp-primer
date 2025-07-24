#include "Person.hpp"
#include "Sales_data_copy.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
bool compareSalesData(const std::string &str1, const std::string &str2) {
  return str1 < str2;
}

int main(int argc, char *argv[]) {
  std::string input_path = (argc > 1) ? argv[1] : "./input.txt";
  std::string input_person = (argc > 2) ? argv[2] : "./person.txt";
  std::fstream inFile(input_path);
  std::fstream inFile_person(input_person);

  if (!inFile) {
    throw std::runtime_error("Could not open input file in either location");
  }

  Sales_data total;
  std::vector<std::string> sales_isbn;
  Person person;
  if (read(inFile, total)) {
    sales_isbn.emplace_back(total.isbn());
    Sales_data trans;

    while (read(inFile, trans)) {
      sales_isbn.emplace_back(trans.isbn());
      if (total.compareIsbn(trans.isbn())) {
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
  std::sort(sales_isbn.begin(), sales_isbn.end(), compareSalesData);
  auto end_unique = std::unique(sales_isbn.begin(), sales_isbn.end());
  sales_isbn.erase(end_unique, sales_isbn.end());
  std::cout << "All Unique Isbn's" << std::endl;
  for (const auto &isbn : sales_isbn) {
    std::cout << isbn << ", ";
  }
  std::cout << "\n" << std ::endl;
  std::cout << std::endl;
  const char *checkmark = " ✓ ";
  // person data display
  if (read_person(inFile_person, person)) {
    std::cout << "---- Person Data Available " << checkmark << "----"
              << std::endl;
    print_person(std::cout, person);
  }

  return 0;
}
