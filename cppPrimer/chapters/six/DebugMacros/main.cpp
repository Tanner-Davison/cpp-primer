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
inline std::string isShorter(const std::string &str, const std::string &str2) {
  return str.size() > str2.size() ? str2 : str;
}

int main(int c, char *[]) {
  std::string name = "Tanner";
  std::string name2 = "Hum";
  std::cout << isShorter(name, name2) << std::endl;
  int arr[] = {1, 2, 3, 4, 5};
  print(arr, 5);
  return 0;
}
