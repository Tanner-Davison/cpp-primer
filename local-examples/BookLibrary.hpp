#pragma once
#include "book.hpp"
#include <iostream>
#include <vector>

class BookLibrary {
public:
  BookLibrary();
  void add_book(Book &);
  void read_inventory() const;
  Book *search_id(std::size_t);
  std::size_t get_book_count() const;
  std::vector<Book> books{Book("Inventory List")};
};
