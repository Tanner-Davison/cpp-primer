/*
 * Copyright (c) 2025 Your Name
 * All rights reserved.
 *
 */
#include <iostream>
int main() {
  int x = 10;
  int y = 100;
  auto increment = [&, y] mutable {
    x++;
    y--;
    std::cout << x;
  };
  for (std::size_t i = 0; i < 10; ++i) {
    increment();
    std::cout << std::endl;
  }
  std::cout << &x << std::endl;

  std::cout << &y << std::endl;

  return 0;
}
