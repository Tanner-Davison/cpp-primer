// MAIN
//(hint) compiled with multiple cpp files leader cx
#include "./Headers/FindString.hpp"
#include <iostream>

int main() {

  const std::string testing = "hello world I am testing a theory";
  std::string::size_type occurs = 0;
  char c = 'd';

  std::cout << "First Occurence: " << find_char(testing, c, occurs)
            << " Letters in.\nTotal occurences: " << occurs << std::endl;

  return 0;
}
