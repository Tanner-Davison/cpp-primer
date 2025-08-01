// Chapter 9.7: Advanced Container Operations
// Covers: Complex container operations, iterator safety, and advanced patterns

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>
#include <string>
#include <map>

// Function to safely insert into forward_list
void find_insert_string(std::forward_list<std::string>& flist,
                       const std::string& str1, const std::string& str2) {
    auto prev = flist.before_begin();
    auto curr = flist.begin();
    
    while (curr != flist.end()) {
        if (*curr == str1) {
            flist.insert_after(prev, str2);
            return;
        }
        ++prev;
        ++curr;
    }
    // If str1 not found, insert at end
    flist.insert_after(prev, str2);
}

int main() {
    std::cout << "=== Advanced Container Operations ===\n\n";

    // 1. FORWARD_LIST OPERATIONS
    std::cout << "1. Forward List Operations:\n";
    
    std::forward_list<std::string> flist{"hello", "world", "cpp", "programming"};
    
    std::cout << "   Original forward_list: ";
    for (const auto& s : flist) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    // Insert after "world"
    find_insert_string(flist, "world", "amazing");
    
    std::cout << "   After inserting 'amazing' after 'world': ";
    for (const auto& s : flist) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    // Insert after non-existent element
    find_insert_string(flist, "nonexistent", "end");
    
    std::cout << "   After inserting 'end' after 'nonexistent': ";
    for (const auto& s : flist) {
        std::cout << s << " ";
    }
    std::cout << "\n\n";

    // 2. VECTOR RESIZE AND CAPACITY
    std::cout << "2. Vector Resize and Capacity:\n";
    
    std::vector<int> vec;
    std::cout << "   Initial size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    
    // Add elements
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        std::cout << "   After push_back(" << i << "): size=" << vec.size() 
                  << ", capacity=" << vec.capacity() << std::endl;
    }
    
    // Reserve space
    vec.reserve(20);
    std::cout << "   After reserve(20): size=" << vec.size() 
              << ", capacity=" << vec.capacity() << std::endl;
    
    // Resize
    vec.resize(15, 99);
    std::cout << "   After resize(15, 99): size=" << vec.size() 
              << ", capacity=" << vec.capacity() << std::endl;
    
    std::cout << "   Vector contents: ";
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";

    // 3. ITERATOR SAFE INSERTION
    std::cout << "3. Iterator Safe Insertion:\n";
    
    std::vector<int> numbers{1, 2, 3, 4, 5};
    std::cout << "   Original vector: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Safe insertion using iterators
    auto it = numbers.begin() + 2;  // Point to element 3
    numbers.insert(it, 10);  // Insert 10 before element 3
    
    std::cout << "   After inserting 10 at position 2: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Insert multiple elements
    std::vector<int> to_insert{20, 30};
    numbers.insert(numbers.begin() + 1, to_insert.begin(), to_insert.end());
    
    std::cout << "   After inserting {20, 30} at position 1: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";

    // 4. MAP OF PAIRS EXAMPLE
    std::cout << "4. Map of Pairs Example:\n";
    
    std::map<std::string, std::pair<int, std::string>> student_records;
    
    // Insert student records
    student_records["Alice"] = {95, "Computer Science"};
    student_records["Bob"] = {87, "Mathematics"};
    student_records["Charlie"] = {92, "Physics"};
    
    std::cout << "   Student records:\n";
    for (const auto& [name, record] : student_records) {
        std::cout << "     " << name << ": Grade=" << record.first 
                  << ", Major=" << record.second << std::endl;
    }
    
    // Find student with highest grade
    auto max_student = std::max_element(student_records.begin(), student_records.end(),
                                       [](const auto& a, const auto& b) {
                                           return a.second.first < b.second.first;
                                       });
    
    std::cout << "   Student with highest grade: " << max_student->first 
              << " (" << max_student->second.first << ")\n\n";

    // 5. CONTAINER ERASE OPERATIONS
    std::cout << "5. Container Erase Operations:\n";
    
    std::vector<int> erase_test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "   Original vector: ";
    for (int n : erase_test) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Erase even numbers
    erase_test.erase(std::remove_if(erase_test.begin(), erase_test.end(),
                                    [](int n) { return n % 2 == 0; }),
                     erase_test.end());
    
    std::cout << "   After removing even numbers: ";
    for (int n : erase_test) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Erase specific element
    auto remove_it = std::find(erase_test.begin(), erase_test.end(), 5);
    if (remove_it != erase_test.end()) {
        erase_test.erase(remove_it);
    }
    
    std::cout << "   After removing 5: ";
    for (int n : erase_test) {
        std::cout << n << " ";
    }
    std::cout << "\n\n";

    // 6. CONTAINER COMPARISON
    std::cout << "6. Container Comparison:\n";
    
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::list<int> list1{1, 2, 3, 4, 5};
    
    // Compare containers
    bool equal = std::equal(vec1.begin(), vec1.end(), list1.begin());
    std::cout << "   Vector and list are equal: " << (equal ? "true" : "false") << std::endl;
    
    // Lexicographical comparison
    std::vector<int> vec2{1, 2, 3, 4, 6};
    bool vec1_less = std::lexicographical_compare(vec1.begin(), vec1.end(),
                                                  vec2.begin(), vec2.end());
    std::cout << "   Vector1 < Vector2: " << (vec1_less ? "true" : "false") << std::endl;
    std::cout << "\n";

    // 7. ADVANCED PATTERNS
    std::cout << "7. Advanced Container Patterns:\n";
    
    // Container of containers
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    std::cout << "   Matrix (container of containers):\n";
    for (const auto& row : matrix) {
        std::cout << "     ";
        for (int n : row) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    
    // Flatten matrix
    std::vector<int> flattened;
    for (const auto& row : matrix) {
        flattened.insert(flattened.end(), row.begin(), row.end());
    }
    
    std::cout << "   Flattened matrix: ";
    for (int n : flattened) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // Container performance tips
    std::cout << "\n   Performance Tips:\n";
    std::cout << "   - Use reserve() to avoid reallocations\n";
    std::cout << "   - Prefer emplace_back() over push_back() for complex objects\n";
    std::cout << "   - Use erase-remove idiom for efficient element removal\n";
    std::cout << "   - Consider move semantics for container transfers\n";
    std::cout << "   - Use appropriate container for your access patterns\n";

    return 0;
} 