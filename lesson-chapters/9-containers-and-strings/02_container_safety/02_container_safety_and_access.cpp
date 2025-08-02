// Chapter 9.2: Container Safety and Element Access
// Covers: Safe element access, bounds checking, different access methods, and error handling

#include <iostream>
#include <vector>
#include <stdexcept>

void test_element_access(std::vector<int>& test_vec, const std::string& test_name) {
    std::cout << "\n--- Testing " << test_name << " ---\n";
    
    if (!test_vec.empty()) {
        std::cout << "Vector contents: [";
        for (size_t i = 0; i < test_vec.size(); ++i) {
            std::cout << test_vec[i] << (i < test_vec.size() - 1 ? ", " : "");
        }
        std::cout << "]\n";
    } else {
        std::cout << "Vector is empty\n";
    }

    // 1. Subscript Operator []
    std::cout << "\n1. Subscript Operator []:\n";
    try {
        if (!test_vec.empty()) {
            std::cout << "   test_vec[0] = " << test_vec[0] << std::endl;
        } else {
            std::cout << "   WARNING: Accessing [0] on empty vector - Undefined Behavior!\n";
            // This would cause undefined behavior in real code
        }
    } catch (const std::exception& e) {
        std::cout << "   Error with []: " << e.what() << std::endl;
    }

    // 2. front() method
    std::cout << "\n2. front() method:\n";
    try {
        if (!test_vec.empty()) {
            std::cout << "   test_vec.front() = " << test_vec.front() << std::endl;
        } else {
            std::cout << "   WARNING: Calling front() on empty vector - Undefined Behavior!\n";
        }
    } catch (const std::exception& e) {
        std::cout << "   Error with front(): " << e.what() << std::endl;
    }

    // 3. at() method (bounds checking)
    std::cout << "\n3. at() method (with bounds checking):\n";
    try {
        std::cout << "   test_vec.at(0) = " << test_vec.at(0) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "   Error with at(): " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "   Unexpected error with at(): " << e.what() << std::endl;
    }

    // 4. Iterator access
    std::cout << "\n4. Iterator access:\n";
    try {
        if (!test_vec.empty()) {
            std::cout << "   *test_vec.begin() = " << *test_vec.begin() << std::endl;
        } else {
            std::cout << "   WARNING: Dereferencing begin() on empty vector - Undefined Behavior!\n";
        }
    } catch (const std::exception& e) {
        std::cout << "   Error with iterator: " << e.what() << std::endl;
    }

    // 5. Safe access patterns
    std::cout << "\n5. Safe Access Patterns:\n";
    
    // Safe subscript access
    if (0 < test_vec.size()) {
        std::cout << "   Safe [0]: " << test_vec[0] << std::endl;
    } else {
        std::cout << "   Safe [0]: Index out of bounds\n";
    }
    
    // Safe iterator access
    if (test_vec.begin() != test_vec.end()) {
        std::cout << "   Safe iterator: " << *test_vec.begin() << std::endl;
    } else {
        std::cout << "   Safe iterator: Container is empty\n";
    }
}

int main() {
    std::cout << "=== Container Safety and Element Access ===\n";

    // Test with empty vector
    std::vector<int> empty_vec;
    test_element_access(empty_vec, "Empty Vector");

    // Test with non-empty vector
    std::vector<int> non_empty_vec{47, 74, 128, 256, 512};
    test_element_access(non_empty_vec, "Non-Empty Vector");

    // Test with single element vector
    std::vector<int> single_vec{42};
    test_element_access(single_vec, "Single Element Vector");

    std::cout << "\n=== Safety Guidelines ===\n";
    std::cout << "1. Always check bounds before using [] or front()/back()\n";
    std::cout << "2. Use at() when you want automatic bounds checking\n";
    std::cout << "3. Check iterators against end() before dereferencing\n";
    std::cout << "4. Prefer range-based for loops for safe iteration\n";
    std::cout << "5. Use empty() to check if container has elements\n";

    return 0;
} 