// String to numeric conversions
#include <iostream>
#include <string>

int main() {
  // String conversion examples
  std::string s2 = "pi = 3.84";

  // Extract and convert to double
  double d = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));

  // Extract and convert to int
  int intstr = std::stoi(s2.substr(s2.find_first_of("0123456789")));

  std::cout << "Original string: " << s2 << std::endl;
  std::cout << "Extracted double: " << d << std::endl;
  std::cout << "Extracted int: " << intstr << std::endl;

  return 0;
}
