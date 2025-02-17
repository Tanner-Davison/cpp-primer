#pragma once
#include <iostream>
#include <string>

class Sales_data {
public:
  // Constructors
  Sales_data() = default;
  Sales_data(std::string id, unsigned units_s, double avg_p);
  Sales_data(std::istream &is);
  Sales_data(const Sales_data &) = default;

  // Member functions
  void printSalesReport(std::ostream &out) const;
  void logTime(std::ostream &out);
  std::string isbn() &;
  Sales_data &combine(Sales_data &other);

  // Operators
  Sales_data &operator=(const Sales_data &rhs);
  Sales_data &operator+=(const Sales_data &rhs);

  // Friend functions
  friend std::istream &operator>>(std::istream &in, Sales_data &data);
  friend void print(std::ostream &out, const Sales_data &item);
  friend Sales_data add(const Sales_data &obj1, const Sales_data &obj2);
  friend bool read(std::istream &in, Sales_data &item);

private:
  std::string item_id;
  unsigned units_sold = 0;
  double avg_price = 0.0;
  double revenue = 0.0;
};
