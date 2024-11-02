#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>

struct Sales_data {
	std::string item_id;
	unsigned units_sold = 0;
	double revenue = 0.0;

	void printSalesReport(std::ostream& out) const {
		double asp = units_sold ? (revenue / units_sold) : 0.0;

		// Write everything to the passed-in stream 'out'
		out << "\n" << item_id
			<< "\nItems sold: \t" << units_sold
			<< "\nTotal revenue: \t$" << revenue
			<< "\nASP: $" << asp;

		if (asp == 0) {
			out << "\t\t(No Items Sold)";
		}
		out << std::endl;
	}

	void logTime(std::ostream& out) {
		// Log the time
		auto now = std::chrono::system_clock::now();
		auto time = std::chrono::system_clock::to_time_t(now);
		struct tm timeinfo;
		localtime_s(&timeinfo, &time);
		out << "\n=========================\n"
			<< "Time recorded: "
			<< std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S")
			<< "\n=========================\n";
	}
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

