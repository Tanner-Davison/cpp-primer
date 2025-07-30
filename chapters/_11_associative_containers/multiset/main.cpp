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
    gen_count += 5;
    return Sales_data(gen_count);
  });

  std::multiset<Sales_data, decltype(compareIsbn) *> bookstore(
      sales_vec.begin(), sales_vec.end(), compareIsbn);

  for (const auto &book : bookstore) {
    std::cout << book.isbn << ", ";
  }
  std::cout << std::endl;

  return 0;
}
