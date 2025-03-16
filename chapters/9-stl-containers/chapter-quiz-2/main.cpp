// Write a program that Fetches the first element in a vector using at, the
// subscript operator, front and begin. Test your program on an empty vector;
#include <iostream>
#include <vector>
void fetch_first(std::vector<int> &test) {
  // Using []
  try {
    if (!test.empty()) {
      std::cout << "Using Subscript Operator: " << test[0] << std::endl;
    } else {
      std::cout
          << "Using Subscript operator []: Undefined Behavior for empty vector";
      // no bounds check here ^
    }
  } catch (const std::exception &e) {
    std::cout << "Error with []: " << e.what() << std::endl;
  }
  // Using front()
  try {
    if (!test.empty()) {
      std::cout << "Using front(): " << test.front() << std::endl;
    } else {
      std::cout << "Using front(): Undefined behavior for empty vector!"
                << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << "Error with front(): " << e.what() << std::endl;
  }
  // Using at()
  try {
    std::cout << "Using at(): " << test.at(0) << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error with at(): " << e.what() << std::endl;
  }
  // Using begin
  try {
    if (!test.empty()) {
      std::cout << *test.begin() << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << "Error with iterator begin(): " << e.what() << std::endl;
  }
  std::cout << "---------------------------------" << std::endl;
}

// main
int main() {
  std::vector<int> empty;
  std::cout << "Testing with an empty vector: " << std::endl;
  fetch_first(empty);
  std::vector<int> non_empty{47, 74, 128};
  std::cout << "Testing with non-empty vec: " << std::endl;
  fetch_first(non_empty);

  return 0;
}
