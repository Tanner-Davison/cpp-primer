#include <iostream>
#include <iterator>
#include <vector>
int main() {
  std::istream_iterator<int> iter_in(std::cin), eof;
  std::ostream_iterator<int> iter_out(std::cout, "\n");
  std::vector<int> container_for_inputs(iter_in, eof);
  if (!container_for_inputs.empty()) {
    for (; iter_in != eof; ++iter_in) {
      iter_out = *iter_in;
    }
  }
  return 0;
}
