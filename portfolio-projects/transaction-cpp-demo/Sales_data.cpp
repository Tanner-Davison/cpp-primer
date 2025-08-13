#include "Sales_data.hpp"
#include <chrono>
#include <ctime>
#include <iomanip>
Sales_data::Sales_data(std::string id, unsigned units_s, double price_p)
    : item_id(id), units_sold(units_s), price(price_p),
      revenue(price_p * units_s) {}
Sales_data::Sales_data(std::string id, unsigned units_s)
    : Sales_data(id, units_s, 0) {};
Sales_data::Sales_data() : Sales_data(" ", 0, 0) {};

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

void Sales_data::printSalesReport(std::ostream &out) const {
  double asp = units_sold ? (revenue / units_sold) : 0.0;
  out << "\n"
      << item_id << "\nItems sold: \t" << units_sold << "\nTotal revenue: \t$"
      << revenue << "\nASP: $" << asp;
  if (asp == 0) {
    out << "\t\t(No Items Sold)";
  }
  out << std::endl;
}

void Sales_data::logTime(std::ostream &out) {
  auto now = std::chrono::system_clock::now();
  auto time = std::chrono::system_clock::to_time_t(now);
  struct tm timeinfo;
  localtime_s(&timeinfo, &time);
  out << "=========================\n"
      << "Time recorded: " << std::put_time(&timeinfo, "%Y-%m-%d %I:%M %p")
      << "\n=========================\n"
      << "\n";
}

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
  item_id = rhs.item_id;
  units_sold = rhs.units_sold;
  revenue = rhs.revenue;
  return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  item_id += rhs.item_id;
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

std::string Sales_data::isbn() & { return this->item_id; }

Sales_data &Sales_data::combine(Sales_data &other) {
  this->units_sold += other.units_sold;
  this->revenue += other.revenue;
  return *this;
}

// Friend function implementations
void print(std::ostream &out, const Sales_data &item) {
  out << "Item #: " << item.item_id << "\n"
      << "Units Sold: " << item.units_sold << "\n"
      << "Total Revenue: $" << item.revenue << "\n"
      << "Average Price: $" << item.avg_price() << "\n"
      << "\n";
}

std::istream &operator>>(std::istream &in, Sales_data &data) {
  double price = 0;
  in >> data.item_id >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return in;
}

Sales_data add(const Sales_data &obj1, const Sales_data &obj2) {
  if (obj1.item_id != obj2.item_id) {
    throw std::runtime_error("Cannot add sales data for different items");
  }
  Sales_data temp;
  temp.item_id = obj1.item_id;
  temp.units_sold = obj1.units_sold + obj2.units_sold;
  temp.revenue = obj1.revenue + obj2.revenue;
  return temp;
}
bool Sales_data::compareIsbn(const std::string other_isbn) const {
  return other_isbn == item_id;
}

bool read(std::istream &in, Sales_data &item) {
  double price = 0.0;
  in >> item.item_id >> item.units_sold >> price;
  if (in.good()) {
    item.revenue = price * item.units_sold;
    return true;
  }
  return false;
}
