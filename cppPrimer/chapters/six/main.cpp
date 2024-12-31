#include <iostream>
using namespace std;
int fact(int num) {
  int ret = 1;
  while (num > 1) {
    ret *= num--;
  }
  return ret;
}

int main() {
  int number{5};
  int factof = fact(number);
  cout << factof << endl;

  return 0;
}
