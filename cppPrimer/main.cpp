#include <iostream>
using namespace std;
void print(const int arr[], const int &len) {
  for (int i = 0; i < len; ++i) {
    cout << arr[i] << endl;
  }
}

int main() {
  float num, num2;
  int numP[19] = {1};
  const int numPLength = 19;
  for (int i = 0; i < 19; ++i) {
    numP[i] = i;
  }
  print(numP, numPLength);
  while (cin >> num >> num2) {
    try {
      if (num2 == 0)
        throw runtime_error("ERROR! -> Attempted to divide by 0");
      cout << num << " / " << num2 << " = " << (num / num2) << endl;
    } catch (runtime_error &err) {
      cout << err.what() << "\nTry again? y or n\n";
      char rsp;
      cin >> rsp;
      if (rsp == 'n' || !rsp) {
        break;
      }
    }
  }
  cout << "Working" << endl;

  return 0;
}
