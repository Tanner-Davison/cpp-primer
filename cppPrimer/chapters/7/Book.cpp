#include "Book.hpp"

Book::Book(std::string auth, std::string bookName, unsigned totalPages,
           std::string publishedDate)
    : author(auth), book_name(bookName), total_pages(totalPages),
      published_date(publishedDate) {};

Book::Book() : Book("", "", 0, "") {};

Book::Book(std::string auth, std::string bookName, unsigned totalPages)
    : Book(auth, bookName, totalPages, "unknown") {};
// copy constructor using constructor delegation!
Book::Book(const Book &other)
    : Book(other.author, other.book_name, other.total_pages,
           other.published_date) {};
