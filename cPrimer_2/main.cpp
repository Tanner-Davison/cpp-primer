#include <iostream>
#include "Sales_item.h"
#include "Sales_data.h"
#include <string>




int main() {
	Sales_data curr_id, next_id, data1, data2;

	double price = 0;

	if (std::cin >> curr_id) {
		Sales_data same_id;
		unsigned asp;
		while (std::cin >> same_id) {

			if (curr_id.item_id == same_id.item_id) {

				curr_id.units_sold += same_id.units_sold;
				curr_id.revenue += same_id.revenue;
			}
			else {
				asp = curr_id.revenue / curr_id.units_sold;
				std::cout << "\n" << curr_id.item_id
					<< "\nItems sold: \t" << curr_id.units_sold
					<< "\nTotal revenue: \t$" << curr_id.revenue
					<< "\nASP: $" << asp << std::endl;
				asp == 0 && std::cout << "(No Items Sold)" << std::endl;
				curr_id = same_id;

			}
		}
		asp = curr_id.revenue / curr_id.units_sold;
		std::cout << "\n" << curr_id.item_id
			<< "\nItems sold: \t" << curr_id.units_sold
			<< "\nTotal revenue: \t$" << curr_id.revenue
			<< "\nASP: $" << asp << std::endl;

		asp == 0 && std::cout << "\t\t(No Items Sold)" << std::endl;
	}
	return 0;


	/*std::cin >> data1.item_id >> data1.units_sold >> price;
	data1.revenue = price * data1.units_sold;

	std::cin >> data2.item_id >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;


	if (data1.item_id == data2.item_id) {

		unsigned totalcnt = data1.units_sold + data2.units_sold;
		double totalrevenue = data1.revenue + data2.revenue;

		std::cout << data1.item_id
			<< "\n# of items sold: " << totalcnt << " "
			<< "\ntotal revenue: $" << totalrevenue << " ";


		if (totalrevenue != 0) {
			std::cout << "\nasp: $"
				<< totalrevenue / totalcnt
				<< std::endl;
		}
		else {
			std::cout << "\n\t(no sales)" << std::endl;
		}
		return 0;
	}
	else {
		std::cerr << "data must refer to the same item_id"
			<< std::endl;
	}
	return 0;*/
}