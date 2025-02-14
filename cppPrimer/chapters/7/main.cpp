#include "Sales_data.hpp"
#include <fstream>
#include <iostream>

int main() {
  std::fstream inFile("./chapters/7/input.txt");
  if (!inFile) {
    inFile.clear();
    inFile.open("./input.txt");
    if (!inFile) {
      throw std::runtime_error("Could not open input file in either location");
    }
  }
  Sales_data total;

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
  return 0;
}
