#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int start = 0;
  std::vector<int> ivec(500);
  std::iota(ivec.begin(), ivec.end(), ++start);
  std::vector<std::string> strvec;
  // initial
  std::cout << "Initial vector value: " << std::endl;
  std::cout << "\tCapacity: " << ivec.capacity() << "\n\tSize: " << ivec.size()
            << " \n";
  // resize vector
  ivec.resize(50);
  std::cout << "\nAfter resize: " << std::endl;
  std::cout << "\tCapacity: " << ivec.capacity() << "\n\tSize: " << ivec.size()
            << " \n";
  // shrink to fit
  std::cout << "\nAfter Shrink to fit-> \n";
  ivec.shrink_to_fit();
  std::cout << "\tCapacity: " << ivec.capacity() << "\n\tSize: " << ivec.size()
            << " \n";
  // print
  std::cout << "\nPrinted Vector Elements [" << std::endl;
  for (const auto &num : ivec) {
    if (num % 10 == 0) {
      std::cout << std::setw(2) << num << ",\n";
    } else {
      std::cout << std::setw(2) << num << ", ";
    }
  }
  std::cout << "]" << std::endl;
  return 0;
}
