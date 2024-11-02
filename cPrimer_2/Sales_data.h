#pragma once
#include <string>
#include <iostream>

struct Sales_data {
	std::string item_id;
	unsigned units_sold = 0;
	double revenue = 0.0;

	Sales_data& operator =(const Sales_data& rhs) {
		item_id = rhs.item_id;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}
	Sales_data& operator +=(const Sales_data& rhs) {
		item_id += rhs.item_id;
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	friend std::istream& operator>>(std::istream& in, Sales_data& data);

};

inline std::istream& operator>>(std::istream& in, Sales_data& data) {
	double price = 0;
	in >> data.item_id >> data.units_sold >> price;
	data.revenue = price * data.units_sold;
	return in;
}