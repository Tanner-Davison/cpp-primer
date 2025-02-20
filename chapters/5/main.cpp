#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// Test for duplicates words in input stream
using namespace std;
int main() {
  string line = "";
  string current_word = "";
  vector<string> duplicates;
  cout << "Uppercase / Any type u or a\n";
  char resp;
  string input;
  try {
    cin >> resp;
    cin.ignore();
    // getline(cin, input);       This way also works
    // resp = input[0];           This way also works
    if (!resp || (resp != 'a' && resp != 'u')) {
      throw runtime_error("Must set boundry!");
    } else {
      cout << "\nBoundry set!\n";
    }
  } catch (runtime_error err) {
    cout << err.what() << endl;
  }
  while (getline(cin, line) && !line.empty()) {
    stringstream s(line);
    string prev;
    while (s >> current_word) {
      if (!current_word.empty() && current_word != prev) {
        prev = current_word;
      } else {
        switch (resp) {
        case 'u':
          if (!std::isupper(current_word[0]) && current_word == prev) {
            break;
          }
        default:
          duplicates.emplace_back(current_word);
          prev = current_word;
        }
      }
    }
  }
  cout << "Duplicate(s) Found: ";
  for (string &word : duplicates) {
    cout << word << ", ";
  }

  return 0;
}
