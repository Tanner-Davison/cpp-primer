// Chapter 9.4: Container Adapters
// Covers: stack, queue, priority_queue - specialized interfaces built on other containers

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <string>

int main() {
    std::cout << "=== Container Adapters ===\n\n";

    // 1. STACK ADAPTER
    std::cout << "1. Stack Adapter (LIFO - Last In, First Out):\n";
    std::stack<int> number_stack;
    
    // Push elements onto stack
    number_stack.push(10);
    number_stack.push(20);
    number_stack.push(30);
    number_stack.push(40);
    
    std::cout << "   Stack contents (top to bottom): ";
    while (!number_stack.empty()) {
        std::cout << number_stack.top() << " ";
        number_stack.pop();
    }
    std::cout << "\n\n";

    // 2. QUEUE ADAPTER
    std::cout << "2. Queue Adapter (FIFO - First In, First Out):\n";
    std::queue<std::string> name_queue;
    
    // Enqueue elements
    name_queue.push("Alice");
    name_queue.push("Bob");
    name_queue.push("Charlie");
    name_queue.push("David");
    
    std::cout << "   Queue contents (front to back): ";
    while (!name_queue.empty()) {
        std::cout << name_queue.front() << " ";
        name_queue.pop();
    }
    std::cout << "\n\n";

    // 3. PRIORITY QUEUE ADAPTER
    std::cout << "3. Priority Queue Adapter (Heap-based):\n";
    std::priority_queue<int> max_heap;
    
    // Insert elements (automatically sorted)
    max_heap.push(30);
    max_heap.push(10);
    max_heap.push(50);
    max_heap.push(20);
    max_heap.push(40);
    
    std::cout << "   Priority queue contents (max heap): ";
    while (!max_heap.empty()) {
        std::cout << max_heap.top() << " ";
        max_heap.pop();
    }
    std::cout << "\n\n";

    // 4. MIN HEAP (using greater comparator)
    std::cout << "4. Min Heap Priority Queue:\n";
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    
    min_heap.push(30);
    min_heap.push(10);
    min_heap.push(50);
    min_heap.push(20);
    min_heap.push(40);
    
    std::cout << "   Min heap contents: ";
    while (!min_heap.empty()) {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }
    std::cout << "\n\n";

    // 5. CUSTOM PRIORITY QUEUE
    std::cout << "5. Custom Priority Queue (by string length):\n";
    
    // Custom comparator for string length
    auto string_length_compare = [](const std::string& a, const std::string& b) {
        return a.length() < b.length();  // Shorter strings have higher priority
    };
    
    std::priority_queue<std::string, std::vector<std::string>, 
                       decltype(string_length_compare)> string_pq(string_length_compare);
    
    string_pq.push("cat");
    string_pq.push("elephant");
    string_pq.push("dog");
    string_pq.push("ant");
    string_pq.push("giraffe");
    
    std::cout << "   String priority queue (by length, shortest first): ";
    while (!string_pq.empty()) {
        std::cout << string_pq.top() << " ";
        string_pq.pop();
    }
    std::cout << "\n\n";

    // 6. PRACTICAL EXAMPLES
    std::cout << "6. Practical Examples:\n";
    
    // Stack: Balanced parentheses checker
    std::cout << "   Stack Example: Balanced Parentheses Checker\n";
    std::string expression = "((()))";
    std::stack<char> paren_stack;
    bool balanced = true;
    
    for (char c : expression) {
        if (c == '(') {
            paren_stack.push(c);
        } else if (c == ')') {
            if (paren_stack.empty()) {
                balanced = false;
                break;
            }
            paren_stack.pop();
        }
    }
    
    if (balanced && paren_stack.empty()) {
        std::cout << "     Expression '" << expression << "' is balanced\n";
    } else {
        std::cout << "     Expression '" << expression << "' is NOT balanced\n";
    }
    
    // Queue: Task scheduler simulation
    std::cout << "   Queue Example: Task Scheduler\n";
    std::queue<std::string> task_queue;
    task_queue.push("Task 1");
    task_queue.push("Task 2");
    task_queue.push("Task 3");
    
    std::cout << "     Processing tasks: ";
    while (!task_queue.empty()) {
        std::cout << task_queue.front() << " ";
        task_queue.pop();
    }
    std::cout << "\n\n";

    // 7. ADAPTER CHARACTERISTICS
    std::cout << "7. Adapter Characteristics:\n";
    std::cout << "   Stack: LIFO, O(1) push/pop, uses deque by default\n";
    std::cout << "   Queue: FIFO, O(1) enqueue/dequeue, uses deque by default\n";
    std::cout << "   Priority Queue: O(log n) insert/remove, uses vector by default\n";
    std::cout << "   All adapters provide restricted interfaces to underlying containers\n";

    return 0;
} 