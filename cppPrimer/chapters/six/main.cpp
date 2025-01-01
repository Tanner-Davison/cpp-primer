#include <iostream>
using namespace std;
int fact(int num) {
  int ret = 1;
  while (num > 1) {
    ret *= num--;
  }
  return ret;
}
unsigned int abs(unsigned int num) { return num; }
int main() { // --< start
  int factOfFive = fact(5);
  int factOfFour = fact(4);
  int total = factOfFive * factOfFour;
  cout << total;
  int myabs = -100;
  cout << abs(myabs) << endl;
  return 0;
}
