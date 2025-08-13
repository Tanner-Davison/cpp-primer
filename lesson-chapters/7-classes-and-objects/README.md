# Chapter 7: Classes and Objects

This chapter covers fundamental object-oriented programming concepts in C++, including class design, constructors, operators, and advanced class features.

## 📁 Structure

Chapter 7 opens into two main subdirectories, each demonstrating different aspects of class design and object-oriented programming:

### `sales-data-person-demo/`
**Main Program:** Sales_data and Person class demonstration
**Core Files:**
- **main.cpp**: Demonstrates Sales_data and Person class usage
- **Sales_data.hpp/cpp**: Complete Sales_data class with constructors, operators, and friend functions
- **Person.hpp/cpp**: Person class with member functions and I/O operations
- **input.txt/person.txt**: Sample data files for testing

**Learning Focus:**
- Class design principles
- Constructors and destructors
- Operator overloading
- Friend functions and classes
- Member functions and data members
- I/O operations with custom classes

### `realtime-console-ticker/`
**Main Program:** Real-time console ticker application
**Core Files:**
- **main.cpp**: Real-time console ticker application
- **Screen.hpp/cpp**: Screen class with advanced features
- **Window_mgr.hpp/cpp**: Window manager class demonstrating friend classes
- **X.hpp/Y.hpp**: Forward declaration examples
- **KnowledgeComments.md**: Detailed documentation on Windows console functions

**Learning Focus:**
- Real-time applications with `_kbhit()` and `_getch()`
- Advanced class design patterns
- Friend class relationships
- Forward declarations
- Console-based applications
- Class composition and relationships

## 🎯 Key Learning Objectives

### Sales Data & Person Demo:
1. **Class Fundamentals**
   - Understanding class structure and member functions
   - Constructor and destructor implementation
   - Access control (public, private, protected)

2. **Operator Overloading**
   - Custom operators for user-defined types
   - Input/output operator overloading
   - Arithmetic operator implementation

3. **Friend Functions**
   - Non-member functions with access to private members
   - I/O operations for custom classes
   - When and how to use friend functions

### Realtime Console Ticker:
1. **Real-time Programming**
   - Non-blocking input handling
   - Console-based applications
   - Platform-specific features

2. **Advanced Class Design**
   - Friend class relationships
   - Forward declarations
   - Class composition patterns

3. **Practical Applications**
   - Interactive console applications
   - Screen manipulation
   - Window management systems

## 🚀 How to Use

### Compile Sales Data & Person Demo:
```bash
cd sales-data-person-demo
g++ -std=c++17 main.cpp Sales_data.cpp Person.cpp -o sales_person_demo
```

### Compile Realtime Console Ticker:
```bash
cd realtime-console-ticker
g++ -std=c++17 main.cpp Screen.cpp Window_mgr.cpp -o realtime_ticker
```

## 📚 Learning Progression

1. **Start with Sales Data & Person Demo**: Understand basic class design with Sales_data and Person
2. **Practice with Examples**: Run the main.cpp to see classes in action
3. **Explore Advanced Features**: Move to realtime console ticker for real-time applications
4. **Study Documentation**: Read KnowledgeComments.md for detailed explanations

## 🔧 Key Concepts Demonstrated

- **Encapsulation**: Private data members with public interfaces
- **Abstraction**: Complex functionality hidden behind simple interfaces
- **Operator Overloading**: Custom behavior for built-in operators
- **Friend Functions**: Controlled access to private members
- **Real-time Programming**: Non-blocking input and console manipulation
- **Class Relationships**: Friend classes and forward declarations

This chapter provides a solid foundation in C++ object-oriented programming, from basic class design to advanced real-time applications.

## 🔗 Related Chapters

**Prerequisites:**
- **[Chapter 6: Functions and Debugging](../6-functions-and-debugging/README.md)** - Function design and parameter passing

**Next Steps:**
- **[Chapter 9: Containers and Strings](../9-containers-and-strings/README.md)** - Use classes with STL containers
- **[Chapter _11: Associative Containers](../_11_associative_containers/)** - Custom comparators and class-based containers
- **[Chapter _10: Generic Algorithms](../_10_generic_algorithms/)** - Function objects and class-based algorithms 