#include <iostream>
using namespace std;
int main() {
  string input1;
  while (cin >> input1 && !input1.empty() && input1 != "n") {
    switch (input1[0]) {
    case '-':
      for (auto it = input1.begin() + 1; it != input1.end(); ++it) {
        if (*it == ' ')
          break;
        cout << *it;
      }
    case 't':
      for (auto it = input1.begin() + 1; it != input1.end(); ++it) {
        if (*it == 'x') {
          break;
        }
      }
    }
  }
  return 0;
}
