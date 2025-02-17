#pragma once
#include <iostream>
#include <string>

class Sales_data {
public:
  // Constructors
  Sales_data() = default;
  Sales_data(std::string id, unsigned units_s, double avg_p);
  explicit Sales_data(std::istream &is);
  Sales_data(const Sales_data &) = default;

  // Member functions
  void printSalesReport(std::ostream &out) const;
  void logTime(std::ostream &out);
  std::string isbn() &;
  Sales_data &combine(Sales_data &other);

  // Operators
  Sales_data &operator=(const Sales_data &rhs);
  Sales_data &operator+=(const Sales_data &rhs);

  // Inline member functions
  inline double avg_price() const;

  // Friend functions
  friend std::istream &operator>>(std::istream &in, Sales_data &data);
  friend void print(std::ostream &out, const Sales_data &item);
  friend Sales_data add(const Sales_data &obj1, const Sales_data &obj2);
  friend bool read(std::istream &in, Sales_data &item);

private:
  std::string item_id;
  unsigned units_sold = 0;
  double price = 0.0;
  double revenue = 0.0;
};

// inline Definitions
inline double Sales_data::avg_price() const {
  return units_sold ? (revenue / units_sold) : 0.0;
}

// Forward declarations
std::istream &operator>>(std::istream &in, Sales_data &data);
void print(std::ostream &out, const Sales_data &item);
Sales_data add(const Sales_data &obj1, const Sales_data &obj2);
bool read(std::istream &in, Sales_data &item);
