#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
void find_nums(const std::string &numbers, const std::string &line) {
  std::list<char> nums;
  std::list<char> letters;
  std::string::size_type pos = 0;
  while ((pos = line.find_first_of(numbers, pos)) != std::string::npos) {
    nums.emplace_back(line[pos]);
    ++pos;
  }
  pos = 0;
  while ((pos = line.find_first_not_of(numbers, pos)) != std::string::npos) {
    letters.emplace_back(line[pos]);
    ++pos;
  }
  nums.sort();
  nums.unique();

  std::cout << "found numbers: (";
  for (const char c : nums) {
    std::cout << c << ",";
  }
  std::cout << ")" << std::endl;
  std::cout << "found letters: (";
  for (const char c : letters) {
    std::cout << c;
  }
  std::cout << ")" << std::endl;
}
// int main(int argc, char *argv[]) {
int main() {
  // if (argc < 2) {
  //   std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
  //   return 1;
  // }
  // std::ifstream inFile(argv[1]);
  std::ifstream inFile("./text-files/input_add_item.txt");
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
  for (const auto &l : lines) {
    std::cout << l << ", " << std::endl;
  }
  std::cout << "\nYour deleted values: ";
  for (const auto &l : unsaved) {
    std::cout << l << ", " << std::endl;
  }
  std::cout << std::endl;
  std::string my_line = "T8a3nn34er i542s s343u245p2332e33r 43s323e87x97y";
  std::string nums("0123456789");
  find_nums(nums, my_line);
  return 0;
}
