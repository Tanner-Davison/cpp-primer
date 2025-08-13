/*
 * Copyright 2025
 * This file is part of Tanner Davison Intro to  C++
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
  std::cout.flush();
}

class FamilyManager {
private:
  std::map<std::string, std::vector<std::pair<std::string, std::string>>>
      families;

  // Helper function to get birthday input
  std::string getBirthdate() const {
    int choice;
    std::cout << "Add birthdate? (1: YES, 2: NO): ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
      std::string birthdate;
      std::cout << "Enter birthdate: ";
      std::getline(std::cin, birthdate);
      return birthdate;
    }
    return "unset";
  }

public:
  void addFamily() {
    std::string family_name;
    std::cout << "Enter family name: ";
    std::getline(std::cin, family_name);

    // Use try_emplace for better performance and error handling
    auto [it, success] = families.try_emplace(family_name);
    if (!success) {
      std::cout << "Family already exists! Adding to existing family.\n";
    }

    std::string child_name;
    std::cout << "Enter children names (empty line to stop):\n";
    while (std::getline(std::cin, child_name) && !child_name.empty()) {
      std::string birthdate = getBirthdate();
      it->second.emplace_back(std::move(child_name), std::move(birthdate));
    }
    std::cout << "Family " << (success ? "added" : "updated") << "!\n";
  }

  void addChild() {
    std::string family_name, child_name;
    std::cout << "Enter family name to add child to: ";
    std::getline(std::cin, family_name);

    // Use try_emplace to create family if it doesn't exist
    auto [it, created] = families.try_emplace(family_name);

    std::cout << "Enter child name: ";
    std::getline(std::cin, child_name);

    std::string birthdate = getBirthdate();
    it->second.emplace_back(std::move(child_name), std::move(birthdate));

    if (created) {
      std::cout << "New family created and child added successfully!\n";
    } else {
      std::cout << "Child added successfully!\n";
    }
  }

  void updateBirthday() {
    std::string family_name, child_name;
    std::cout << "Look up family: ";
    std::getline(std::cin, family_name);

    auto family_it = families.find(family_name);
    if (family_it == families.end()) {
      std::cout << "Family not found!\n";
      return;
    }

    std::cout << "Available children:\n";
    for (const auto &[name, birthdate] : family_it->second) {
      std::cout << "  " << name << " (Current: " << birthdate << ")\n";
    }

    std::cout << "Which child? ";
    std::getline(std::cin, child_name);

    // Find child using find_if with structured binding in lambda
    auto child_it =
        std::find_if(family_it->second.begin(), family_it->second.end(),
                     [&child_name](const auto &child_pair) {
                       return child_pair.first == child_name;
                     });

    if (child_it != family_it->second.end()) {
      std::string new_birthdate;
      std::cout << "Enter new birthdate: ";
      std::getline(std::cin, new_birthdate);
      child_it->second = std::move(new_birthdate);
      std::cout << "Birthdate updated successfully!\n";
    } else {
      std::cout << "Could not find " << child_name << " in " << family_name
                << "\n";
    }
  }

  void displayFamilies() const {
    if (families.empty()) {
      std::cout << "No families registered.\n";
      return;
    }

    for (const auto &[family_name, children] : families) {
      std::cout << "\nFamily: " << family_name << "\n";
      if (children.empty()) {
        std::cout << "  No children registered.\n";
      } else {
        for (const auto &[child_name, birthdate] : children) {
          std::cout << "  Child: " << child_name << "\n    Born: " << birthdate
                    << "\n";
        }
      }
    }
  }

  void showMenu() const {
    std::cout << "\n=== Family Manager ===\n";
    std::cout << "1. Add new family\n";
    std::cout << "2. Add child to family\n";
    std::cout << "3. Display all families\n";
    std::cout << "4. Update birthdate\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose option: ";
  }

  void run() {
    int choice;
    while (true) {
      showMenu();
      std::cin >> choice;
      std::cin.ignore(); // Clear newline

      clearScreen();

      switch (choice) {
      case 1:
        addFamily();
        break;
      case 2:
        addChild();
        break;
      case 3:
        displayFamilies();
        break;
      case 4:
        updateBirthday();
        break;
      case 5:
        std::cout << "Goodbye!\n";
        return;
      default:
        std::cout << "Invalid choice. Please try again.\n";
      }
    }
  }
};

int main() {
  FamilyManager manager;
  manager.run();
  return 0;
}
