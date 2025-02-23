#include "./Tracker.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

int main() {

  std::cout << "TRACKING STARTS HERE--->" << std::endl;
  Tracker tracker;
  std::cout << "tracker: " << tracker.get_id() << " instances" << std::endl;
  Tracker tracker2;
  std::cout << "tracker_2: " << tracker2.get_id() << " instances" << std::endl;
  Tracker *t_ptr = tracker.get_tracker_ptr();
  std::cout << "ptr_1: " << t_ptr->get_id() << " pointer instances"
            << std::endl;
  Tracker *t_ptr2 = tracker2.get_tracker_ptr();
  std::cout << "ptr_2: " << t_ptr2->get_id() << " pointer instances"
            << std::endl;
  Tracker &trackerRef = tracker.get_local_tracker();
  std::cout << "local_1: " << trackerRef.get_id()
            << "local tracker instances/same as tracker and tracker 2"
            << std::endl;
  if (t_ptr == t_ptr2)
    std::cout << "SAME MEMORY LOCATION" << std::endl;
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
  // this cleans up all my pointers who point to t_ptrs
  t_ptr->destroy();
  return 0;
}
