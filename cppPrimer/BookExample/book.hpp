#pragma once
#include <iostream>

class Book {
public:
  Book();
  Book(std::string, std::string, std::string, std::string);
  Book(std::string, std::string, std::string);
  // copy constructor
  Book(const Book &);

  friend bool read(std::istream &, Book &);
  // member functions
  // friend
  friend std::istream &operator>>(std::istream &, Book &);
  friend void print(std::ostream &, Book &);
  friend std::ostream &operator<<(std::ostream &, const Book &);

private:
  std::string author;
  std::string book_name;
  std::string total_pages;
  std::string published_date;
};

// forward declarations
std::istream &operator>>(std::istream &, Book &);
void print(std::ostream &, Book &);
bool read(std::istream &, Book &);
