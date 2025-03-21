#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string_view>
#include <vector>

// Print command line arguments, demonstrating exception handling
void print_args(const std::vector<std::string> &args) {
  try {
    std::cout << "Command line args: ";
    for (int i = 0; i < static_cast<int>(args.size()); ++i) {
      std::cout << std::setw(10) << args.at(i);
    }
    std::cout << std::endl;
  } catch (const std::out_of_range &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;
}

// Replace first occurrence of oldVal in str1 with newVal
void replace_substring(std::string &str1, const std::string &oldVal,
                       const std::string &newVal) {
  auto startPos = str1.find(oldVal);
  if (startPos != std::string::npos) {
    str1.replace(startPos, oldVal.length(), newVal);
  } else {
    std::cout << "Old value \"" << oldVal << "\" not found in string"
              << std::endl;
  }
}

int main(int argc, char *argv[]) {
  // Store command line arguments in vector
  std::vector<std::string> mainArgs(argv, argv + argc);
  print_args(mainArgs);

  // String creation examples
  std::string str = "This is a testing string";
  char nonull[] = {'h', 'k'};

  // String views and substrings
  std::string view(str, 10, 7);                // Substring: "testing"
  std::string view2(str, str.length() - 6, 6); // Substring: "string"
  std::string view3(nonull, 2);                // Char array to string: "hk"
  std::cout << "Substrings: " << view << " " << view2 << "+" << view3
            << std::endl;

  // Create string from vector of chars
  std::vector<char> strVec{'H', 'E', 'L', 'L', 'O'};
  std::string test(strVec.begin(), strVec.end());
  std::cout << "String from vector: " << test << std::endl;

  // String manipulation: substring, insert, replace
  std::string subbed = test.substr(0, test.size() - 1); // "HELL"
  subbed.insert(subbed.size(), 5, '!');                 // "HELL!!!!!"
  std::cout << "After insert: " << subbed << std::endl;

  subbed.replace(subbed.size() - 6, 1, "P"); // "HELP!!!!!"
  std::cout << "After replace: " << subbed << std::endl;

  subbed.insert(subbed.size() / 2, " ( Awesome ) "); // "HEL ( Awesome ) P!!!!!"
  std::cout << "After insert at middle: " << subbed << std::endl;

  // String insertion at beginning
  auto start = view.begin();
  view.insert(start, {'-', '_', '-', '_'}); // "-_-_testing"
  std::cout << "After insert at beginning: " << view << std::endl;

  // String replacement using function
  std::string value = "The big brown fox jumped over the basket";
  std::cout << "Initial string: " << value << std::endl;

  std::string old_val = "brown fox";
  std::string new_value = "stupid kid";
  replace_substring(value, old_val, new_value);
  std::cout << "After replacement: " << value << std::endl;

  // String_view examples
  const char *char_test = "This is a testing string of const char pointers";
  std::string name = "Tanner Davison";

  // Using string_view with specific length
  std::string_view firstname(name.c_str(), 7); // "Tanner "

  // Using iterator with find and string_view
  auto it = std::find(name.begin(), name.end(), 'D');
  auto end = name.end();
  std::string_view lastname(it, end); // "Davison"

  // String_view from char pointer with length
  std::string_view strview(char_test, 5); // "This "

  // Display results
  std::cout << "\nString_view examples:" << std::endl;
  std::cout << "First name: " << firstname << std::endl;
  std::cout << "Last name: " << lastname << std::endl;
  std::cout << "With std::quoted: " << std::quoted(strview) << std::endl;

  return 0;
}
