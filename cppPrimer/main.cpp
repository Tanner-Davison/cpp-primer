#include <iostream>

typedef int arrT[10];

arrT *func(int i);
// form of a func that returns an array
//  int (*p2)[10] = &arr;
int (*func(int))[10] {
  static int arrS[10];
  for (int i = 0; i < 10; ++i) {
    arrS[i] = i;
  }
  return &arrS;
};

int main() {
  int(*testPtr)[10] = func(5);
  std::cout << (*testPtr)[3] << std::endl;
  return 0;
}
