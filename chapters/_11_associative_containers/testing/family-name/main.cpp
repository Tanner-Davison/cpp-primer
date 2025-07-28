#include <iostream>
#include <map>
#include <string>
#include <vector>

void setFamilyName(std::istream &input, std::string &name) {
  std::cout << "Enter a family name: " << std::endl;
  std::getline(input, name);
}

void setChildren(std::istream &input,
                 std::vector<std::string> &children_container) {
  std::string child_name;
  std::cout << "\n Childrens Names: \n" << std::endl;
  while (std::getline(input, child_name) && !child_name.empty()) {
    children_container.push_back(child_name);
  }
}
int main() {

  std::map<std::string, std::vector<std::string>> families;
  int inputing_info = 1;
  while (inputing_info == 1) {
    int response;
    std::cout << "Enter family? (1 for yes, 0 for no)\n" << std::endl;
    std::cin >> response;
    std::cin.ignore();
    if (response == 1) {

      std::string family_name;
      std::vector<std::string> children;

      setFamilyName(std::cin, family_name);
      setChildren(std::cin, children);

      families[family_name] = children;
    } else {
      inputing_info = 0;
    }
  }
  for (const auto &family : families) {
    std::cout << "Family: " << family.first << std::endl;
    for (const auto &child : family.second) {
      std::cout << "  Child: " << child << std::endl;
    }
  }
  return 0;
}
