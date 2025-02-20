#include "BookLibrary.hpp"

BookLibrary::BookLibrary() { books.front().set_id(0); }
void BookLibrary::add_book(Book &book) {
  books.push_back(book);
  books.back().set_id(books.size() - 1);
}
void BookLibrary::read_inventory() const {
  for (const auto &book : books) {
    std::cout << book << std::endl;
  }
};
