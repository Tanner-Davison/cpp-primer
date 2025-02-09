#include <cassert>
#include <iostream>
#define DEBUG

void readArr(int nums[], int size) {
#ifdef DEBUG
  std::cerr << " arr size : " << size << "\n@ Line # " << __LINE__
            << "\nDate: " << __DATE__ << "\nTime: " << __TIME__ << std::endl;
#endif
  if (size > 0) {
    std::cout << nums[size - 1] << std::endl;
    readArr(nums, size - 1);
  }
}
int main() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  readArr(numbers, 10);
  return 0;
}
