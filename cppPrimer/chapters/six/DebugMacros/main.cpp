#include <cassert>
#include <iostream>
#include <source_location>

void print(const int ia[], size_t size) {
#ifndef NDEBUG
  std::cerr << std::source_location::current().function_name()
            << " : array size is " << size << "\n";
#endif
  for (size_t i = 0; i < size; i++) {
    std::cout << ia[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  print(arr, 5);
  return 0;
}
