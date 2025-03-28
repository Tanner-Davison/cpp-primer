#include <iomanip>
#include <iostream>
#include <map>
#include <utility>

int main() {

  std::map<std::pair<int, int>, int> grid;
  for (int i = 0; i <= 10; ++i) {

    for (int j = 1; j <= 10; ++j) {
      grid[std::make_pair(i, j)] = i;
    }
  }
  int current_line = -1;
  for (int i = 0; i < 11; ++i) {
    if (i == 0) {
      std::cout << std::setw(5) << "";
      continue;
    }
    auto width = i > 1 ? std::setw(5) : std::setw(2);
    std::cout << width << "  [" << i << "]";
  }
  std::cout << std::endl;
  for (const auto &cell : grid) {
    auto spacing = std::setw(2);
    if (cell.first.first != current_line) {
      if (current_line != -1) {
        std::cout << std::endl;
      }
      current_line = cell.first.first;
      std::cout << " [" << current_line << "] ";
    }
    if (current_line == 10) {
      spacing = std::setw(0);
    }
    std::cout << spacing << "(" << cell.first.first << "," << cell.first.second
              << ") ";
  }

  return 0;
}
