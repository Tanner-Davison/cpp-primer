#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int cap_value = 100;

  auto add = [](const int num, const int num2) { return num + num2; };
  auto sum_lambda = [cap_value](const int num) { return num + cap_value; };

  cout << add(2, 4) << endl;
  cout << sum_lambda(50) << endl;

  return 0;
}
