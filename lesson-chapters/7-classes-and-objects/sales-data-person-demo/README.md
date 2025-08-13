# Sales Data & Person Demo

This subdirectory demonstrates fundamental class design concepts using two main classes: `Sales_data` and `Person`.

## 📁 Files

- **main.cpp**: Main demonstration program showing both classes in action
- **Sales_data.hpp/cpp**: Complete Sales_data class implementation
- **Person.hpp/cpp**: Person class implementation
- **input.txt**: Sample sales data for testing
- **person.txt**: Sample person data for testing

## 🎯 Learning Objectives

### Sales_data Class
- **Constructors**: Multiple constructor overloads
- **Operator Overloading**: `=`, `+=` operators
- **Friend Functions**: I/O operators (`>>`, `<<`)
- **Member Functions**: `combine()`, `isbn()`, `avg_price()`
- **Data Processing**: Sales data aggregation and reporting

### Person Class
- **Basic Class Design**: Simple class with getters/setters
- **Friend Functions**: Custom I/O operations
- **Member Functions**: `add()` method for combining persons
- **Data Validation**: Input/output handling

## 🚀 How to Compile and Run

```bash
g++ -std=c++17 main.cpp Sales_data.cpp Person.cpp -o sales_person_demo
./sales_person_demo
```

## 📊 Sample Output

The program demonstrates:
1. Reading sales data from `input.txt`
2. Aggregating sales by ISBN
3. Displaying sales reports
4. Reading person data from `person.txt`
5. Displaying person information

## 🔧 Key Concepts Demonstrated

- **Class Design**: Proper encapsulation and interface design
- **Operator Overloading**: Custom behavior for built-in operators
- **Friend Functions**: Non-member functions with private access
- **I/O Operations**: Custom input/output for user-defined types
- **Data Processing**: Real-world data handling patterns

This demo provides a solid foundation in C++ class design and object-oriented programming principles. 