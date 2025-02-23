#include "./Tracker.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

int main() {
  std::mt19937 mt{static_cast<std::mt19937::result_type>(
      std::chrono::steady_clock::now().time_since_epoch().count())};
  std::uniform_int_distribution<> die6{1, 6};

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
  std::cout << "roll's dice: " << die6(mt) << std::endl;
  return 0;
}
