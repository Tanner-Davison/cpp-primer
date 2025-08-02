#include <algorithm>
#include <iostream>
#include <vector>
// fill_n
int main() {
  std::cout << "sequence before:" << std::endl;
  std::vector<int> sequence{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (const auto &num : sequence) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  std::cout << "sequence after std::fill_n:" << std::endl;
  std::fill_n(begin(sequence), sequence.size(), 0);
  for (const auto &num : sequence) {
    std::cout << num << ", ";
  }
  std::cout << std::endl;
  return 0;
}
