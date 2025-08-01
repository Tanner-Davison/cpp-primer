// Chapter 9.6: Algorithms and Search Operations
// Covers: Standard algorithms, custom search functions, and container operations

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <functional>

// Custom find template function
template <typename T>
typename std::vector<T>::iterator find_(typename std::vector<T>::iterator begin,
                                        typename std::vector<T>::iterator end,
                                        const T& target) {
    return std::find(begin, end, target);
}

// Custom search function with predicate
template <typename Iterator, typename Predicate>
Iterator find_if_custom(Iterator begin, Iterator end, Predicate pred) {
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            return it;
        }
    }
    return end;
}

int main() {
    std::cout << "=== Algorithms and Search Operations ===\n\n";

    // 1. BASIC SEARCH OPERATIONS
    std::cout << "1. Basic Search Operations:\n";
    
    std::vector<std::string> lookup_lib{"hello", "Tom", "Ransom", "Ben", "Tougher"};
    std::vector<int> numbers{3, 4, 5, 2, 1, 6, 8, 7};
    
    // Search for string using custom find function
    auto string_result = find_<std::string>(lookup_lib.begin(), lookup_lib.end(), "Ben");
    if (string_result == lookup_lib.end()) {
        std::cout << "   Target string 'Ben' not found\n";
    } else {
        std::cout << "   Target string 'Ben' found at position: " 
                  << std::distance(lookup_lib.begin(), string_result) << std::endl;
    }
    
    // Search for number using standard find
    auto num_result = std::find(numbers.begin(), numbers.end(), 3);
    if (num_result == numbers.end()) {
        std::cout << "   Target number 3 not found\n";
    } else {
        std::cout << "   Target number 3 found at position: " 
                  << std::distance(numbers.begin(), num_result) << std::endl;
    }
    std::cout << "\n";

    // 2. ADVANCED SEARCH WITH PREDICATES
    std::cout << "2. Advanced Search with Predicates:\n";
    
    std::vector<int> test_numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Find first even number
    auto even_it = std::find_if(test_numbers.begin(), test_numbers.end(),
                                [](int n) { return n % 2 == 0; });
    if (even_it != test_numbers.end()) {
        std::cout << "   First even number: " << *even_it << std::endl;
    }
    
    // Find first number greater than 5
    auto greater_than_5 = std::find_if(test_numbers.begin(), test_numbers.end(),
                                       [](int n) { return n > 5; });
    if (greater_than_5 != test_numbers.end()) {
        std::cout << "   First number > 5: " << *greater_than_5 << std::endl;
    }
    
    // Custom search with predicate
    auto custom_result = find_if_custom(test_numbers.begin(), test_numbers.end(),
                                       [](int n) { return n % 3 == 0; });
    if (custom_result != test_numbers.end()) {
        std::cout << "   First number divisible by 3: " << *custom_result << std::endl;
    }
    std::cout << "\n";

    // 3. SORTING AND ORDERING
    std::cout << "3. Sorting and Ordering:\n";
    
    std::vector<std::string> names{"Charlie", "Alice", "Bob", "David", "Eve"};
    
    // Sort alphabetically
    std::sort(names.begin(), names.end());
    std::cout << "   Sorted names: ";
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    
    // Sort by length
    std::sort(names.begin(), names.end(),
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });
    std::cout << "   Sorted by length: ";
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
    
    // Reverse sort
    std::sort(names.begin(), names.end(), std::greater<std::string>());
    std::cout << "   Reverse sorted: ";
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << "\n\n";

    // 4. CONTAINER OPERATIONS
    std::cout << "4. Container Operations:\n";
    
    std::vector<int> source{1, 2, 3, 4, 5};
    std::vector<int> dest;
    
    // Copy elements
    std::copy(source.begin(), source.end(), std::back_inserter(dest));
    std::cout << "   Copied elements: ";
    for (int n : dest) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Transform elements
    std::vector<int> squared;
    std::transform(source.begin(), source.end(), std::back_inserter(squared),
                   [](int n) { return n * n; });
    std::cout << "   Squared elements: ";
    for (int n : squared) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Filter elements
    std::vector<int> evens;
    std::copy_if(source.begin(), source.end(), std::back_inserter(evens),
                  [](int n) { return n % 2 == 0; });
    std::cout << "   Even numbers: ";
    for (int n : evens) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";

    // 5. BINARY SEARCH
    std::cout << "5. Binary Search (requires sorted container):\n";
    
    std::vector<int> sorted_numbers{1, 3, 5, 7, 9, 11, 13, 15};
    
    // Check if element exists
    bool found_7 = std::binary_search(sorted_numbers.begin(), sorted_numbers.end(), 7);
    bool found_8 = std::binary_search(sorted_numbers.begin(), sorted_numbers.end(), 8);
    
    std::cout << "   Number 7 found: " << (found_7 ? "true" : "false") << std::endl;
    std::cout << "   Number 8 found: " << (found_8 ? "true" : "false") << std::endl;
    
    // Find lower bound
    auto lb = std::lower_bound(sorted_numbers.begin(), sorted_numbers.end(), 6);
    std::cout << "   Lower bound for 6: " << *lb << std::endl;
    
    // Find upper bound
    auto ub = std::upper_bound(sorted_numbers.begin(), sorted_numbers.end(), 6);
    std::cout << "   Upper bound for 6: " << *ub << std::endl;
    std::cout << "\n";

    // 6. PRACTICAL SEARCH EXAMPLES
    std::cout << "6. Practical Search Examples:\n";
    
    // Search in list of pairs
    std::vector<std::pair<std::string, int>> students{
        {"Alice", 95}, {"Bob", 87}, {"Charlie", 92}, {"David", 78}
    };
    
    // Find student by name
    auto student_it = std::find_if(students.begin(), students.end(),
                                   [](const auto& p) { return p.first == "Charlie"; });
    if (student_it != students.end()) {
        std::cout << "   Found Charlie with grade: " << student_it->second << std::endl;
    }
    
    // Find highest grade
    auto max_grade = std::max_element(students.begin(), students.end(),
                                     [](const auto& a, const auto& b) {
                                         return a.second < b.second;
                                     });
    std::cout << "   Highest grade: " << max_grade->second 
              << " by " << max_grade->first << std::endl;
    
    // Count students with grade >= 90
    int high_achievers = std::count_if(students.begin(), students.end(),
                                       [](const auto& p) { return p.second >= 90; });
    std::cout << "   Students with grade >= 90: " << high_achievers << std::endl;
    std::cout << "\n";

    // 7. ALGORITHM PERFORMANCE TIPS
    std::cout << "7. Algorithm Performance Tips:\n";
    std::cout << "   - Use binary_search only on sorted containers\n";
    std::cout << "   - Prefer find_if over find when you need custom logic\n";
    std::cout << "   - Use transform for element-wise operations\n";
    std::cout << "   - Use copy_if for filtering operations\n";
    std::cout << "   - Consider using std::function for complex predicates\n";
    std::cout << "   - Use std::back_inserter for output iterators\n";

    return 0;
} 