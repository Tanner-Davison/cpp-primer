#include <iostream>
#include <map>
#include <vector>

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
void myRec(int *arr, int index) { // Recursion example
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
// COMPLEX EXAMPLE of a function that returns a reference to an array of
// pointers to functions that each take a vector of integers and return a const
// reference to a map of strings to doubles.
//  Original complex declaration
std::map<std::string, double> const &(*(&complexFunc())[5])(std::vector<int>);

// Trailing return style (more readable)
auto complexFunc()
    -> std::map<std::string, double> const &(*(&)[5])(std::vector<int>);

// Break it down into manageable pieces using Type aliases
using MapType = std::map<std::string, double>;
using MapRef = const MapType &;
using FuncPtr = MapRef (*)(std::vector<int>); // Pointer to function
using ArrayOfFuncPtr = FuncPtr[5];            // Array of function pointers
using ArrayPtrRef = ArrayOfFuncPtr &;         // Reference to the array

ArrayPtrRef complexFunc();
//////////////////////////////
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
