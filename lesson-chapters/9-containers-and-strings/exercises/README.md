# Chapter 9 Exercises

This folder contains small projects and exercises that were restored after the Chapter 9 reorganization. These exercises provide practical applications of container concepts and demonstrate specific use cases.

## 📁 Exercise Structure

### `date-constructor/`
**Purpose:** Demonstrates custom class design with containers
- **Date.hpp**: Custom Date class with validation
- **Date.cpp**: Implementation with leap year logic
- **main.cpp**: Container operations with Date objects

**Learning Points:**
- Custom class design for containers
- Input validation and error handling
- Container algorithms with custom objects
- Date manipulation and validation

### `vector-list-comparison/`
**Purpose:** Performance comparison between vector and list
- **main.cpp**: Benchmarking insertion and iteration performance

**Learning Points:**
- Performance characteristics of different containers
- When to use vector vs list
- Memory layout differences
- Cache performance considerations

### `else-if-demo/`
**Purpose:** Control flow with containers
- **main.cpp**: Demonstrates else-if logic with container operations

**Learning Points:**
- Control flow with containers
- Categorization and filtering
- Complex conditional logic
- Container-based decision making

## 🎯 Exercise Goals

These exercises complement the main Chapter 9 files by providing:

1. **Practical Applications**: Real-world use cases for containers
2. **Performance Understanding**: When to use which container
3. **Custom Class Integration**: How to work with custom objects in containers
4. **Control Flow**: Combining containers with conditional logic

## 🚀 How to Use

Each exercise can be compiled and run independently:

```bash
# Compile Date exercise
g++ -std=c++17 date-constructor/main.cpp date-constructor/Date.cpp -o date_demo

# Compile vector-list comparison
g++ -std=c++17 vector-list-comparison/main.cpp -o container_comparison

# Compile else-if demo
g++ -std=c++17 else-if-demo/main.cpp -o control_flow_demo
```

## 📚 Learning Progression

1. **Start with Date Constructor**: Understand custom classes in containers
2. **Move to Vector-List Comparison**: Learn performance characteristics
3. **Finish with Else-If Demo**: Combine containers with control flow

These exercises provide hands-on experience with the concepts covered in the main Chapter 9 files. 