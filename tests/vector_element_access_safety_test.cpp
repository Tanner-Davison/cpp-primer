// Problem:
// Write a program that Fetches the first element in a vector using at, the
// subscript operator, front and begin. Test your program on an empty vector;
//
#include <iostream>
#include <vector>

void fetch_first(std::vector<int> &test_vec) {
  // Using []
  try {
    if (!test_vec.empty()) {
      std::cout << "\nUsing Subscript Operator: " << test_vec[0] << std::endl;
    } else {
      std::cout << "Using Subscript operator []: \n\t--Undefined Behavior for "
                   "empty vector";
      // no bounds check here ^
    }
  } catch (const std::exception &e) {
    std::cout << "Error with []: " << e.what() << std::endl;
  }
  // Using front()
  try {
    if (!test_vec.empty()) {
      std::cout << "Using front(): " << test_vec.front() << std::endl;
    } else {
      std::cout << "Using front(): Undefined behavior for empty vector!"
                << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << "Error with front(): " << e.what() << std::endl;
  }
  // Using at()
  try {
    std::cout << "Using at(): \n" << test_vec.at(0) << std::endl;
  } catch (const std::exception &e) {
    std::cout << "\t--Error with at(): " << e.what() << std::endl;
  }
  // Using begin()
  try {
    if (!test_vec.empty()) {
      std::cout << *test_vec.begin() << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << "Error with iterator begin(): " << e.what() << std::endl;
  }
  std::cout << "---------------------------------" << std::endl;
}

// main
int main() {
  std::vector<int> empty;
  std::cout << "Testing with an empty vector: \n" << std::endl;
  fetch_first(empty);
  std::vector<int> non_empty{47, 74, 128};
  std::cout << "\nTesting with non-empty vec: \n\t Vector: [ ";
  for (const auto &elem : non_empty) {
    std::cout << elem << ", ";
  }
  std::cout << " ]" << std::endl;
  fetch_first(non_empty);

  return 0;
}
