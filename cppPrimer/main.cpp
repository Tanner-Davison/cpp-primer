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
void myRec(int *arr, int index) {
  std::cout << arr[index] << std::endl;
  if (index > 0) {
    --index;
    myRec(arr, index);
  } else {
    std::cout << "end" << std::endl;
  }
}
std::string strArr[10];
decltype(strArr) &arrP(std::string); // decltype version
typedef std::string ArrayType[10];   // typedef version
ArrayType &funcName() {
  static std::string staticString[10];
  return staticString;
}
auto functrail() -> std::string (&)[10]; // Trailing function version

std::string (&stringArr())[10] { // Exercise 6.36 p:230
  static std::string myTempString[10];
  return myTempString;
}
int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 10};
decltype(odd) &arrPtr(int i) { return (i % 2) ? odd : even; }
int main() {
  typedef int &lref;
  typedef int &&rref;
  int n;

  lref &r1 = n;

  int arrTest[10]{10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  myRec(arrTest, 10);
  return 0;
}
