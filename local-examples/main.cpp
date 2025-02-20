#include "Book.hpp"
#include "BookLibrary.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

int main() {

  BookLibrary lib;
  Book book_ref;
  std::size_t search;
  std::fstream inFile("./books.txt");
  if (!inFile) {
    throw std::runtime_error("No input file found!");
  }
  std::cout << "Search by id: ";
  std::cin >> search;

  while (read_non_blanks(inFile, book_ref)) {
    lib.add_book(book_ref);
  }
  std::cout << *lib.search_id(search) << std::endl;
  ;
  // lib.read_inventory();

  // std::cout << lib.books.front() << std::endl;
  return 0;
}
