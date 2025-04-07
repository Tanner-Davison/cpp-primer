// spaceship operator (c++ new declaration)

#include <compare>
#include <iostream>

struct Point {
  int x, y;

  auto operator<=>(const Point &other) const {
    // First compare x values
    if (auto cmp = x <=> other.x; cmp != 0) {
      return cmp;
    }
    // If x values are equal, compare y values
    return y <=> other.y;
  }

  // The compiler will automatically generate ==, !=, <, <=, >, >= from <=>
};

int main() {
  Point p1{1, 2};
  Point p2{1, 3};

  if (p1 < p2) {
    std::cout << "p1 is less than p2" << std::endl;
  }

  return 0;
}
