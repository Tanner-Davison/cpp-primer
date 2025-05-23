#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> iv{1, 2, 3, 4, 5, 6};
  std::vector<int>::iterator iter = iv.begin();
  int some_value = 3;

  while (iter != iv.begin() + iv.size() / 2) {
    if (*iter == some_value) {
      iter = iv.insert(
          iter,            // this line is important iter returns the pointer
          2 * some_value); // returned by insert to keep the iterator validated

      break;
    } else {
      ++iter;
    }
  }

  for (auto &num : iv) {
    std::cout << num << ", ";
  }

  return 0;
}
