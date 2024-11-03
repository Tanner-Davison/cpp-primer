#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include<sstream>
using std::istringstream;
#include <string>
using std::toupper;
using std::string;


using  std::cout, std::endl, std::cin;

int main() {
	const string hexdigits = "0123456789ABCDEF";
	string result;
	decltype(result.size()) n;
	cout << "Enter a series of numbers from 0-15\n"
		"Separated by ' [spaces] ' Hit [enter] when finished.\n" << endl;

	while (getline(cin, result)) {
		std::istringstream iss(result);
		while (iss >> n) {
			if (n < hexdigits.size()) {
				cout << hexdigits[n];
			}
			else {
				auto r = (n % 16);
				auto d = (n / 16);
				cout << hexdigits[d] << hexdigits[r];

			}
		}
		cout << endl;
	}

	Sales_data curr_id, next_id;

	double price = 0;

	curr_id.logTime(cout);
	if (cin >> curr_id) {
		Sales_data same_id;
		unsigned asp;
		int total_item_count = 0;
		while (cin >> same_id) {

			if (curr_id.item_id == same_id.item_id) {

				curr_id.units_sold += same_id.units_sold;
				curr_id.revenue += same_id.revenue;
				total_item_count++;
			}
			else {
				total_item_count++;
				curr_id.printSalesReport(cout);
				curr_id = same_id;
			}
		}
		curr_id.printSalesReport(cout);
		cout << "\n\t Items accounted: " << ++total_item_count;
	}


	return 0;


}