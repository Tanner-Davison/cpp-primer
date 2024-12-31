#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main() {
  string line;
  string current_word = "";
  vector<string> duplicates;
  while (getline(cin, line) && !line.empty()) {
    stringstream s(line);
    string prev;
    while (s >> current_word) {
      if (!current_word.empty() && current_word != prev) {
        prev = current_word;
      } else {
        if (std::isupper(current_word[0])) {
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
