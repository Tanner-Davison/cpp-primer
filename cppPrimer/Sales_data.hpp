#pragma once

#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

struct Sales_data {
  std::string item_id;
  unsigned units_sold = 0;
  double revenue = 0.0;
  double avg_price = 0.0;

  Sales_data() = default;

  // Add copy constructor
  Sales_data(const Sales_data &) = default;
  void printSalesReport(std::ostream &out) const {
    double asp = units_sold ? (revenue / units_sold) : 0.0;

    // Write everything to the passed-in stream 'out'
    out << "\n"
        << item_id << "\nItems sold: \t" << units_sold << "\nTotal revenue: \t$"
        << revenue << "\nASP: $" << asp;

    if (asp == 0) {
      out << "\t\t(No Items Sold)";
    }
    out << std::endl;
  }

  void logTime(std::ostream &out) {
    // Log the time
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    struct tm timeinfo;
    localtime_s(&timeinfo, &time);
    out << "\n=========================\n"
        << "Time recorded: " << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S")
        << "\n=========================\n";
  }
  Sales_data &operator=(const Sales_data &rhs) {
    item_id = rhs.item_id;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
  }

  Sales_data &operator+=(const Sales_data &rhs) {
    item_id += rhs.item_id;
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }
  friend std::istream &operator>>(std::istream &in, Sales_data &data);

  std::string isbn() & { return this->item_id; }

  Sales_data &combine(Sales_data &other) {
    this->units_sold += other.units_sold;
    this->revenue += other.revenue;
    return *this;
  }
};
inline std::istream &operator>>(std::istream &in, Sales_data &data) {
  double price = 0;
  in >> data.item_id >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return in;
}
inline Sales_data add(const Sales_data &obj1, const Sales_data &obj2) {
  if (obj1.item_id != obj2.item_id) {
    throw std::runtime_error("Cannot add sales data for different items");
  }
  Sales_data temp;
  temp.item_id = obj1.item_id; // Add this line
  temp.units_sold = obj1.units_sold + obj2.units_sold;
  temp.revenue = obj1.revenue + obj2.revenue;
  return temp;
}
inline bool read(std::istream &in, Sales_data &item) {
  double price = 0.0;
  in >> item.item_id >> item.units_sold >> price;
  if (in.good()) {
    item.revenue = price * item.units_sold;
    return true;
  }
  return false;
}

inline void print(std::ostream &out, const Sales_data &item) {
  out << "Item Id: " << item.item_id << "\n"
      << "Units Sold: " << item.units_sold << "\n"
      << "Total Revenue: " << item.revenue << "\n";
}
