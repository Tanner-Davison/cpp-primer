#pragma once
#include "book.hpp"
#include <vector>

class BookLibrary {
public:
  BookLibrary();
  void add_book(Book &);
  void read_inventory() const;

  std::vector<Book> books{Book("Inventory List")};
};
