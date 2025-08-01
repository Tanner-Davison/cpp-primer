// Algorithms and custom search functions
#include <algorithm>
#include <iostream>
#include <vector>

// Custom find template function
template <typename T>
typename std::vector<T>::iterator find_(typename std::vector<T>::iterator begin,
                                        typename std::vector<T>::iterator end,
                                        const T &target) {
  return std::find(begin, end, target);
}

int main() {
  std::vector<std::string> lookup_lib{"hello", "Tom", "Ransom", "Ben",
                                      "Tougher"};
  std::vector<int> nums{3, 4, 5, 2, 1, 6, 8, 7};

  // Search for integer
  auto numTarget = find_<int>(nums.begin(), nums.end(), 3);
  if (numTarget == nums.end()) {
    std::cout << "Target number not found" << std::endl;
  } else {
    std::cout << "Target number [" << *numTarget << "] found!" << std::endl;
  }

  // Search for string
  auto result = find_<std::string>(lookup_lib.begin(), lookup_lib.end(), "Ben");
  if (result == lookup_lib.end()) {
    std::cout << "Target string not found." << std::endl;
  } else {
    std::cout << "Target string [" << *result << "] found!" << std::endl;
  }

  return 0;
}
