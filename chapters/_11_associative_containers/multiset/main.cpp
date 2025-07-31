#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Sales_data {
  int isbn;
  Sales_data(int x) : isbn(x) {};
  Sales_data() : isbn(0) {};
};

// descending order
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn > rhs.isbn;
}

int main() {

  std::vector<Sales_data> sales_vec(29);
  int gen_count = 0;
  std::generate(begin(sales_vec), end(sales_vec), [&gen_count]() {
    gen_count++;
    return Sales_data(gen_count);
  });

  std::multiset<Sales_data, decltype(compareIsbn) *> bookstore(
      sales_vec.begin(), sales_vec.end(), compareIsbn);
  // answer result from exercise 11.19 on page 431;
  std::multiset<Sales_data, decltype(compareIsbn) *>::iterator book_store_ref =
      bookstore.begin();

  for (const auto &book : bookstore) {
    if (book.isbn % 10 == 0) {
      std::cout << "\n";
      std::cout << book.isbn << ", ";
    } else {

      std::cout << book.isbn << ", ";
    }
  }
  std::cout << std::endl;

  // Searching the bookstore example
  Sales_data target(17);
  auto it = bookstore.find(target);
  if (it != bookstore.end()) {
    Sales_data found = *it;
    std::cout << "\nTarget Found: " << found.isbn << std::endl;
  } else {
    std::cout << "Could not find: " << target.isbn
              << " inside of the bookstore." << std::endl;
  }
  return 0;
}
