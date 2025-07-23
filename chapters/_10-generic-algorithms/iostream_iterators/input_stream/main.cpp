
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::istream_iterator<int> str_it(std::cin), eof;

  // std::ifstream in("./sample_text.txt");
  std::vector<int> saved_string_data(str_it, eof);
  while (str_it != eof) {
    saved_string_data.push_back(*str_it++);
  }
  for (const auto &word : saved_string_data) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  return 0;
}
