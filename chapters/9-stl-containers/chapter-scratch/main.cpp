#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> iv{1, 2, 3, 4, 5, 6};
  std::vector<int>::iterator iter = iv.begin(),
                             mid = (iv.begin() + iv.size() / 2);

  int some_value = 3;

  while (iter != mid) {
    if (*iter == some_value) {
      iter = iv.insert(iter, 2 * some_value);
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
