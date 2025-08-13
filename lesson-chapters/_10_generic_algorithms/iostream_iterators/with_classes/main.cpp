#include "Sales_item.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

  std::fstream transaction_list("./input.txt");
  if (transaction_list) {
    std::cout << "no input file found" << std::endl;
  }
  std::istream_iterator<Sales_item> item_iter(transaction_list), eof;
  std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");
  Sales_item sum = *item_iter++;
  std::vector<Sales_item> transactions;

  while (item_iter != eof) {
    if (item_iter->isbn() == sum.isbn()) {
      sum += *item_iter++;
      transactions.emplace_back(*item_iter);
    } else {
      out_iter = sum;
      sum = *item_iter++;
    }
  }
  out_iter = sum;

  std::sort(transactions.begin(), transactions.end(),
            [&](Sales_item &x, Sales_item &y) { return x.isbn() < y.isbn(); });
  std::cout << "\n";

  for (const auto &trans : transactions) {
    std::cout << trans.isbn() << ", ";
  }
  return 0;
}
