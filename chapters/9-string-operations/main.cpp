#include <exception>
#include <iomanip>
#include <iostream>
#include <vector>
// program creates a vector container to hold mains arguments
// has an out of bounds in case the loop trys to access elements in vector which
// do not exist example of how .at() throws and how std::out_of_range catches
//

void print_args(std::vector<std::string> &args) {
  try {
    std::cout << "main() args: ";
    for (int i = 0; i < static_cast<int>(args.size()); ++i) {
      std::cout << std::setw(10) << args.at(i);
    }

  } catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n" << std::endl;
  ;
}
void three_strings(std::string &str1, std::string &oldVal,
                   std::string &newVal) {
  auto startPos = str1.find(oldVal);
  // checks if the string was found at all
  if (startPos != std::string::npos) {
    str1.replace(startPos, oldVal.length(), newVal);
  } else {
    std::cout << "Old Value: not found" << std::endl;
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::string> mainArgs(argv, argv + argc);
  print_args(mainArgs);
  // main begins
  std::string str = "This is a testing string";
  const char *cstr = "This is a null terminated string";
  char nonull[] = {'h', 'k'};

  std::string view(str, 10, 7);
  std::string view2(str, str.length() - 6, 6);
  std::string view3(nonull, 2);
  std::cout << view << " " << view2 << "+" << view3 << std::endl;
  std::vector<char> strVec{'H', 'E', 'L', 'L', 'O'};
  std::string test(strVec.begin(), strVec.end());
  std::cout << test << std::endl;
  std::string subbed = test.substr(test.size() - test.size(), test.size() - 1);
  subbed.insert(subbed.size(), 5, '!');
  std::cout << subbed << std::endl;
  subbed.replace(subbed.size() - 6, 1, "P");
  std::cout << subbed << std::endl;
  subbed.insert(subbed.size() / 2, " ( Awesome ) ");
  auto start = view.begin();
  view.insert(start, {'-', '_', '-', '_'});
  std::cout << view << std::endl;
  std::string value = "The big brown fox jumped over the basket";
  std::cout << "initial string: " << value << "\n" << std::endl;
  std::string old_val = "brown fox";
  std::string new_value = "stupid kid";
  three_strings(value, old_val, new_value);

  std::cout << "changed string with function: \n\t" << value << std::endl;
  return 0;
}
