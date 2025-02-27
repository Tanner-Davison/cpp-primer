#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
struct Person {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::string line, word;
  std::vector<Person> people;
  std::ofstream out("./logs.txt");

  while (std::getline(std::cin, line)) {
    if (line.empty()) {
      break;
    }
    Person person;
    std::istringstream record(line);
    record >> person.name;
    while (record >> word) {
      person.phones.push_back(word);
    }
    people.push_back(person);
  }
  for (auto &person : people) {
    static int count = 0;
    static int phone_count = 0;
    out << "Index: " << ++count << "\nName: " << person.name
        << "\n\tPhones #'s: ";
    for (auto &number : person.phones) {
      out << number << ", ";
      ++phone_count;
    }
    out << "\n\tTotal Phone Numbers: " << "[" << phone_count << "]" << "\n";
    out << "\n\n";
    phone_count = 0;
  }
  return 0;
}
