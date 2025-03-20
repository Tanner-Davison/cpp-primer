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
    std::cout << "Printing Args: \n";
    for (int i = 0; i < static_cast<int>(args.size()); ++i) {
      std::cout << std::setw(10) << args.at(i) << std::endl;
    }

  } catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::string> mainArgs(argv, argv + argc);
  print_args(mainArgs);

  return 0;
}
