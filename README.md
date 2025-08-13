# C++ Learning Journey

> A comprehensive collection of C++ examples, exercises, and projects documenting my journey through C++ Primer 5th Edition and beyond.

## 📚 Overview

This repository represents my systematic approach to learning C++ through hands-on practice. Each chapter and concept is thoroughly explored with practical examples, ensuring deep understanding of both fundamental and advanced C++ concepts.

## 🎯 Learning Path

### **Phase 1: C++ Primer 5th Edition** (Current)
- **Status**: In Progress
- **Focus**: Core language features, STL, modern C++ practices
- **Approach**: Chapter-by-chapter with practical examples

### **Future Phases** (Planned)
- **Phase 2**: Effective C++ Series (Scott Meyers)
- **Phase 3**: Professional C++ (Advanced topics)
- **Phase 4**: Design Patterns in C++

## 📁 Project Structure

```
cppPrimer/
├── chapters/                    # C++ Primer 5th Edition examples
│   ├── 5/                      # Basic language features
│   ├── 6/                      # Functions and debugging
│   ├── 7/                      # Classes and objects
│   ├── 7.3/                    # Advanced class features
│   ├── 8-streams/              # I/O streams
│   ├── 9-containers-and-strings/ # STL containers
│   └── _10-generic-algorithms/ # Generic algorithms
├── projects/                    # Real-world applications
├── subjects/                    # Specialized topics
├── tests/                       # Testing examples
└── cool_finds/                  # Interesting discoveries
```

## 🚀 Key Features

### **Modern C++ Focus**
- C++11/14/17/20 features throughout
- Lambda expressions and functional programming
- Smart pointers and RAII principles
- Range-based for loops and `auto` keyword
- Spaceship operator (`<=>`) examples

### **Comprehensive Coverage**
- **STL Containers**: vectors, lists, maps, sets, queues, stacks
- **Generic Algorithms**: sort, find, transform, accumulate
- **Function Objects**: lambdas, bind, function pointers
- **I/O Operations**: file streams, string streams, iterators
- **Class Design**: constructors, operators, inheritance

### **Practical Applications**
- Library management system
- Phone number validation
- Balanced brackets checker
- Real-time console applications
- Data processing pipelines

## 🛠️ Development Environment

- **Editor**: Neovim with custom C++ setup
- **Compiler**: Modern C++ compiler with full C++20 support
- **Build System**: Make/CMake integration
- **Language Server**: clangd for IntelliSense
- **Debugging**: GDB/LLDB integration

## 📖 Chapter Highlights

### **Chapter 5: Basic Language Features**
- Exception handling with try-catch blocks
- String processing and validation
- Control flow and decision making

### **Chapter 6: Functions**
- Function overloading and default arguments
- Debug macros and preprocessor directives
- Recursive function implementations
- Reference parameters and return types

### **Chapter 7: Classes**
- Class design principles
- Constructors and destructors
- Operator overloading
- Friend functions and classes
- Sales data management system

### **Chapter 8: I/O Streams**
- File input/output operations
- String stream processing
- Data validation and formatting
- Error handling in streams

### **Chapter 9: Containers and Strings**
- STL container operations
- String manipulation and processing
- Iterator safety and best practices
- Container adapters (stack, queue)

### **Chapter 10: Generic Algorithms**
- Lambda expressions and closures
- Algorithm customization
- Iterator adapters (back_inserter, etc.)
- Function objects and bind
- Partitioning and sorting algorithms

## 🎮 Interactive Projects

### **Real-time Applications**
- **Console Ticker**: Real-time character animation
- **Grid Visualizer**: Dynamic grid manipulation
- **Library Search**: Interactive book management

### **Data Processing**
- **Phone Number Validator**: Input validation and formatting
- **Balanced Brackets**: Algorithm implementation
- **Word Finder**: Text processing utilities

### **System Design**
- **Transaction Processing**: Sales data management
- **Person Management**: Object-oriented design
- **Debug System**: Comprehensive logging framework

## 🔧 Technical Skills Demonstrated

### **Modern C++ Features**
```cpp
// Lambda expressions
auto lambda = [](const std::string &val) {
    std::cout << "Value: " << val << std::endl;
};

// Range-based for loops
for (const auto &str : my_strings) {
    // Process each string
}

// Spaceship operator (C++20)
auto operator<=>(const Point &other) const {
    if (auto cmp = x <=> other.x; cmp != 0) {
        return cmp;
    }
    return y <=> other.y;
}
```

### **STL Mastery**
```cpp
// Generic algorithms with lambdas
std::transform(numbers.begin(), numbers.end(),
               std::back_inserter(squared_nums),
               [](int num) { return num * num; });

// Container operations
std::erase_if(my_strings, [](int num) { return num % 2; });
```

### **Class Design**
```cpp
class Sales_data {
public:
    // Modern constructors
    Sales_data() = default;
    Sales_data(const Sales_data &) = default;
    
    // Operator overloading
    Sales_data &operator+=(const Sales_data &rhs);
    
    // Friend functions
    friend std::ostream &operator<<(std::ostream &os, const Sales_data &item);
};
```

## 📈 Learning Outcomes

### **Programming Skills**
- ✅ Modern C++ syntax and features
- ✅ STL containers and algorithms
- ✅ Object-oriented design principles
- ✅ Memory management and RAII
- ✅ Template programming basics
- ✅ Exception handling and error management

### **Development Skills**
- ✅ Neovim/Vim proficiency
- ✅ Command-line development
- ✅ Build system understanding
- ✅ Debugging and testing
- ✅ Code organization and documentation

### **Problem-Solving Skills**
- ✅ Algorithm implementation
- ✅ Data structure usage
- ✅ System design thinking
- ✅ Performance considerations
- ✅ Code optimization

## 🎯 Career Benefits

This systematic approach to learning C++ provides:

1. **Comprehensive Knowledge**: Deep understanding of C++ fundamentals and advanced features
2. **Practical Experience**: Real-world project implementations
3. **Modern Practices**: Current C++ best practices and idioms
4. **Tool Proficiency**: Advanced development environment skills
5. **Portfolio Material**: Extensive code examples for interviews

## 🚀 Getting Started

### **Prerequisites**
- Modern C++ compiler (GCC 10+, Clang 10+, MSVC 2019+)
- Neovim or compatible editor
- Make or CMake build system

### **Building Examples**
```bash
# Navigate to any example directory
cd chapters/5/

# Compile with modern C++ standard
g++ -std=c++20 -Wall -Wextra main.cpp -o main

# Run the example
./main
```

### **Development Setup**
```bash
# Clone the repository
git clone <repository-url>
cd cppPrimer

# Explore chapters
ls chapters/

# Build and run examples
make -C chapters/5/
```

## 📝 Notes

- **Ongoing Project**: This is a living document of my C++ learning journey
- **Systematic Approach**: Each concept is thoroughly explored with practical examples
- **Modern Focus**: Emphasis on C++11/14/17/20 features over legacy code
- **Real Applications**: Examples progress from simple to complex real-world scenarios

## 🤝 Contributing

This is a personal learning project, but suggestions and feedback are welcome! Feel free to:
- Report issues or bugs in examples
- Suggest improvements to code organization
- Share additional learning resources
- Discuss C++ best practices

## 📚 Resources

- **Primary Text**: C++ Primer 5th Edition (Stanley Lippman)
- **Reference**: C++ Standard Library Reference
- **Tools**: Neovim, clangd, GDB
- **Community**: C++ forums and Stack Overflow

---

*"The best way to learn a programming language is to write code in it."*

This repository demonstrates that principle through systematic, hands-on learning of C++ with modern practices and real-world applications. 