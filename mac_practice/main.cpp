#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
int main() {
  std::ifstream in("./input.txt");
  std::ofstream out_1("./output_1.txt"), out_2("./output_2.txt");
  if (!in || !out_1 || !out_2) {
    std::cout << "no input/or output files found" << std::endl;
    return 0;
  }
  std::istream_iterator<std::string> iter_in(in), eof;
  std::ostream_iterator<std::string> it_out_more(out_1, "\n");
  std::ostream_iterator<std::string> it_out_less(out_2, "\n");
  std::copy_if(iter_in, eof, it_out_more,
               [&](std::string str) { return str.size() >= 7 == 1; });

  std::copy_if(iter_in, eof, it_out_less,
               [&](std::string str) { return str.size() <= 7 == 1; });
}
