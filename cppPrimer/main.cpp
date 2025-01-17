#include <iostream>

int (*func(int addP))[10] {
  static int arrS[10];
  try {
    if (addP > 0) {
      for (int i = 0; i < 10; ++i) {
        arrS[i] = i + addP;
      }
      return &arrS;
    } else {
      throw std::runtime_error("Cannot add to 0");
    }
  } catch (std::runtime_error &err) {
    std::cout << err.what() << std::endl;
  }
  return nullptr;
}
int main(int argc, char *argv[]) {
  int(*myArray)[10] = func(2);

  if (myArray) {
    for (auto &el : *myArray) {
      std::cout << el << std::endl;
    }
  }
  return 0;
}
