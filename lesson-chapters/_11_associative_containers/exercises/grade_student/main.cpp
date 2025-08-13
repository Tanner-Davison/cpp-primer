#include <iostream>
#include <map>
#include <string>

int main() {
  // MAP EXAMPLE - One key -> One value
  std::cout << "=== MAP EXAMPLE ===" << std::endl;
  std::map<std::string, int> ages;

  // Adding data
  ages["Alice"] = 25;
  ages["Bob"] = 30;
  ages["Charlie"] = 25; // Different key, same value is fine
  ages["Alice"] = 26;   // This overwrites Alice's previous age

  // Print map
  for (const auto &[name, age] : ages) {
    std::cout << name << " is " << age << " years old" << std::endl;
  }

  std::cout << "\n=== MULTIMAP EXAMPLE ===" << std::endl;
  std::multimap<int, std::string> grade_students;

  // Adding data - multiple values per key
  grade_students.insert({85, "Alice"});
  grade_students.insert({92, "Bob"});
  grade_students.insert({85, "Charlie"});
  grade_students.insert({85, "Diana"});
  grade_students.insert({78, "Eve"});

  // Print all entries
  std::cout << "All students:" << std::endl;
  for (const auto &[grade, student] : grade_students) {
    std::cout << student << " got " << grade << std::endl;
  }

  // Find all students with grade 85
  std::cout << "\nStudents with grade 85:" << std::endl;
  auto range = grade_students.equal_range(85);
  for (auto it = range.first; it != range.second; ++it) {
    std::cout << it->second << std::endl;
  }

  return 0;
}
