// Copyright (c) 2025 Tanner  Davison . All Rights Reserved.
// The Shared Pointer
#include <iostream>
#include <list>
#include <memory>

int main() {
  auto s_p1 = std::make_shared<int>(1);
  auto c_p1 = s_p1;

  std::cout << c_p1.use_count();
  c_p1.reset();

  std::cout << s_p1.use_count() << "\n";
  std::cout << std::endl;
  return 0;
}
