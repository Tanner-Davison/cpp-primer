#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <string>

// Function to measure insertion time
template<typename Container>
void measureInsertion(Container& container, const std::string& name, int num_elements) {
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < num_elements; ++i) {
        container.insert(container.begin(), i);  // Insert at beginning
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << name << " insertion time: " << duration.count() << " microseconds\n";
}

// Function to measure iteration time
template<typename Container>
void measureIteration(const Container& container, const std::string& name) {
    auto start = std::chrono::high_resolution_clock::now();
    
    int sum = 0;
    for (const auto& item : container) {
        sum += item;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << name << " iteration time: " << duration.count() << " microseconds\n";
}

int main() {
    std::cout << "=== Vector vs List Comparison ===\n\n";

    const int num_elements = 10000;
    
    // 1. Insertion performance comparison
    std::cout << "1. Insertion Performance (inserting at beginning):\n";
    
    std::vector<int> vec;
    std::list<int> lst;
    
    measureInsertion(vec, "Vector", num_elements);
    measureInsertion(lst, "List", num_elements);
    std::cout << "\n";

    // 2. Iteration performance comparison
    std::cout << "2. Iteration Performance:\n";
    measureIteration(vec, "Vector");
    measureIteration(lst, "List");
    std::cout << "\n";

    // 3. Memory layout demonstration
    std::cout << "3. Memory Layout Differences:\n";
    std::cout << "   Vector: Contiguous memory, cache-friendly\n";
    std::cout << "   List: Non-contiguous memory, pointer-based\n";
    std::cout << "   Vector size: " << sizeof(std::vector<int>) << " bytes\n";
    std::cout << "   List size: " << sizeof(std::list<int>) << " bytes\n\n";

    // 4. Access patterns
    std::cout << "4. Access Pattern Comparison:\n";
    
    // Random access (vector advantage)
    if (!vec.empty()) {
        std::cout << "   Vector random access: " << vec[5000] << std::endl;
    }
    
    // Sequential access (both similar)
    std::cout << "   List sequential access: ";
    auto it = lst.begin();
    std::advance(it, 5000);
    if (it != lst.end()) {
        std::cout << *it << std::endl;
    }
    std::cout << "\n";

    // 5. Use case recommendations
    std::cout << "5. Use Case Recommendations:\n";
    std::cout << "   Use Vector when:\n";
    std::cout << "   - You need random access\n";
    std::cout << "   - You mostly append elements\n";
    std::cout << "   - Memory efficiency is important\n";
    std::cout << "   - Cache performance matters\n\n";
    
    std::cout << "   Use List when:\n";
    std::cout << "   - You frequently insert/delete in middle\n";
    std::cout << "   - You don't need random access\n";
    std::cout << "   - Iterator invalidation is a concern\n";
    std::cout << "   - You need bidirectional iteration\n";

    return 0;
} 