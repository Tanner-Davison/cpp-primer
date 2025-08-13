// chapter 8 streams
// Standard library headers (alphabetical order)
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// Local/project headers
#include "./utils.h"
void update_winner(const std::vector<std::string> &saved) {
  std::string winner = "";
  static std::size_t top_count = 0;
  const std::list<char> ascenders{'b', 'd', 'f', 'h', 'k', 'l', 't'};
  const std::list<char> descenders{'g', 'j', 'p', 'q', 'y'};

  for (const auto &word : saved) {
    if (word.size() < top_count) {
      continue;
    }
    bool has_either = false;
    for (const char c : word) {
      if (std::find(descenders.begin(), descenders.end(), c) !=
              descenders.end() ||
          std::find(ascenders.begin(), ascenders.end(), c) != ascenders.end()) {
        has_either = true;
        break;
      }
    }
    if (has_either) {
      continue;
    } else {
      winner = word;
      top_count = word.size();
    }
  }
  auto display = !winner.empty() ? winner : "empty";
  std::cout << "\nCurrent Winner: [ " << display << " ]\n" << std::flush;
}
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

  std::cout << "\nfound numbers: (";
  for (const char c : nums) {
    std::cout << c << ",";
  }
  std::cout << ")";

  std::cout << "\nfound letters: (";
  for (const char c : letters) {
    std::cout << c;
  }
  std::cout << ")";
}
int main(int argc, char *argv[]) {
  std::string default_file = "../../text-files/input_add_item.txt";
  std::ifstream inFile;
  if (argc < 2) {
    std::cout << "No filename provided. Using default file: " << default_file
              << std::endl;
    inFile.open(default_file);
  } else {
    inFile.open(argv[1]);
  }
  if (!inFile) {
    std::cerr << "Failed to open file. Attempted paths:" << std::endl;
    if (argc >= 2)
      std::cerr << " - " << argv[1] << std::endl;
    std::cerr << " - " << default_file << std::endl;
    throw std::runtime_error("No input file found or nonexistent default file");
  }

  std::vector<std::string> saved;
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
      clearScreen();
      std::cout << "Could not recognize input would you like to keep line? "
                   "('y', 'n')\n\t"
                << line << std::endl;

      std::cin >> input;
    } else if (input == 'y' || input == 'Y') {
      saved.emplace_back(line);
    } else {
      unsaved.emplace_back(line);
    }
    clearScreen();
    update_winner(saved);
  }
  std::cout << "\n-------END OF FILE-------\n"
            << "\nYour saved Values: " << std::endl;
  for (const auto &l : saved) {
    std::cout << l << ", " << std::endl;
  }
  std::cout << "\nYour deleted values: ";
  for (const auto &l : unsaved) {
    std::cout << l << ", " << std::endl;
  }
  std::string my_line = "T8a3nn34er i542s s343u245p2332e33r 43s323e87x97y";
  std::string nums("0123456789");
  find_nums(nums, my_line);
  return 0;
}
