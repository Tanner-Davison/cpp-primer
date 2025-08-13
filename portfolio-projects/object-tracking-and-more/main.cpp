#include "./Tracker.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

void print_section(const std::string &title) {
  std::cout << "\n=== " << title << " ===\n";
}

int main() {

  print_section("OBJECT TRACKING DEMONSTRATION");

  // Creating tracker objects
  std::cout << "Creating first tracker object...\n";
  Tracker tracker;
  std::cout << "Tracker 1 ID: " << tracker.get_id() << "\n";

  std::cout << "Creating second tracker object...\n";
  Tracker tracker2;
  std::cout << "Tracker 2 ID: " << tracker2.get_id() << "\n";

  print_section("POINTER OPERATIONS");

  // Working with pointers
  Tracker *t_ptr = tracker.get_tracker_ptr();
  std::cout << "Pointer 1 points to ID: " << t_ptr->get_id() << "\n";

  Tracker *t_ptr2 = tracker2.get_tracker_ptr();
  std::cout << "Pointer 2 points to ID: " << t_ptr2->get_id() << "\n";

  // Pointer comparison
  if (t_ptr == t_ptr2) {
    std::cout << "✓ Both pointers point to the same memory location\n";
  } else {
    std::cout << "✗ Pointers point to different memory locations\n";
  }

  print_section("REFERENCE OPERATIONS");

  Tracker &trackerRef = tracker.get_local_tracker();
  std::cout << "Reference ID: " << trackerRef.get_id()
            << " (should match original tracker)\n";

  print_section("VECTOR OF TRACKERS");

  std::cout << "Creating vector with 5 tracker objects:\n";
  std::vector<Tracker> vec(5);
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << "  Vector[" << i << "] ID: " << vec[i].get_id() << "\n";
  }

  print_section("STRING PARSING EXAMPLE");

  std::string myString = "Tanner 19 6'5 awesome";
  std::string name, age, height, type;
  std::istringstream iss(myString);
  iss >> name >> age >> height >> type;

  std::cout << "Original string: \"" << myString << "\"\n";
  std::cout << "Parsed data:\n";
  std::cout << "  Name:   " << name << "\n";
  std::cout << "  Age:    " << age << "\n";
  std::cout << "  Height: " << height << "\n";
  std::cout << "  Type:   " << type << "\n";

  print_section("RANDOM NUMBER GENERATION");

  // Random number setup
  std::mt19937 mt{static_cast<std::mt19937::result_type>(
      std::chrono::steady_clock::now().time_since_epoch().count())};
  std::uniform_int_distribution<> die6{1, 6};

  std::cout << "Rolling a 6-sided die 3 times:\n";
  for (int i = 0; i < 3; ++i) {
    std::cout << "  Roll " << (i + 1) << ": " << die6(mt) << "\n";
  }

  print_section("CLEANUP");

  std::cout << "Destroying tracker pointers...\n";
  t_ptr->destroy();
  std::cout << "Cleanup complete!\n";

  std::cout << "\n=== PROGRAM FINISHED ===\n";
  return 0;
}
