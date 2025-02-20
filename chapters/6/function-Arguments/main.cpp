// MAIN
#include "Headers/FindString.hpp"
#include <iostream>

using namespace std;

int main() {

  string testing = "hello world I am testing a theory";
  string::size_type occurs = 0;

  cout << "First Occurence: " << find_char(testing, 'd', occurs)
       << " Letters in.\nTotal occurences: " << occurs << endl;

  return 0;
}
