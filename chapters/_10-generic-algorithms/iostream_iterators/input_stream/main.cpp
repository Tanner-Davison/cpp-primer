#include <fstream>
#include <iostream>
#include <iterator>

int main() {
  std::ifstream input_file("./sample_text.txt");
  if (!input_file.is_open()) {
    std::cout << "No input file found" << std::endl;
    return 0;
  }
  std::istream_iterator<std::string> in_file_it(input_file), eof;
  int word_count{1};

  for (; in_file_it != eof; ++in_file_it) {
    std::cout << *in_file_it << ", ";
    if (++word_count % 10 == 0) {
      std::cout << "\n";
    }
  }
  std::cout << std::endl;
  return 0;
}
