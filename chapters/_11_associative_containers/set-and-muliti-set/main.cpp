#include <cstdint>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

struct Sales_data {
  int isbn;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn < rhs.isbn;
}
int main() {
  Sales_data a, b;
  a.isbn = 499;
  b.isbn = 299;
  std::multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);
  bookstore.insert(a);
  bookstore.insert(b);

  for (const auto &book : bookstore) {
    std::cout << book.isbn << "\n";
  }
  std::cout << std::endl;
  std::ostream_iterator<std::string> display(std::cout, "\n");
  std::ostream_iterator<int> print_iset(std::cout, " ");
  std::ostream_iterator<int> print_mset(std::cout, " ");
  std::vector<int> ivec;
  for (std::vector<int>::size_type i = 0; i != 10; ++i) {
    ivec.push_back(i);
    ivec.push_back(i);
  }
  std::set<int> iset(ivec.cbegin(), ivec.cend());
  std::multiset<int> mset(ivec.cbegin(), ivec.cend());

  display = "\niset: ";
  for (const int &num : iset) {
    print_iset = num;
  }
  std::cout << std::endl;
  display = "\nmset: ";
  for (const int &num : mset) {
    print_mset = num;
  }

  std::cout << "\n" << std::endl;
  std::cout << "ivec size: " << ivec.size() << std::endl;
  std::cout << "iset size: " << iset.size() << std::endl;
  std::cout << "mset size: " << mset.size() << std::endl;

  return 0;
}
