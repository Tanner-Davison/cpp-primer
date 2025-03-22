#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::ifstream inFile(argv[1]);
  if (!inFile) {
    throw std::runtime_error("No input file found");
  }
  std::vector<std::string> lines;
  std::vector<std::string> unsaved;
  std::string line;
  while (getline(inFile, line)) {
    if (line.empty()) {
      continue;
    }
    char input;
    std::cout << line << "\n\t Keep line? (y || n)" << std::endl;
    std::cin >> input;
    if (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
      system("cls");
      std::cout << "Could not recognize input would you like to keep line? "
                   "('y', 'n')\n\t"
                << line << std::endl;

      std::cin >> input;
    } else if (input == 'y' || input == 'Y') {
      lines.emplace_back(line);
    } else {
      unsaved.emplace_back(line);
    }
    system("cls");
  }
  std::cout << "\n-------END OF FILE-------\n"
            << "\nYour saved Values: " << std::endl;
  ;
  for (const auto &l : lines) {
    std::cout << l << ", " << std::endl;
  }
  std::cout << "\nYour deleted values: ";
  for (const auto &l : unsaved) {
    std::cout << l << ", " << std::endl;
  }
  return 0;
}
