# C++ Associative Containers Function Reference

## Container Types Overview

### Ordered Containers (Red-Black Trees)
- **`std::set<T>`** - Unique elements, sorted
- **`std::multiset<T>`** - Duplicate elements allowed, sorted  
- **`std::map<Key, T>`** - Unique key-value pairs, sorted by key
- **`std::multimap<Key, T>`** - Duplicate keys allowed, sorted by key

### Unordered Containers (Hash Tables)
- **`std::unordered_set<T>`** - Unique elements, no ordering
- **`std::unordered_multiset<T>`** - Duplicate elements allowed, no ordering
- **`std::unordered_map<Key, T>`** - Unique key-value pairs, no ordering
- **`std::unordered_multimap<Key, T>`** - Duplicate keys allowed, no ordering

---

## Common Functions (All Containers)

### Capacity
```cpp
bool empty() const;                    // Check if container is empty
size_type size() const;                // Number of elements
size_type max_size() const;            // Maximum possible size
```

### Iterators
```cpp
iterator begin();                      // Iterator to first element
const_iterator begin() const;
const_iterator cbegin() const;         // Const iterator to first element

iterator end();                        // Iterator past last element  
const_iterator end() const;
const_iterator cend() const;           // Const iterator past last element
```

### Element Access & Search
```cpp
iterator find(const Key& key);         // Find element by key
const_iterator find(const Key& key) const;

size_type count(const Key& key) const; // Count elements with key
bool contains(const Key& key) const;   // C++20: Check if key exists
```

### Modifiers
```cpp
void clear();                          // Remove all elements
void swap(container& other);           // Swap contents with another container

iterator erase(const_iterator pos);           // Erase by iterator
iterator erase(const_iterator first, last);   // Erase range
size_type erase(const Key& key);              // Erase by key
```

---

## Insertion Functions

### Single Element Insertion
```cpp
// All containers
pair<iterator, bool> insert(const value_type& value);           // Copy
pair<iterator, bool> insert(value_type&& value);                // Move
iterator insert(const_iterator hint, const value_type& value);  // With hint

// C++11: Construct in-place
template<class... Args>
pair<iterator, bool> emplace(Args&&... args);
template<class... Args>  
iterator emplace_hint(const_iterator hint, Args&&... args);
```

### Map-Specific Insertion (C++17)
```cpp
// Only for map/unordered_map
template<class... Args>
pair<iterator, bool> try_emplace(const Key& key, Args&&... args);
template<class... Args>
pair<iterator, bool> try_emplace(Key&& key, Args&&... args);

// With hint
template<class... Args>
iterator try_emplace(const_iterator hint, const Key& key, Args&&... args);
```

### Range Insertion
```cpp
template<class InputIt>
void insert(InputIt first, InputIt last);     // Insert range

void insert(initializer_list<value_type> il); // Insert from initializer list
```

---

## Map-Only Functions

### Element Access
```cpp
T& operator[](const Key& key);         // Insert or access (non-const only)
T& operator[](Key&& key);              // Move version

T& at(const Key& key);                 // Access with bounds checking
const T& at(const Key& key) const;     // Const version
```

### Assignment (C++17)
```cpp
template<class M>
pair<iterator, bool> insert_or_assign(const Key& key, M&& obj);
template<class M>
pair<iterator, bool> insert_or_assign(Key&& key, M&& obj);

// With hint
template<class M>
iterator insert_or_assign(const_iterator hint, const Key& key, M&& obj);
```

---

## Ordered Container Specific

### Range Operations
```cpp
iterator lower_bound(const Key& key);         // First element >= key
const_iterator lower_bound(const Key& key) const;

iterator upper_bound(const Key& key);         // First element > key  
const_iterator upper_bound(const Key& key) const;

pair<iterator, iterator> equal_range(const Key& key);           // Range of equal elements
pair<const_iterator, const_iterator> equal_range(const Key& key) const;
```

### Comparison Object
```cpp
key_compare key_comp() const;          // Get key comparison function
value_compare value_comp() const;      // Get value comparison function (maps only)
```

---

## Unordered Container Specific

### Bucket Interface
```cpp
size_type bucket_count() const;        // Number of buckets
size_type max_bucket_count() const;    // Maximum buckets possible
size_type bucket_size(size_type n) const;     // Elements in bucket n
size_type bucket(const Key& key) const;       // Bucket for key

local_iterator begin(size_type n);     // Iterator to bucket n
local_iterator end(size_type n);
const_local_iterator begin(size_type n) const;
const_local_iterator end(size_type n) const;
const_local_iterator cbegin(size_type n) const;
const_local_iterator cend(size_type n) const;
```

### Hash Policy
```cpp
float load_factor() const;             // Current load factor
float max_load_factor() const;         // Maximum load factor
void max_load_factor(float ml);        // Set maximum load factor

void rehash(size_type count);          // Rehash to at least count buckets
void reserve(size_type count);         // Reserve space for count elements
```

### Hash Function Access
```cpp
hasher hash_function() const;          // Get hash function object
key_equal key_eq() const;              // Get key equality predicate
```

---

## Node Extraction (C++17)

### Extract Operations
```cpp
node_type extract(const_iterator position);   // Extract by iterator
node_type extract(const Key& key);            // Extract by key
```

### Insert Node
```cpp
insert_return_type insert(node_type&& nh);                    // Unique containers
iterator insert(node_type&& nh);                              // Multi containers
iterator insert(const_iterator hint, node_type&& nh);         // With hint
```

### Merge Operations
```cpp
template<class C2>
void merge(C2& source);                // Move elements from compatible container
template<class C2>  
void merge(C2&& source);               // Move version
```

---

## Usage Examples

### Basic Operations
```cpp
std::map<std::string, int> grades;

// Insertion
grades.insert({"Alice", 95});
grades.emplace("Bob", 87);
grades["Charlie"] = 92;                // Insert or assign
auto [it, success] = grades.try_emplace("David", 88);

// Search
auto it = grades.find("Alice");
if (it != grades.end()) {
    std::cout << it->second << std::endl;
}

// C++20
if (grades.contains("Bob")) {
    std::cout << "Bob found\n";
}

// Range operations (ordered only)
auto lower = grades.lower_bound("A");
auto upper = grades.upper_bound("C");
```

### Unordered Container Optimization
```cpp
std::unordered_map<int, std::string> cache;
cache.reserve(1000);                   // Prevent rehashing

// Check load factor
if (cache.load_factor() > 0.75) {
    cache.rehash(cache.bucket_count() * 2);
}
```

### Node Extraction Example
```cpp
std::map<int, std::string> source = {{1, "one"}, {2, "two"}};
std::map<int, std::string> dest;

// Move element without allocation
auto node = source.extract(1);
dest.insert(std::move(node));
```

---

## Performance Characteristics

### Ordered Containers (Red-Black Trees)
- **Insertion**: O(log n)
- **Deletion**: O(log n)
- **Search**: O(log n)
- **Space**: O(n)
- **Iteration**: In-order traversal

### Unordered Containers (Hash Tables)
- **Insertion**: O(1) average, O(n) worst case
- **Deletion**: O(1) average, O(n) worst case
- **Search**: O(1) average, O(n) worst case
- **Space**: O(n)
- **Iteration**: No guaranteed order

---

## When to Use Each Container

### Use Ordered Containers When:
- You need elements sorted by key
- You need range operations (lower_bound, upper_bound)
- You need predictable iteration order
- Memory usage is more important than speed
- You're working with small datasets

### Use Unordered Containers When:
- You need fast average-case operations
- Order doesn't matter
- You have good hash functions
- You're working with large datasets
- You need to avoid worst-case scenarios

---

## Common Pitfalls

### 1. Iterator Invalidation
```cpp
std::map<int, int> m = {{1, 10}, {2, 20}};
auto it = m.find(1);
m.erase(it);  // it is now invalid
// ++it;      // Undefined behavior!
```

### 2. Const Correctness
```cpp
const std::map<int, std::string> cm = {{1, "one"}};
// cm[1] = "two";  // Won't compile - operator[] is not const
auto it = cm.find(1);  // Use find() for const access
```

### 3. Hash Function Requirements
```cpp
// Custom types need proper hash functions
struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// Need to provide hash function for unordered containers
namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };
}
```

### 4. Memory Management
```cpp
// Be careful with pointers in containers
std::map<int, std::unique_ptr<MyClass>> ptr_map;
ptr_map[1] = std::make_unique<MyClass>();  // Automatic cleanup

// Avoid raw pointers unless you manage memory carefully
std::map<int, MyClass*> raw_ptr_map;  // Potential memory leaks
```

---

## Best Practices

### 1. Choose the Right Container
```cpp
// For simple lookups without ordering
std::unordered_map<std::string, int> cache;

// For sorted data with range queries
std::map<std::string, int> sorted_data;

// For unique elements with ordering
std::set<int> unique_sorted;

// For duplicate elements without ordering
std::unordered_multiset<int> bag;
```

### 2. Use Reserve for Unordered Containers
```cpp
std::unordered_map<int, std::string> large_map;
large_map.reserve(10000);  // Avoid rehashing
```

### 3. Leverage Structured Bindings (C++17)
```cpp
std::map<std::string, int> scores;
if (auto [it, inserted] = scores.insert({"Alice", 95}); inserted) {
    std::cout << "New score added\n";
}
```

### 4. Use Const References for Keys
```cpp
// Good
void process_map(const std::map<std::string, int>& data) {
    for (const auto& [key, value] : data) {
        // Process key-value pair
    }
}

// Avoid copying keys unnecessarily
```

### 5. Consider Move Semantics
```cpp
std::map<int, std::string> source;
// ... populate source ...

std::map<int, std::string> dest;
// Move elements efficiently
for (auto&& [key, value] : source) {
    dest.emplace(std::move(key), std::move(value));
}
```

---

## Advanced Techniques

### 1. Custom Comparators
```cpp
// Custom comparison for case-insensitive string keys
struct CaseInsensitiveCompare {
    bool operator()(const std::string& a, const std::string& b) const {
        return std::lexicographical_compare(
            a.begin(), a.end(), b.begin(), b.end(),
            [](char c1, char c2) {
                return std::tolower(c1) < std::tolower(c2);
            }
        );
    }
};

std::map<std::string, int, CaseInsensitiveCompare> case_insensitive_map;
```

### 2. Heterogeneous Lookup (C++14)
```cpp
// Allow lookup with different but comparable types
std::map<std::string, int, std::less<>> heterogeneous_map;
heterogeneous_map["hello"] = 42;

// Can lookup with string_view (C++17)
std::string_view sv = "hello";
auto it = heterogeneous_map.find(sv);  // Works!
```

### 3. Transparent Comparators (C++14)
```cpp
// More efficient heterogeneous lookup
std::map<std::string, int, std::less<>> transparent_map;
std::string_view sv = "key";
auto it = transparent_map.find(sv);  // No temporary string created
```

---

*This reference covers the essential functions and usage patterns for C++ associative containers. For the most up-to-date information, consult the C++ Standard Library documentation.* 