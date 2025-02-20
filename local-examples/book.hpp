#pragma once
#include <iostream>
#include <vector>

class BookLibrary;

class Book {
  friend BookLibrary;

public:
  Book();
  Book(std::string, std::string, std::string, std::string);
  Book(std::string, std::string, std::string);
  Book(std::string);
  // copy constructor
  Book(const Book &);

  // member functions
  std::string get_auth(Book &) const;
  std::string get_book_name(Book &) const;
  std::string get_published_date(Book &) const;

  // friend
  friend std::istream &operator>>(std::istream &, Book &);
  friend void print(std::ostream &, Book &);
  friend std::ostream &operator<<(std::ostream &, const Book &);
  friend bool read(std::istream &, Book &);
  friend bool read_non_blanks(std::istream &, Book &);
  // Skip any empty lines
private:
  std::size_t book_id = 1;
  std::string author;
  std::string book_name;
  std::string total_pages;
  std::string published_date;

private:
  inline void set_id(std::vector<Book>::size_type);
};

// forward declarations
std::istream &operator>>(std::istream &, Book &);
void print(std::ostream &, Book &);
bool read(std::istream &, Book &);
bool read_non_blanks(std::istream &, Book &);
// inline functions
void Book::set_id(std::size_t id) { book_id = id; };
