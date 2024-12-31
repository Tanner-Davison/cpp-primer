#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {

  int num1, num2;
  while (cin >> num1 >> num2) {
    try {
      
      cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
      if (num1 + num2 <= 0) {
        throw runtime_error("Addition must be greater than 0");
      }
    } catch (runtime_error err) {
      cout << err.what() << "\n Try again? Enter y or n" << endl;
      char rsp;
      cin >> rsp;
      if (!rsp || rsp == 'n') {
        break;
      }
    }
  }
  return 0;
}
