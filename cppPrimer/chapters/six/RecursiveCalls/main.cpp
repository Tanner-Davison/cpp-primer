#include <iostream>

void readArr(int nums[], int size) {
  static int id = size;
  std::cout << nums[size] << std::endl;
  if (id != 0) {
    readArr(nums, (--id));
  }
}
int main() {
  std::cout << "Program Starts here -->" << std::endl;
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  readArr(numbers, 10);
  return 0;
}
