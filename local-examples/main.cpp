#include "Book.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

int main() {

  Book book_one;
  std::fstream inFile("./books.txt");
  if (!inFile) {
    throw std::runtime_error("No input file found!");
  }

  while (read(inFile, book_one)) {
    std::cout << book_one << std::endl;
  }
  return 0;
}
