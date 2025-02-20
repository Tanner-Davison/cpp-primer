#include "Book.hpp"
#include "BookLibrary.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

int main() {

  BookLibrary lib;
  Book book_ref;

  std::fstream inFile("./books.txt");
  if (!inFile) {
    throw std::runtime_error("No input file found!");
  }

  while (read_non_blanks(inFile, book_ref)) {
    lib.add_book(book_ref);
  }
  lib.read_inventory();

  // std::cout << lib.books.front() << std::endl;
  return 0;
}
