#include <iostream>
using namespace std;

std::string::size_type find_char(const string &s, char c,
                                 string::size_type &occurs) {
  auto ret = s.size();
  for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
      if (ret == s.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}
int main() {

  string testing = "hello world I am testing a theory";
  string::size_type occurs = 0;

  cout << "First Occurence: " << find_char(testing, 'd', occurs)
       << " Letters in.\nTotal occurences: " << occurs << endl;

  return 0;
}
