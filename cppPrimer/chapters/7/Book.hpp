#pragma once
#include <iostream>

class Book {
public:
  Book();
  Book(std::string, std::string, unsigned, std::string);
  Book(std::string, std::string, unsigned);
  // copy constructor
  Book(const Book &);

private:
  std::string author;
  std::string book_name;
  unsigned int total_pages;
  std::string published_date;
};
