#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
// Reads from inpute file
// writes even nums to one file and odd nums to another
int main() {
  std::ifstream input_file("./input_file.txt");
  std::ofstream output_evens("./output_evens.txt");
  std::ofstream output_odds("./output_odds.txt");

  if (!input_file || !output_evens || !output_odds) {
    std::cout << "Missing input or output files" << std::endl;
  }
  std::istream_iterator<int> in_iter(input_file), eof;
  std::ostream_iterator<int> out_evens(output_evens, ", ");
  std::ostream_iterator<int> out_odds(output_odds, ", ");

  std::partition_copy(in_iter, eof, out_odds, out_evens,
                      [](int x) { return x % 2 == 1; });
  return 0;
}
