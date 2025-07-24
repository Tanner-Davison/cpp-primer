#include "Sales_item.h"
#include <iostream>
#include <iterator>

int main() {
  std::istream_iterator<Sales_item> item_iter(std::cin), eof;
  std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");

  Sales_item sum = *item_iter++;

  while (item_iter != eof) {
    if (item_iter->isbn() == sum.isbn()) {
      sum += *item_iter++;
    } else {
      out_iter = sum;
      sum = *item_iter++;
    }
  }
  out_iter = sum;
  return 0;
}
