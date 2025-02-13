#include <iostream>
#include <vector>

int add(int num1, int num2) { return (num1 + num2); };
int subtract(int num1, int num2) { return (num1 - num2); };
int multiply(int num1, int num2) { return (num1 * num2); };
int divide(int num1, int num2) { return (num1 / num2); };

typedef int (*mathops)(int, int);

int main() {

  std::vector<mathops> ops = {add, subtract, multiply, divide};

  std::cout << ops[0](2, 2) << std::endl;

  return 0;
}
