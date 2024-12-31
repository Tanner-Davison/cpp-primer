#include <iostream>
using namespace std;

int main() {
  float num, num2;
  while (cin >> num >> num2) {
    try {
      if (num2 == 0)
        throw runtime_error("ERROR! -> Attempted to divide by 0");
      cout << num << " / " << num2 << " = " << (num / num2) << endl;
    } catch (runtime_error err) {
      cout << err.what() << "\nTry again? y or n\n";
      char rs;
      cin >> rs;
      if (rs == 'n' || !rs) {
        break;
      }
    }
  }
  return 0;
}
