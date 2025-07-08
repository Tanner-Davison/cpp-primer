#include <iostream>
#include <vector>
using namespace std;

// functor
bool isEqual(int x, int y) { return x == y; }

// regular function
struct isOdd {
  bool operator()(int x) { return x % 2; }
};
struct isEven {
  bool operator()(int x) { return x % 2 == 0; }
};

int main() {
  // functor
  isOdd fn;
  cout << "~functor example~ \nfn(5) = " << boolalpha << fn(5) << endl;

  // regular function
  cout << "\n~reg function example~ \nisEqual(5,5) = " << boolalpha
       << isEqual(5, 5) << endl;

  std::vector<int> col1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "\nOdd Values: " << count_if(begin(col1), end(col1), isOdd()) << endl;
  cout << "\nEven Values:" << count_if(begin(col1), end(col1), isEven())
       << endl;

  return 0;
}
