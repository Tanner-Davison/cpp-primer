#include <expected>
#include <iostream>

using std::expected;

expected<int, std::string> Divide(int a, int b) {
  if (b == 0) {

    return std::unexpected("Divide by zero");
  }
  return (a / b);
}
int main() {
  auto value = Divide(5, 0);
  if (value.has_value()) {
    std::cout << "Result: " << value.value() << std::endl;
  } else {
    std::cout << "Error: " << value.error() << std::endl;
  }
  return 0;
}
