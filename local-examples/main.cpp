#include "Book.hpp"
#include "BookLibrary.hpp"
#include <algorithm>
#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Platform-specific screen clear
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

bool containsIgnoreCase(const std::string &str, const std::string &substring) {
  auto it = std::search(str.begin(), str.end(), substring.begin(),
                        substring.end(), [](char ch1, char ch2) {
                          return std::tolower(ch1) == std::tolower(ch2);
                        });
  return it != str.end();
}

std::vector<Book *> searchBooks(BookLibrary &lib, const std::string &query) {
  std::vector<Book *> results;
  try {
    if (!query.empty()) {
      std::size_t id = std::stoull(query);
      Book *result = lib.search_id(id);
      if (result)
        results.push_back(result);
    }
  } catch (...) {
    for (auto &book : lib.books) {
      if (containsIgnoreCase(book.get_title(), query) ||
          containsIgnoreCase(book.get_auth(), query)) {
        results.push_back(&book);
      }
    }
  }
  return results;
}

void displayResults(const std::vector<Book *> &results,
                    const std::string &query) {
  clearScreen();
  std::cout << "Search: " << query << std::endl;
  std::cout << "---------------------" << std::endl;
  if (results.empty()) {
    std::cout << "No matching books found." << std::endl;
  } else {
    for (const auto &book : results) {
      std::cout << *book << std::endl;
      std::cout << "---------------------" << std::endl;
    }
    std::cout << results.size() << " result(s) found." << std::endl;
  }
}

extern bool read_non_blanks(std::istream &is, Book &data);

int main() {
  BookLibrary lib;
  Book book_ref;
  std::fstream inFile("./books.txt");

  if (!inFile) {
    std::cerr << "Error: Could not open books.txt" << std::endl;
    return 1;
  }

  while (read_non_blanks(inFile, book_ref)) {
    lib.add_book(book_ref);
  }
  inFile.close();

  std::string query;
  char ch;

  clearScreen();
  std::cout << "Interactive Book Search (press Esc to exit)" << std::endl;
  std::cout << "Total books loaded: " << lib.books.size() << std::endl;
  std::cout << "Search: ";

  while (true) {
#ifdef _WIN32
    ch = _getch();
#else
    system("stty raw");
    ch = getchar();
    system("stty cooked");
#endif
    if (ch == 27)
      break;

    if (ch == 8 || ch == 127) {
      if (!query.empty()) {
        query.pop_back();
        auto results = searchBooks(lib, query);
        displayResults(results, query);
        std::cout << "Search: " << query;
      }
      continue;
    }

    if (ch >= 32 && ch <= 126) { // Printable characters
      query += ch;
      auto results = searchBooks(lib, query);
      displayResults(results, query);
      std::cout << "Search: " << query;
    }
  }

  return 0;
}
