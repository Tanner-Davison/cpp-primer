#include "C.hpp"
#include "NoDefault.hpp"
#include <iostream>
#include <sstream>
#include <vector>

int main() {
  std::string myString = "Tanner 19 6'5 awesome";
  std::string name, age, height, type;
  std::istringstream iss(myString);
  iss >> name >> age >> height >> type;

  std::vector<Tracker> vec(10);
  for (auto &n : vec) {
    std::cout << n.get_id() << std::endl;
  }
  std::cout << "name: " << name << "\nage: " << age << "\nheight: " << height
            << "\ntype: " << type << std::endl;
  return 0;
}
