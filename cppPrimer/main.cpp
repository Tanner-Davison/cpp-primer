#include <ios>
#include <iostream>
#include <vector>

int (*func(int param1 = 10))[10] {
  static int arrP[10];
  if (param1 > 0) {
    for (int i = 1; i < 11; ++i) {
      arrP[i - 1] = i;
    }
    return &arrP;
  }
  return nullptr;
}
typedef std::string::size_type sz;

std::vector<int> *funcVec(sz arrSz = 10) {
  if (arrSz > 0) {
    static std::vector<int> arrPtr;
    for (sz i = 0; i < arrSz; ++i) {
      arrPtr.emplace_back(i);
    }
    return &arrPtr;
  }
  return {};
}
int InitializeAge(int month, int born, int currentYear = 2025) {
  std::cout << born << std::endl;
  static int currMonth = 1;
  if (month > currMonth) {
    return (currentYear - born) - 1;
  }
  return currentYear - born;
}
inline std::string &shorterString(std::string &one, std::string &two) {
  return one.size() < two.size() ? one : two;
}

constexpr int scale(std::string::size_type sz) { return 2 * sz; }
int main() {
  int arrTest[scale(4)];
  for (int i = 0; i < 8; ++i) {
    arrTest[i] = i;
    std::cout << arrTest[i];
  }
  int(*myArrP)[10] = func(10);
  sz SIZE = 20;
  for (int i = 0; i < 10; ++i) {
    std::cout << (*myArrP)[i] << std::endl;
  }
  // Vector Example
  std::vector<int> *myTestVec{funcVec(SIZE)};
  for (auto val : *myTestVec) {
    std::cout << "Vector: " << val << std::endl;
  }
  int age = InitializeAge(1, 1984);
  std::cout << "I am " << age << " years old." << std::endl;
  return 0;
}
