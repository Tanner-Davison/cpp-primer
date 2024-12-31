#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main() {
  string line;
  string current_word;
  vector<string> duplicates;
  while (getline(cin, line) && !line.empty()) {
    stringstream s(line);
    string prev;
    while (s >> current_word) {
      if (prev.empty() && !current_word.empty()) {
        prev = current_word;
      } else if (!prev.empty() && !current_word.empty()) {
        if (current_word == prev) {
          duplicates.emplace_back(current_word);
          prev = current_word;
        }
        prev = current_word;
      }
    }
  }
  cout << "Duplicate(s) Found: ";
  for (string &word : duplicates) {
    cout << word << ", ";
  }

  return 0;
}
