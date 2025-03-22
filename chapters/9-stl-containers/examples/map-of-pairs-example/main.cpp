#include <cctype>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

int main() {
  std::map<std::string, std::pair<std::string, int>> people;
  people["tanner"] = std::make_pair("pretty cool", 30);
  people["ben"] = std::make_pair("average", 20);

  // Display map contents with capitalized keys
  std::cout << "=== Map Contents ===\n";
  for (const auto &person : people) {
    const auto &key = person.first;
    std::string displayName = key;
    displayName[0] = std::toupper(displayName[0]);

    const auto &details = person.second;
    std::cout << "Name: " << displayName << "\n  Description: " << details.first
              << "\n  Age: " << details.second << "\n"
              << std::endl;
  }

  // Initialize test vectors
  std::vector<std::string> names{"Sarah", "Andrew", "Kate", "Perry"};
  std::vector<std::string> celebrities{"Tanner", "Trump", "ELON", "MUSK"};
  std::vector<std::string> emptyVector;

  // Create iterators to the beginning and end of celebrities vector
  auto beginIter = celebrities.begin();
  auto endIter = celebrities.end();

  // Display original values
  std::cout << "\n=== Original Vector Values ===\n";
  std::cout << "Names: ";
  for (const auto &name : names) {
    std::cout << name << ", ";
  }
  std::cout << "\n\nCelebrities: ";
  for (const auto &celeb : celebrities) {
    std::cout << celeb << ", ";
  }
  std::cout << "\n";

  // Assign all values from celebrities to names
  names.assign(beginIter, endIter);
  std::cout << "\n=== After Assigning Celebrities to Names ===\n";
  std::cout << "Names: ";
  for (const auto &name : names) {
    std::cout << name << ", ";
  }
  std::cout << "\n";

  // Swap names with emptyVector
  std::cout << "\n=== After Swapping Names with Empty Vector ===\n";
  std::swap(names, emptyVector);

  std::cout << "Names (now empty): ";
  if (names.empty()) {
    std::cout << "[EMPTY]";
  } else {
    for (const auto &name : names) {
      std::cout << name << ", ";
    }
  }

  std::cout << "\n\nEmpty Vector (now contains celebrities): ";
  for (const auto &name : emptyVector) {
    std::cout << name << ", ";
  }

  // Swap celebrities with emptyVector
  std::cout << "\n\n=== After Swapping Celebrities with Empty Vector ===\n";
  std::swap(celebrities, emptyVector);

  std::cout << "Celebrities (now empty): ";
  if (celebrities.empty()) {
    std::cout << "[EMPTY]";
  } else {
    for (const auto &celeb : celebrities) {
      std::cout << celeb << ", ";
    }
  }

  std::cout << "\n\nEmpty Vector (now contains original celebrities): ";
  for (const auto &name : emptyVector) {
    std::cout << name << ", ";
  }

  std::cout << "\n\n";
  return 0;
}
