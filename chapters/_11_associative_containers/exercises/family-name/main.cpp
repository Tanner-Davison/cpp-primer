#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
  std::cout.flush();
}
void setFamilyName(std::istream &input, std::string &name) {
  std::cout << "Enter family name: " << std::endl;
  std::getline(input, name);
}

void setChildren(
    std::istream &input,
    std::vector<std::pair<std::string, std::string>> &children_container) {

  std::string child_name, birthdate;
  int input_response;
  std::cout << "Enter children names (empty line to stop):\n";
  while (std::getline(input, child_name) && !child_name.empty()) {
    std::cout << "add birthdate? (enter 1 :YES, 2 :NO)" << std::endl;
    std::cin >> input_response;
    std::cin.ignore();
    if (input_response == 1) {
      std::cin >> birthdate;
      std::cin.ignore();
    } else {
      birthdate = "unset";
    }
    children_container.push_back({child_name, birthdate});
  }
}

void addChildToFamily(auto &families) {
  std::string last_name, child_name, birthdate;
  int input_response;
  std::cout << "Enter family name to add child to: ";
  std::getline(std::cin, last_name);

  if (families.find(last_name) != families.end()) {
    std::cout << "Enter child name: ";
    std::getline(std::cin, child_name);
    std::cout << "add birthdate? (enter 1 :YES, 2 :NO)" << std::endl;
    std::cin >> input_response;
    std::cin.ignore();
    if (input_response == 1) {
      std::cin >> birthdate;
      std::cin.ignore();
    } else {
      birthdate = "unset";
    }
    families[last_name].emplace_back(child_name, birthdate);
    std::cout << "Child added successfully!\n";
  } else {
    std::cout << "Family not found!\n";
  }
}
void update_birthday(auto &families) {
  std::string familyName, child, birthdate;
  std::cout << "Look up family: ";
  std::cin >> familyName;
  auto family = families.find(familyName);
  if (family != families.end()) {
    std::cout << "which child?" << std::endl;
    for (const auto &children : family->second) {
      std::cout << children.first << std::endl;
    }
    std::cin >> child;
    std::cin.ignore();

    // find child in famly->second (vector) of children
    auto child_it = std::find_if(
        family->second.begin(), family->second.end(),
        [&child](const auto &pair) { return pair.first == child; });

    if (child_it != family->second.end()) {
      std::cout << "Enter birthdate: ";
      std::getline(std::cin, birthdate);
      child_it->second = birthdate;
      std::cout << "\n Birthdate update success!" << std::endl;
    }

  } else {
    std::cout << "could not find: " << child << " in " << familyName
              << std::endl;
  }
}

int main() {
  std::map<std::string, std::vector<std::pair<std::string, std::string>>>
      families;
  int choice;

  while (true) {
    std::cout << "\n1. Add new family\n";
    std::cout << "2. Add child to existing family\n";
    std::cout << "3. Display all families\n";
    std::cout << "4. Update birthdate\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose option: ";

    std::cin >> choice;
    std::cin.ignore(); // Clear newline

    if (choice == 1) {
      // Add new family
      clearScreen();
      std::string family_name;
      std::vector<std::pair<std::string, std::string>> children;
      setFamilyName(std::cin, family_name);
      setChildren(std::cin, children);
      families[family_name] = children;
      std::cout << "Family added!\n";

    } else if (choice == 2) {
      // Add child to existing family
      clearScreen();
      addChildToFamily(families);

    } else if (choice == 3) {
      // Display families
      clearScreen();
      for (const auto &[last, children] : families) {
        std::cout << "\nFamily: \n" << last << std::endl;
        for (const auto &[child, birthdate] : children) {
          std::cout << "  Child: " << child << "\n\t Born: " << birthdate
                    << std::endl;
        }
      }

    } else if (choice == 4) {
      // update birthdate
      update_birthday(families);
    } else if (choice == 5) {
      break;
    }
  }

  return 0;
}
