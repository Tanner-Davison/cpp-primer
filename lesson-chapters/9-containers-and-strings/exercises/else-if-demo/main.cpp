#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function to categorize numbers
std::string categorizeNumber(int num) {
    if (num < 0) {
        return "negative";
    } else if (num == 0) {
        return "zero";
    } else if (num < 10) {
        return "small positive";
    } else if (num < 100) {
        return "medium positive";
    } else {
        return "large positive";
    }
}

// Function to grade scores
char getGrade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    std::cout << "=== Else-If Control Flow Demo ===\n\n";

    // 1. Number categorization
    std::cout << "1. Number Categorization:\n";
    std::vector<int> numbers{-5, 0, 3, 25, 150, -10, 7, 99, 200};
    
    for (const auto& num : numbers) {
        std::cout << "   " << num << " is " << categorizeNumber(num) << std::endl;
    }
    std::cout << "\n";

    // 2. Grade assignment
    std::cout << "2. Grade Assignment:\n";
    std::vector<int> scores{95, 87, 72, 65, 100, 78, 92, 55, 88, 70};
    
    for (const auto& score : scores) {
        std::cout << "   Score " << score << " = Grade " << getGrade(score) << std::endl;
    }
    std::cout << "\n";

    // 3. Container-based categorization
    std::cout << "3. Container-Based Categorization:\n";
    std::vector<std::string> words{"apple", "banana", "cherry", "date", "elderberry"};
    
    for (const auto& word : words) {
        if (word.length() < 5) {
            std::cout << "   " << word << " is short\n";
        } else if (word.length() < 8) {
            std::cout << "   " << word << " is medium\n";
        } else {
            std::cout << "   " << word << " is long\n";
        }
    }
    std::cout << "\n";

    // 4. Complex categorization with containers
    std::cout << "4. Complex Categorization:\n";
    std::vector<std::pair<std::string, int>> students{
        {"Alice", 95}, {"Bob", 87}, {"Charlie", 72}, 
        {"David", 65}, {"Eve", 100}, {"Frank", 78}
    };
    
    for (const auto& [name, score] : students) {
        std::string performance;
        if (score >= 90) {
            performance = "excellent";
        } else if (score >= 80) {
            performance = "good";
        } else if (score >= 70) {
            performance = "average";
        } else if (score >= 60) {
            performance = "below average";
        } else {
            performance = "needs improvement";
        }
        
        std::cout << "   " << name << " (" << score << "): " << performance << std::endl;
    }
    std::cout << "\n";

    // 5. Container filtering with else-if
    std::cout << "5. Container Filtering:\n";
    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::vector<int> evens, odds, multiples_of_three;
    
    for (const auto& num : data) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else if (num % 3 == 0) {
            multiples_of_three.push_back(num);
        } else {
            odds.push_back(num);
        }
    }
    
    std::cout << "   Even numbers: ";
    for (const auto& num : evens) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    std::cout << "   Multiples of 3: ";
    for (const auto& num : multiples_of_three) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    std::cout << "   Other odd numbers: ";
    for (const auto& num : odds) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
} 