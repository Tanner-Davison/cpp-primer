#include <cassert>
#include <iostream>
#define DEBUG

void readArr(int nums[], size_t size) {
  static size_t start = size;
  if (size > 0) {
    std::cout << nums[size - 1] << std::endl;
    readArr(nums, size - 1);
  }
  if (size == 0) {
#ifdef DEBUG
    std::cerr << "arr size : " << start << "\n@ Line # " << __LINE__
              << "\nDate: " << __DATE__
              << "\nFinal Iteration completed at : " << __TIME__ << std::endl;
#endif
  }
}

int main() {
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  readArr(numbers, 10);

  return 0;
}
