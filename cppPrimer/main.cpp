#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {

  string rsp;
  do {
    cout << "Enter 2 numbers to sum " << endl;
    int num1, num2;
    cin >> num1 >> num2;
    cout << "\n Result of " << num1 << " + " << num2 << " = " << (num1 + num2)
         << "\n";
    cout << "\ntype yes/no... ";
    cin >> rsp;

  } while (!rsp.empty() && rsp[0] != 'n');

  return 0;
}
