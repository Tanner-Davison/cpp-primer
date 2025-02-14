#include <iostream>
#include <vector>

// Section 6.7
// Create 4 functions Add, Subtract, Multiply, Divide
int add(int num1, int num2) { return (num1 + num2); };
int subtract(int num1, int num2) { return (num1 - num2); };
int multiply(int num1, int num2) { return (num1 * num2); };
int divide(int num1, int num2) { return (num1 / num2); };

// typedef int (*mathops)(int, int);
using mathops = int (*)(int, int);

// passing pointer functions to functions
int callback(int num1, int num2, int (*func_cb)(int, int)) {
  return func_cb(num1, num2);
}

int main() {

  std::vector<mathops> ops = {add, subtract, multiply, divide};
  int num1 = 10;
  int num2 = 20;
  for (std::vector<mathops>::iterator it = ops.begin(); it != ops.end(); ++it) {
    std::cout << "Total: " << (*it)(num2, num1) << std::endl;
  }
  std::cout << "Callback() = " << callback(num1, num2, ops[0]);
  return 0;
}
