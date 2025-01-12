#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void addNum(initializer_list<int> &a) {
  auto beg = a.begin();
  auto end = a.end();
  int total = 0;
  while (beg != end) {
    total += *beg;
    ++beg;
  }
  std::cout << "Total: " << total << endl;
}

void print(const int arr[], const int &len) {
  for (int i = 0; i < len; ++i) {
    cout << arr[i] << endl;
  }
}

int rec(int num) {
  if (num > 1) {
    rec(num - 1);
  }
  return 1;
}
// returns a ref to a string takes in a vector of strings and an index;
string &getElement(vector<string> &arr, int index) { return arr[index]; }
unsigned long long factorial(int num) {
  if (num > 1) {
    return factorial(num - 1) * num;
  }
  return 1;
}
int main(int argc, char *argv[]) {
  std::vector<string> names{"Sally", "Missy", "Johnny", "Kate"};
  getElement(names, 2) = "Tanner";
  cout << names[2] << endl;
  unsigned long long ran = factorial(52);
  cout << ran << endl;
  cout << endl;
  if (argc > 2) {
    std::cout << "Directory: " << argv[1] << std::endl;
  }
  initializer_list<int> iNumbers{1, 2, 3, 4, 5, 6, 6};
  addNum(iNumbers);
  int num, num2;
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
