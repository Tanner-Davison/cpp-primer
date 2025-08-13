// This demonstration shows the usage of istream_iterators when using algorithms
// such as Accumuluate
//
#include <iostream>
#include <iterator>
#include <numeric>
int main() {
  std::cout << "type any Non Number to STOP and add all nums" << std::endl;
  std::istream_iterator<int> it(std::cin), eof;
  std::cout << std::accumulate(it, eof, 0) << std::endl;
  return 0;
};
