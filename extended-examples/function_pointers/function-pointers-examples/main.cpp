#include <iostream>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return (a - b); }
int multiply(int a, int b) { return (a * b); }

int calculate(int a, int b, int (*operation)(int, int)) {
  return operation(a, b);
};

int (*getOperation(char op))(int, int) {
  switch (op) {
  case '+':
    return &add;
  case '-':
    return &subtract;
  case '*':
    return &multiply;
  default:
    return nullptr;
  };
};

int main() {
  int (*func_ptr)(int, int) = getOperation('+');
  int sum = func_ptr(5, 3);

  std::cout << "\nSum: of 5 + 3 = " << sum << std::endl;

  return 0;
}
