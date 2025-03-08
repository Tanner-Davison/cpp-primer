#include <iostream>
#include <vector>

int main() {
  // const Char * to " " literals adds a null terminating character at the end
  // \0;
  //
  //
  // example
  std::vector<const char *> cPtrs{"Tanner", "Andrew", "Nathan",
                                  "Nate",   "Eear",   "Rapper"};
  for (auto &word : cPtrs) {
    for (int i = 0; word[i] != '\0'; ++i) {
      std::cout << word[i];
    }
    std::cout << std::endl;
  }
  return 0;
}
