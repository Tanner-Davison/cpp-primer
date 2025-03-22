#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::ifstream inFile;
  inFile.open(argv[1]);
  if (!inFile) {
    std::cout << argc << ": args" << std::endl;
    throw std::runtime_error("No input file found");
  }
  std::vector<std::string> lines;
  std::vector<std::string> unsaved;
  std::string line;
  while (getline(inFile, line)) {
    char input;
    if (!line.empty()) {
      std::cout << line << "\n\t Keep line? (y || n)" << std::endl;
      std::cin >> input;
      if (input == 'y' || input == 'Y') {
        lines.emplace_back(line);
        system("cls");
      } else {
        unsaved.emplace_back(line);
        continue;
      }
    } else {
      std::cout << "\nEnd of file -------->" << std::endl;
      break;
    }
  }
  std::cout << "\nYour saved Values: " << std::endl;
  ;
  for (auto l : lines) {
    std::cout << l << ", " << std::endl;
  }
  std::cout << "\nYour deleted values: ";
  for (auto l : unsaved) {
    std::cout << l << ", " << std::endl;
  }
  return 0;
}
