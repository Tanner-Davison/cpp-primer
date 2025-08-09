// Chapter 9.3: Associative Containers
// Covers: map, set, unordered_map, unordered_set, multimap, multiset

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
  std::cout << "=== Associative Containers ===\n\n";

  // 1. ORDERED MAP (Red-Black Tree)
  std::cout << "1. Ordered Map (std::map):\n";
  std::map<char, int> char_to_int{
      {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}};

  std::cout << "   Map contents (sorted by key):\n";
  for (const auto &[key, value] : char_to_int) {
    std::cout << "     " << key << " -> " << value << std::endl;
  }

  // Map operations
  char_to_int['f'] = 6;         // Insert or assign
  char_to_int.insert({'g', 7}); // Insert only if key doesn't exist

  std::cout << "   After adding 'f' and 'g':\n";
  for (const auto &[key, value] : char_to_int) {
    std::cout << "     " << key << " -> " << value << std::endl;
  }
  std::cout << "\n";

  // 2. UNORDERED MAP (Hash Table)
  std::cout << "2. Unordered Map (std::unordered_map):\n";
  std::unordered_map<std::string, int> word_count;

  //  Insert elements
  word_count["hello"] = 1;
  word_count["world"] = 2;
  word_count["cpp"] = 3;
  word_count["programming"] = 1;

  std::cout << "   Word count (no guaranteed order):\n";
  for (const auto &[word, count] : word_count) {
    std::cout << "     " << word << " -> " << count << std::endl;
  }

  // Search in unordered_map
  auto it = word_count.find("cpp");
  if (it != word_count.end()) {
    std::cout << "   Found 'cpp' with count: " << it->second << std::endl;
  }
  std::cout << "\n";

  // 3. SET CONTAINERS
  std::cout << "3. Set Containers:\n";

  // Ordered set
  std::set<int> ordered_numbers{3, 1, 4, 1, 5, 9, 2, 6};
  std::cout << "   Ordered set (unique, sorted): ";
  for (const auto &num : ordered_numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  // Unordered set
  std::unordered_set<int> unordered_numbers{3, 1, 4, 1, 5, 9, 2, 6};
  std::cout << "   Unordered set (unique, no order): ";
  for (const auto &num : unordered_numbers) {
    std::cout << num << " ";
  }
  std::cout << "\n\n";

  // 4. MULTIMAP AND MULTISET
  std::cout << "4. Multi Containers (allow duplicates):\n";

  // Multimap example
  std::multimap<std::string, int> student_grades;
  student_grades.insert({"Alice", 95});
  student_grades.insert({"Bob", 87});
  student_grades.insert({"Alice", 92}); // Alice has multiple grades

  std::cout << "   Student grades (multimap):\n";
  for (const auto &[student, grade] : student_grades) {
    std::cout << "     " << student << " -> " << grade << std::endl;
  }

  // Multiset example
  std::multiset<int> number_bag{1, 2, 2, 3, 3, 3, 4, 5};
  std::cout << "   Number bag (multiset): ";
  for (const auto &num : number_bag) {
    std::cout << num << " ";
  }
  std::cout << "\n\n";

  // 5. CONTAINER COMPARISON
  std::cout << "5. Container Characteristics:\n";
  std::cout << "   Ordered containers (map, set):\n";
  std::cout << "     - Elements sorted by key\n";
  std::cout << "     - O(log n) operations\n";
  std::cout << "     - Predictable iteration order\n\n";

  std::cout << "   Unordered containers (unordered_map, unordered_set):\n";
  std::cout << "     - No guaranteed order\n";
  std::cout << "     - O(1) average operations\n";
  std::cout << "     - Requires good hash functions\n\n";

  // 6. PRACTICAL EXAMPLE: WORD FREQUENCY
  std::cout << "6. Practical Example: Word Frequency Counter\n";
  std::vector<std::string> words{"the",   "quick", "brown", "fox",
                                 "jumps", "over",  "the",   "lazy",
                                 "dog",   "the",   "fox"};

  std::map<std::string, int> frequency;
  for (const auto &word : words) {
    frequency[word]++; // Increment count (creates if doesn't exist)
  }

  std::cout << "   Word frequency (sorted):\n";
  for (const auto &[word, count] : frequency) {
    std::cout << "     " << word << ": " << count << std::endl;
  }

  return 0;
}
