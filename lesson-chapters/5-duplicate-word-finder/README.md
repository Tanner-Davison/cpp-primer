# Chapter 5: Duplicate Word Finder

This chapter demonstrates text processing and duplicate detection with case sensitivity options.

## 📁 Files

- **main.cpp**: Main duplicate word finder program

## 🎯 Learning Objectives

### Text Processing
- **String Streams**: Using `std::stringstream` for word parsing
- **Case Sensitivity**: Handling uppercase/lowercase options
- **Input Validation**: Error handling with try-catch blocks
- **Container Operations**: Using `std::list` for duplicate storage

### Program Features
- **Boundary Setting**: User chooses between 'u' (uppercase) or 'a' (any case)
- **Duplicate Detection**: Finds consecutive duplicate words
- **Case Handling**: Filters based on case sensitivity setting
- **Error Handling**: Validates user input with exceptions

## 🚀 How to Compile and Run

```bash
g++ -std=c++17 main.cpp -o duplicate_finder
./duplicate_finder
```

## 🎮 How to Use

1. **Run the program**: Choose 'u' for uppercase-only or 'a' for any case
2. **Enter text**: Type words separated by spaces
3. **Press Enter twice**: End input and see results
4. **View duplicates**: Program shows all consecutive duplicate words found

## 📊 Sample Usage

```
Uppercase / Any type u or a
u

Boundry set!
hello world hello cpp programming cpp
Duplicate(s) Found: hello, cpp,
```

## 🔧 Key Concepts Demonstrated

- **String Processing**: Word-by-word parsing with string streams
- **Exception Handling**: Input validation with runtime_error
- **Container Usage**: std::list for storing and managing duplicates
- **Case Sensitivity**: Character classification with std::isupper()
- **User Input**: Interactive program with multiple input phases

This chapter provides a practical example of text processing and duplicate detection algorithms.

## 🔗 Related Chapters

**Next Steps:**
- **[Chapter 6: Functions and Debugging](../6-functions-and-debugging/README.md)** - Apply functions to text processing
- **[Chapter 9: Containers and Strings](../9-containers-and-strings/README.md)** - Advanced string operations and container usage 