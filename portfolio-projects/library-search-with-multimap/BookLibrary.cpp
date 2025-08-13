#include "BookLibrary.hpp"
#include <algorithm>

// constexpr static members;
constexpr std::size_t BookLibrary::default_size;

BookLibrary::BookLibrary() {
  // No need to reserve space for multimap, it grows automatically
  // Add a header book for inventory display
  Book header_book("Inventory List");
  header_book.set_id(0);
  books.insert({"Inventory List", header_book});
}

void BookLibrary::add_book(Book &book) {
  // Set the book ID based on current size
  book.set_id(books.size());
  // Insert into multimap with book title as key
  books.insert({book.get_title(), book});
}

void BookLibrary::read_inventory() const {
  for (const auto &[title, book] : books) {
    std::cout << book << std::endl;
  }
}

Book *BookLibrary::search_id(std::size_t id) {
  // Search through all books in the multimap
  for (auto &[title, book] : books) {
    if (book.get_id() == id) {
      return &book;
    }
  }
  return nullptr;
}

std::size_t BookLibrary::get_book_count() const { 
  return books.size() - 1; // Subtract 1 for the header book
}

// New multimap-specific methods
std::vector<Book *> BookLibrary::search_by_title(const std::string &title) {
  std::vector<Book *> results;
  
  // Use multimap's equal_range to find all books with the same title
  auto range = books.equal_range(title);
  for (auto it = range.first; it != range.second; ++it) {
    results.push_back(&(it->second));
  }
  
  return results;
}

std::vector<Book *> BookLibrary::search_by_author(const std::string &author) {
  std::vector<Book *> results;
  
  // Search through all books for matching author
  for (auto &[title, book] : books) {
    if (book.get_auth() == author) {
      results.push_back(&book);
    }
  }
  
  return results;
}

std::vector<Book *> BookLibrary::get_all_books_by_title(const std::string &title) {
  std::vector<Book *> results;
  
  // Use multimap's equal_range to find all books with the same title
  auto range = books.equal_range(title);
  for (auto it = range.first; it != range.second; ++it) {
    results.push_back(&(it->second));
  }
  
  return results;
}
