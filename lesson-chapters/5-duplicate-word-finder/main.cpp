#include <cctype>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int main() {
  string line = "";
  string current_word = "";
  std::list<std::string> duplicates;
  cout << "Uppercase / Any type u or a\n";
  char resp;
  string input;
  try {
    cin >> resp;
    cin.ignore();
    if (resp != 'a' && resp != 'u') {
      throw runtime_error("Must set boundry!");
    } else {
      cout << "\nBoundry set!\n";
    }
  } catch (runtime_error &err) {
    cout << err.what() << endl;
  }
  while (getline(cin, line) && !line.empty()) {
    stringstream s(line);
    string prev;
    while (s >> current_word) {
      if (!current_word.empty() && current_word != prev) {
        prev = current_word;
      } else if (resp == 'u' && current_word == prev &&
                 !std::isupper(current_word[0])) {
        continue;
      } else {
        duplicates.emplace_back(current_word);
        prev = current_word;
      }
    }
  }
  if (!duplicates.empty()) {
    duplicates.unique();
    cout << "Duplicate(s) Found: ";
    for (string &word : duplicates) {
      cout << word << ", ";
    }

  } else {
    std::cout << "No duplicates found!" << std::endl;
  }

  return 0;
}
