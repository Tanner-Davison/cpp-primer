#include "Book.hpp"
#include <string>

Book::Book(std::string auth, std::string bookName, std::string totalPages,
           std::string publishedDate)
    : author(auth), book_name(bookName), total_pages(totalPages),
      published_date(publishedDate) {};

Book::Book() : Book("", "", "", "") {};

Book::Book(std::string auth, std::string bookName, std::string totalPages)
    : Book(auth, bookName, totalPages, "unknown") {};
// copy constructor using constructor delegation!
Book::Book(const Book &other)
    : Book(other.author, other.book_name, other.total_pages,
           other.published_date) {};

std::istream &operator>>(std::istream &is, Book &data) {
  std::string line;
  std::getline(is, line);
  data.author = line;
  std::getline(is, line);
  data.book_name = line;
  std::getline(is, line);
  data.total_pages = line;
  std::getline(is, line);
  data.published_date = line;
  return is;
};
bool read(std::istream &is, Book &data) {
  std::string line;
  std::getline(is, line);
  data.author = line;
  std::getline(is, line);
  data.book_name = line;
  std::getline(is, line);
  data.total_pages = line;
  std::getline(is, line);
  data.published_date = line;
  if (is.good()) {
    return true;
  }
  return false;
}
void print(std::ostream &os, Book &book) {
  os << "Author: " << book.author << "\n"
     << "Book: " << book.book_name << " ( " << book.total_pages << " pages )\n"
     << "Published: " << book.published_date << "\n";
}
std::ostream &operator<<(std::ostream &os, const Book &book) {
  os << "Author: " << book.author << "\n"
     << "Book: " << book.book_name << " ( " << book.total_pages << " pages )\n"
     << "Published: " << book.published_date << "\n";
  return os;
};
