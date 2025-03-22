#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int start = 0;
  std::vector<int> ivec(500);
  std::iota(ivec.begin(), ivec.end(), ++start);
  std::string rand_str = "rand_str: ";
  std::vector<std::string> strvec{rand_str};
  std::cout << "Initial string vector value: " << std::endl;
  std::cout << "\tCapacity: " << strvec.capacity()
            << "\n\tSize: " << strvec.size() << " \n";

  for (int i = 0; i < 20; ++i) {
    strvec.push_back((rand_str += std::to_string(i)));
  }
  // read string data after loop
  std::cout << "\nString Vector after loop" << std::endl;
  std::cout << "\tCapacity: " << strvec.capacity()
            << "\n\tSize: " << strvec.size() << " \n";

  // initial
  std::cout << "\nInitial vector value: " << std::endl;
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
