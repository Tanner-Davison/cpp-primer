#pragma once
#include <iostream>
#include <string>

class Sales_data {
public:
  // Constructors
  Sales_data(const std::string id, unsigned units_s, double avg_p);
  Sales_data(const std::string, unsigned);
  Sales_data();
  explicit Sales_data(std::istream &is);
  Sales_data(const Sales_data &) = default;

  // Member functions
  void printSalesReport(std::ostream &out) const;
  void logTime(std::ostream &out);
  bool compareIsbn(const std::string other_isbn) const;
  // compare isbn 2 objs CHECK INLINE functions at bottom

  std::string isbn() const &;
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

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn() < rhs.isbn();
};
