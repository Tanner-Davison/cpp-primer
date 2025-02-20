#include "Book.hpp"
#include "BookLibrary.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

int main() {
  std::fstream inFile("./books.txt");
  if (!inFile) {
    throw std::runtime_error("No input file found!");
  }
  BookLibrary lib;
  Book book_ref;

  while (read_non_blanks(inFile, book_ref)) {
    lib.add_book(book_ref);
  }

  std::cout << "Search by id (press Enter to list all): ";
  std::string input;
  std::getline(std::cin, input);

  if (input.empty()) {
    lib.read_inventory();
  } else {
    try {
      std::size_t search_id = std::stoull(input);
      auto book_ptr = lib.search_id(search_id);
      if (book_ptr) {
        std::cout << *book_ptr << std::endl;
      } else {
        std::cout << "No book found with ID: " << search_id << std::endl;
      }
    } catch (const std::exception &) {
      std::cout << "Invalid ID. Showing all books instead.\n";
      lib.read_inventory();
    }
  }

  inFile.close();
  return 0;
}
