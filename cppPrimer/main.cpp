#include <iostream>
typedef int arrP[10];
int (*func(int p))[10] {
  static arrP arrP;
  try {
    if (p > 0) {
      for (int i = 0; i < p; ++i) {
        arrP[i] = i;
        std::cout << arrP[i] << std::endl;
      }
      return &arrP;
    } else {
      throw std::runtime_error("function has no valid parameters");
    }
  } catch (std::runtime_error &err) {
    std::cout << err.what() << std::endl;
    return nullptr;
  }
  return nullptr;
}
int main() {
  int(*arr)[10] = func(0);

  return 0;
}
