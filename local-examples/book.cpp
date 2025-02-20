#include "Book.hpp"
#include <string>

Book::Book(std::string auth, std::string bookName, std::string totalPages,
           std::string publishedDate)
    : author(auth), book_name(bookName), total_pages(totalPages),
      published_date(publishedDate) {};

Book::Book() : Book("", "", "", "") { book_id = 0; };
Book::Book(std::string auth) : Book(auth, "", "", "") {};

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
  if (book.author == "Inventory List") {
    os << "All Available Books" << " id: " << book.book_id << "\n";

    return os;
  } else {
    os << "id: " << book.book_id << "\n"
       << "Author: " << book.author << "\n"
       << "Book: " << book.book_name << " ( " << book.total_pages
       << " pages )\n"
       << "Published: " << book.published_date << "\n";
    return os;
  }
};

bool read_non_blanks(std::istream &is, Book &data) {
  std::string line;

  // Skip any empty lines
  do {
    if (!std::getline(is, line)) {
      return false; // End of file reached
    }
  } while (line.empty());
  data.author = line;

  // book name
  if (!std::getline(is, line) || line.empty())
    return false;
  data.book_name = line;

  // total pages
  if (!std::getline(is, line) || line.empty())
    return false;
  data.total_pages = line;

  // published date
  if (!std::getline(is, line) || line.empty())
    return false;
  data.published_date = line;

  return true;
};
