// Copyright(c) 2025 Tanner Davison.All rights reserved
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  * of this software and associated documentation files (the "Software"), to
//  deal * in the Software without restriction, including without limitation the
//  rights * to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell * copies of the Software, and to permit persons to whom the
//  Software is * furnished to do so, subject to the following conditions: * * -
//  This copyright notice and permission notice shall be included in all *
//  copies or substantial portions of the Software. * * THE SOFTWARE IS PROVIDED
//  "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR * IMPLIED, INCLUDING BUT
//  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, * FITNESS FOR A PARTICULAR
//  PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE * AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER * LIABILITY, WHETHER IN AN
//  ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, * OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN * THE SOFTWARE.

// Project headers first
#include "./BookLibrary.hpp"
#include "./book.hpp"
// C system headers
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring> // For memset
// C++ system headers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// Platform-specific headers
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// Platform-specific getch implementation
#ifdef _WIN32
// On Windows, use _getch() directly
#else
// On Unix/Linux, use termios-based implementation
char getch() {
  char buf = 0;
  struct termios old;
  struct termios current;

  // Get current terminal settings
  if (tcgetattr(0, &old) < 0) {
    perror("tcgetattr()");
    return 0;
  }

  // Copy the settings
  current = old;

  // Disable canonical mode and echo
  current.c_lflag &= ~ICANON;
  current.c_lflag &= ~ECHO;
  current.c_cc[VMIN] = 1;  // Read 1 character at a time
  current.c_cc[VTIME] = 0; // No timeout

  // Apply the new settings
  if (tcsetattr(0, TCSANOW, &current) < 0) {
    perror("tcsetattr ICANON");
    return 0;
  }
  // Read a single character
  char ch;
  if (read(0, &ch, 1) < 0) {
    perror("read()");
    // Restore terminal settings before returning on error
    tcsetattr(0, TCSADRAIN, &old);
    return 0;
  }

  // Restore the original terminal settings
  if (tcsetattr(0, TCSADRAIN, &old) < 0) {
    perror("tcsetattr ~ICANON");
  }

  return ch;
  memset(&old, 0, sizeof(old));
  if (tcgetattr(0, &old) < 0)
    perror("tcsetattr()");
  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &old) < 0)
    perror("tcsetattr ICANON");
  if (read(0, &buf, 1) < 0)
    perror("read()");
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;
  if (tcsetattr(0, TCSADRAIN, &old) < 0)
    perror("tcsetattr ~ICANON");
  return buf;
}
#endif
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

// Search for books matching the query
std::vector<Book *> searchBooks(BookLibrary &lib, const std::string &query) {
  std::vector<Book *> results;

  // Empty query returns no results
  if (query.empty()) {
    return results;
  }

  // Try to interpret query as an ID
  try {
    std::size_t id = std::stoull(query);
    Book *book_result = lib.search_id(id);
    if (book_result) {
      results.push_back(book_result);
    }
  } catch (...) {
    // If query is not a valid ID, search by title and author
    for (auto &[title, book] : lib.books) {
      if (containsIgnoreCase(book.get_title(), query) ||
          containsIgnoreCase(book.get_auth(), query)) {
        results.push_back(&book);
      }
    }
  }

  return results;
}

// Display search results
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

// External function declaration
extern bool read_non_blanks(std::istream &is, Book &data);

int main() {
  BookLibrary lib;
  Book book_ref;

  // Open and load the books file
  std::fstream inFile("./books.txt");
  if (!inFile) {
    std::cerr << "Error: Could not open books.txt" << std::endl;
    return 1;
  }

  // Read books from file
  while (read_non_blanks(inFile, book_ref)) {
    lib.add_book(book_ref);
  }
  inFile.close();

  // Initialize search interface
  std::string query;
  char ch;
  clearScreen();
  std::cout << "Interactive Book Search (press Esc to exit)" << std::endl;
  std::cout << "Total books loaded: " << lib.get_book_count() << std::endl;
  std::cout << "Search: ";

  // Main input loop
  while (true) {
#ifdef _WIN32
    ch = _getch();
#else
    ch = m_getch();
#endif
    // Exit on Escape key
    if (ch == 27) {
      break;
    }

    // Handle backspace (both ASCII 8 and 127 for different terminals)
    if (ch == 8 || ch == 127) {
      if (!query.empty()) {
        query.pop_back();
        auto results = searchBooks(lib, query);
        displayResults(results, query);
        std::cout << "Search: " << query;
      }
      continue;
    }

    // Handle printable characters
    if (ch >= 32 && ch <= 126) {
      query += ch;
      auto results = searchBooks(lib, query);
      displayResults(results, query);
      std::cout << "Search: " << query;
    }
  }

  return 0;
}
