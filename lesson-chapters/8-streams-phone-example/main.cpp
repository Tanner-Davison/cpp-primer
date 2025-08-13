// this file is included in /projects as name-and-phone-adder
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;

struct Person {
  std::string name;
  std::vector<std::string> phones;
  std::vector<std::string> bad_numbers;

  unsigned int get_phone_count() {
    int psize = phones.size();
    int bsize = bad_numbers.size();
    if (psize > bsize) {
      return (psize - bsize);
    } else {
      return (bsize - psize);
    }
  };
  int get_invalid_count() { return (bad_numbers.size()); }
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
std::string formatPhoneNumber(const std::string &nums) {
  if (nums.length() == 10) {
    return "(" + nums.substr(0, 3) + ") " + nums.substr(3, 3) + "-" +
           nums.substr(6, 4) + ",";
  }
  return nums;
}
int main() {
  string line, word;
  std::vector<Person> people;
  std::ofstream out("logs.txt");
  if (!out) {
    std::cerr << "no output file found!" << std::endl;
  }
  std::cout << "\nHello, Please add name first then phone numbers "
               "\nCheck output logs.txt for result once finished inputing info."
               "\nExample:[ Tanner "
               "8018575996 3223458493 ]\n"
            << std::endl;
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
        badNums << " " << nums << ",";
      } else
        formatted << " " << formatPhoneNumber(nums);
    }
    if (badNums.str().empty()) {
      std::cout << "[" << person.name
                << " input success] Check output logs for saved results!"
                << std::endl;
      out << "\n[id: " << ++count << "]\n"
          << "Name: " << person.name << "\n\t[" << person.get_phone_count()
          << "] phone #'s: \n\t[" << formatted.str() << "]\n"
          << "----------------------------" << "\n";
    } else {
      std::cerr << "input error! " << person.name << " invalid number(s) "
                << badNums.str() << std::endl;
      person.bad_numbers.push_back(badNums.str());
      out << "\nName: " << person.name << " id: " << ++count << "\n["
          << person.get_phone_count()
          << "] Phone Number(s): " << formatted.str() << "\n\t"
          << "\n(" << person.get_invalid_count()
          << ")Error! invalid numbers: [ " << badNums.str() << " ]\n"
          << "----------------------------" << "\n";
    }
  }
  return 0;
}
