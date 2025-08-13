# Chapter 10: Generic Algorithms

This chapter covers C++ generic algorithms, which are template functions that operate on iterators rather than containers directly. These algorithms provide a powerful and flexible way to manipulate data across different container types.

## 📚 Table of Contents

1. [Overview](#overview)
2. [Bind](#bind)
3. [Lambdas](#lambdas)
4. [Iterators](#iterators)
5. [Container Operations](#container-operations)
6. [Duplicate Filtering Operations](#duplicate-filtering-operations)
7. [Read-Only and Query Operations](#read-only-and-query-operations)
8. [Iostream Iterators](#iostream-iterators)
9. [Reverse Iterators](#reverse-iterators)
10. [Passing Functions to Algorithms](#passing-functions-to-algorithms)
11. [Exercises](#exercises)

## 🎯 Overview

Generic algorithms are template functions that work with iterators, making them container-independent. They provide a standardized way to perform common operations like searching, sorting, and transforming data.

### Key Concepts:
- **Iterators**: Provide access to container elements
- **Algorithms**: Template functions that operate on iterator ranges
- **Predicates**: Functions that return bool, used for filtering/ordering
- **Function Objects**: Objects that can be called like functions

## 🔗 Bind

The `std::bind` function creates callable objects by binding arguments to functions, allowing you to adapt function interfaces.

### Basic Binding
```cpp
#include <functional>
using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz) {
    return s.size() >= sz;
}

// Bind the second parameter to 6
auto check6 = bind(check_size, _1, 6);
```

### Reference Parameters
```cpp
std::ostream &print(std::ostream &os, const std::string &str, char c) {
    return os << str << " " << c;
}

// Use ref() to bind references
std::for_each(words.begin(), words.end(),
              bind(print, ref(std::cout), _1, ' '));
```

### Reordering Parameters
```cpp
// Original function
bool isShorter(std::string &str1, std::string &str2) {
    return str1.size() < str2.size();
}

// Reverse parameter order with bind
std::sort(str_vec.begin(), str_vec.end(), bind(isShorter, _2, _1));
```

## 🐑 Lambdas

Lambda expressions provide a concise way to define function objects inline.

### Basic Lambda Syntax
```cpp
[capture list](parameter list) -> return type { function body }
```

### Simple Examples
```cpp
// Basic lambda
auto lambda = [](const std::string &val) {
    std::cout << "Value: " << val << std::endl;
};

// Lambda with capture
int cap_value = 100;
auto sum_lambda = [cap_value](const int num) { 
    return num + cap_value; 
};
```

### Lambda with Return Types
```cpp
std::transform(numbers.begin(), numbers.end(),
               std::back_inserter(absolute_values), 
               [](int i) -> int {
                   if (i < 0) return -i;
                   else return i;
               });
```

### Lambda in Algorithms
```cpp
// Using lambda for sorting
std::stable_sort(str_vec.begin(), str_vec.end(),
                 [](const std::string &str1, const std::string &str2) {
                     return str1.size() < str2.size();
                 });

// Using lambda with bind
auto wc = find_if(words.begin(), words.end(), 
                  bind(check_size, _1, sz));
```

## 🔄 Iterators

Iterators provide a way to traverse container elements and are the foundation of generic algorithms.

### Insert Iterators
Three types of insert iterators for adding elements to containers:

#### 1. back_inserter
```cpp
// Uses push_back() to add elements at the end
std::vector<int> vec;
std::fill_n(std::back_inserter(vec), 10, 5);
```

#### 2. front_inserter
```cpp
// Uses push_front() to add elements at the beginning
std::list<int> lst;
std::copy(vec.begin(), vec.end(), std::front_inserter(lst));
```

#### 3. inserter
```cpp
// Uses insert(iterator, value) to add elements at specific position
std::set<int> s;
std::copy(vec.begin(), vec.end(), std::inserter(s, s.begin()));
```

### Iterator Categories
1. **Input Iterator**: Read-only, forward-only
2. **Output Iterator**: Write-only, forward-only
3. **Forward Iterator**: Read/write, forward-only
4. **Bidirectional Iterator**: Read/write, forward/backward
5. **Random Access Iterator**: Read/write, random access

## 📦 Container Operations

### Filling Containers
```cpp
// std::fill
std::vector<int> vec(20);
std::fill(vec.begin(), vec.end(), 1);

// std::iota (incremental fill)
std::vector<int> iota_vec(20);
std::iota(iota_vec.begin(), iota_vec.end(), 1);

// std::fill_n
std::fill_n(vec.begin(), vec.size(), 0);

// std::generate
std::generate(vec.begin(), vec.end(), 
              [&count]() { return count += 5; });
```

### Back Inserter Examples
```cpp
// Using back_inserter with algorithms
std::vector<int> numbers{0, 1, 2, 3, 4, 5};
std::vector<int> squared_nums;

std::transform(numbers.begin(), numbers.end(),
               std::back_inserter(squared_nums),
               [](int num) { return num * num; });
```

### Reordering Containers
```cpp
// Eliminate duplicates
void elim_dups(std::vector<std::string> &strs) {
    std::sort(strs.begin(), strs.end());           // Sort to group duplicates
    auto end_unique = std::unique(strs.begin(), strs.end()); // Move duplicates to end
    strs.erase(end_unique, strs.end());            // Erase duplicates
}
```

## 🔍 Duplicate Filtering Operations

### Copy and Replace
```cpp
// std::copy
std::copy(source.begin(), source.end(), std::back_inserter(dest));

// std::replace
std::replace(vec.begin(), vec.end(), 3, 0);

// std::replace_copy
std::replace_copy(source.begin(), source.end(),
                  std::back_inserter(dest), 3, 0);
```

### Eliminating Duplicates
```cpp
// For strings
void elim_dups(std::vector<std::string> &strs) {
    std::sort(strs.begin(), strs.end());
    auto end_unique = std::unique(strs.begin(), strs.end());
    strs.erase(end_unique, strs.end());
}

// For numbers
void elim_num_dups(std::vector<int> &nums) {
    std::sort(begin(nums), end(nums));
    auto end_unique_nums = std::unique(begin(nums), end(nums));
    nums.erase(end_unique_nums, nums.end());
}
```

### Stable Sort with Duplicates
```cpp
void elim_dups_stable_sort(std::vector<std::string> &strs) {
    std::sort(strs.begin(), strs.end());
    auto end_unique = std::unique(strs.begin(), strs.end());
    strs.erase(end_unique, strs.end());
    std::stable_sort(strs.begin(), strs.end(), isShorter);
}
```

## 📊 Read-Only and Query Operations

### Accumulate
```cpp
// Numeric accumulation
std::vector<int> nums{1, 2, 3, 4, 5};
int sum = std::accumulate(nums.begin(), nums.end(), 0);

// String accumulation
std::vector<std::string> strs{"Hello ", "world"};
std::string result = std::accumulate(strs.cbegin(), strs.cend(), std::string(""));
```

### Equal Comparison
```cpp
// Compare two sequences
bool equal = std::equal(vec1.cbegin(), vec1.cend(), vec2.cbegin());
```

### Counting Elements
```cpp
// Fast counting with unordered_map
std::unordered_map<int, int> count_map;
for (const auto &num : nums) {
    count_map[num]++;
}

// Slow counting with std::count
for (const auto &num : nums) {
    int count = std::count(nums.begin(), nums.end(), num);
}
```

## 📝 Iostream Iterators

### Input Stream Iterators
```cpp
// Reading from file
std::ifstream input_file("sample_text.txt");
std::istream_iterator<std::string> in_file_it(input_file), eof;

for (; in_file_it != eof; ++in_file_it) {
    std::cout << *in_file_it << ", ";
}
```

### Output Stream Iterators
```cpp
// Writing to output
std::ostream_iterator<int> out_iter(std::cout, ", ");
std::copy(vec.begin(), vec.end(), out_iter);
```

### With Algorithms
```cpp
// Using istream_iterator with accumulate
std::istream_iterator<int> it(std::cin), eof;
int sum = std::accumulate(it, eof, 0);
```

### Partition Copy
```cpp
// Split input into even/odd files
std::ifstream input_file("input_file.txt");
std::ofstream output_evens("output_evens.txt");
std::ofstream output_odds("output_odds.txt");

std::istream_iterator<int> in_iter(input_file), eof;
std::ostream_iterator<int> out_evens(output_evens, ", ");
std::ostream_iterator<int> out_odds(output_odds, ", ");

std::partition_copy(in_iter, eof, out_odds, out_evens,
                    [](int x) { return x % 2 == 1; });
```

## 🔄 Reverse Iterators

### Basic Usage
```cpp
// Print vector in reverse
std::vector<int> nums{1, 2, 3, 4, 5};
for (auto rev_it = nums.rbegin(); rev_it != nums.rend(); ++rev_it) {
    std::cout << *rev_it << ", ";
}
```

### Finding with Reverse Iterators
```cpp
std::string line{"this is my,comma,seperated,list"};

// Find first comma from beginning
auto bcomma = std::find(line.cbegin(), line.cend(), ',');

// Find first comma from end
auto rcomma = std::find(line.rbegin(), line.rend(), ',');

// Extract substrings
std::string before_first = std::string(line.cbegin(), bcomma);
std::string after_last = std::string(rcomma.base(), line.end());
```

### Copying with Reverse Iterators
```cpp
// Copy elements 3-7 in reverse order to a list
std::vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::list<int> num_list;

auto revStart = nums.crbegin() + 3;
auto revEnd = nums.crend() - 2;
std::copy(revStart, revEnd, std::back_inserter(num_list));
```

## 🎯 Passing Functions to Algorithms

### Function Objects (Functors)
```cpp
struct isOdd {
    bool operator()(int x) { return x % 2; }
};

struct isEven {
    bool operator()(int x) { return x % 2 == 0; }
};

// Using functors with algorithms
std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int odd_count = std::count_if(nums.begin(), nums.end(), isOdd());
int even_count = std::count_if(nums.begin(), nums.end(), isEven());
```

### Regular Functions
```cpp
bool isEqual(int x, int y) { return x == y; }

// Using regular functions
bool result = isEqual(5, 5);
```

## 🏋️ Exercises

### Bind Exercises
- **Exercise 1**: Using `bind` with `find_if` to check string sizes against a vector of lengths

### Lambda Exercises
- **Lambda Sort Test**: Using lambdas for custom sorting
- **Lambda Tests**: Basic lambda syntax and capture examples
- **Partition Test**: Using lambdas with `std::partition`

### Iterator Exercises
- **Reverse Iterators**: Working with reverse iterators for various operations
- **Revisiting Iterators**: Using `unique_copy` with different predicates

### Algorithm Exercises
- **Fill N**: Demonstrating `std::fill_n` usage
- **New File**: Advanced lambda capture examples

## 🎓 Key Takeaways

1. **Generic algorithms** work with iterators, not containers directly
2. **Bind** allows adapting function interfaces for algorithm requirements
3. **Lambdas** provide concise inline function definitions
4. **Iterators** come in different categories with different capabilities
5. **Insert iterators** allow algorithms to add elements to containers
6. **Iostream iterators** enable reading/writing directly to streams
7. **Reverse iterators** provide backward traversal capabilities
8. **Function objects** and **regular functions** can be passed to algorithms

## 📖 Further Reading

- C++ Standard Library documentation
- Iterator concepts and categories
- Lambda capture modes and best practices
- Algorithm complexity and performance considerations
- Custom function objects and predicates

---

*This chapter provides the foundation for using C++'s powerful generic algorithms effectively in your programs.* 