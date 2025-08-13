#pragma once
#include "book.hpp"
#include <iostream>
#include <map>
#include <vector>

class BookLibrary {
public:
  BookLibrary();
  void add_book(Book &);
  void read_inventory() const;
  Book *search_id(std::size_t);
  std::size_t get_book_count() const;
  
  // New multimap-specific methods
  std::vector<Book *> search_by_title(const std::string &title);
  std::vector<Book *> search_by_author(const std::string &author);
  std::vector<Book *> get_all_books_by_title(const std::string &title);
  
  std::multimap<std::string, Book> books; // Key: book title, Value: Book object

private:
  constexpr static std::size_t default_size = 200;
};
