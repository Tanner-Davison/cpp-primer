#include <iostream>
#include "Sales_item.h"
#include "Sales_data.h"
#include <string>


int main() {
	Sales_data curr_id, next_id;

	double price = 0;

	curr_id.logTime(std::cout);
	if (std::cin >> curr_id) {
		Sales_data same_id;
		unsigned asp;
		int total_item_count = 0;
		while (std::cin >> same_id) {

			if (curr_id.item_id == same_id.item_id) {

				curr_id.units_sold += same_id.units_sold;
				curr_id.revenue += same_id.revenue;
				total_item_count++;
			}
			else {
				total_item_count++;
				curr_id.printSalesReport(std::cout);
				curr_id = same_id;
			}
		}
		curr_id.printSalesReport(std::cout);
		std::cout << "\n\t Items accounted: " << ++total_item_count;
	}


	return 0;


}