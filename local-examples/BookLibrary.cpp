#include "BookLibrary.hpp"
#include <algorithm>

BookLibrary::BookLibrary() {
  books.front().set_id(0);
  books.reserve(200);
}
void BookLibrary::add_book(Book &book) {
  books.push_back(book);
  books.back().set_id(books.size() - 1);
}
void BookLibrary::read_inventory() const {
  for (const auto &book : books) {
    std::cout << book << std::endl;
  }
}
Book *BookLibrary::search_id(std::size_t id) {
  auto it = std::find_if(books.begin(), books.end(),
                         [id](const Book &b) { return b.get_id() == id; });
  if (it != books.end())
    return &(*it);
  return nullptr;
}
std::size_t BookLibrary::get_book_count() const { return books.size() - 1; }
