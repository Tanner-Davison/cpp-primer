#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

struct Person {
  std::string name;
  std::vector<std::string> phones;
  int get_phone_count() { return phones.size(); };
};
bool valid(const std::string &nums) {
  if (nums.empty())
    return false;

  for (char c : nums) {
    if (!std::isdigit(c) && c != '-') {
      return false;
    }
  }
  return true;
}
std::string formatPhoneNumber(std::string &nums) {
  if (nums.length() == 10) {
    return "(" + nums.substr(0, 3) + ") " + nums.substr(3, 3) + "-" +
           nums.substr(6, 4) + ",";
  }
  return nums;
}
int main() {
  std::string line, word;
  std::vector<Person> people;
  std::ofstream out("logs.txt");
  if (!out) {
    std::cerr << "no output file found!" << std::endl;
  }
  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      break;
    }
    Person person;
    // input
    std::istringstream record(line);
    record >> person.name;
    while (record >> word) {
      person.phones.push_back(word);
    }
    people.push_back(person);
  }

  for (auto &person : people) {
    static int count = 0;
    std::ostringstream formatted, badNums;

    for (auto &nums : person.phones) {
      if (!valid(nums)) {
        badNums << " " << nums;
      } else
        formatted << " " << formatPhoneNumber(nums);
    }
    if (badNums.str().empty()) {
      out << "\nName: " << person.name << " id: " << ++count
          << "\n\tPhones #'s: ";
      out << formatted.str() << "\n\tcount: " << "[" << person.get_phone_count()
          << "]"
          << "\n\n\n";
    } else {
      std::cerr << "Input Error! " << person.name << " invalid number(s) "
                << badNums.str() << std::endl;
    }
  }
  return 0;
}
