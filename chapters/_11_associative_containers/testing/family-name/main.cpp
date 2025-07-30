#include <iostream>
#include <map>
#include <string>
#include <vector>

void setFamilyName(std::istream &input, std::string &name) {
  std::cout << "Enter family name: " << std::endl;
  std::getline(input, name);
}

void setChildren(std::istream &input,
                 std::vector<std::string> &children_container) {
  std::string child_name;
  std::cout << "Enter children names (empty line to stop):\n";
  while (std::getline(input, child_name) && !child_name.empty()) {
    children_container.push_back(child_name);
  }
}

void addChildToFamily(auto &families) {
  std::string last_name, child_name;

  std::cout << "Enter family name to add child to: ";
  std::getline(std::cin, last_name);

  if (families.find(last_name) != families.end()) {
    std::cout << "Enter child name: ";
    std::getline(std::cin, child_name);
    families[last_name].emplace_back(child_name);
    std::cout << "Child added successfully!\n";
  } else {
    std::cout << "Family not found!\n";
  }
}

int main() {
  std::map<std::string, std::vector<std::string>> families;
  int choice;

  while (true) {
    std::cout << "\n1. Add new family\n";
    std::cout << "2. Add child to existing family\n";
    std::cout << "3. Display all families\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose option: ";

    std::cin >> choice;
    std::cin.ignore(); // Clear newline

    if (choice == 1) {
      // Add new family
      std::string family_name;
      std::vector<std::string> children;
      setFamilyName(std::cin, family_name);
      setChildren(std::cin, children);
      families[family_name] = children;
      std::cout << "Family added!\n";

    } else if (choice == 2) {
      // Add child to existing family
      addChildToFamily(families);

    } else if (choice == 3) {
      // Display families
      for (const auto &[last, children] : families) {
        std::cout << "Family: " << last << std::endl;
        for (const auto &child : children) {
          std::cout << "  Child: " << child << std::endl;
        }
      }

    } else if (choice == 4) {
      break;
    }
  }

  return 0;
}
