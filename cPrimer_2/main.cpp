#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include<sstream>
using std::istringstream;
#include <string>
using std::toupper;
using std::string;


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
		}
		cout << endl;
	}
	return 0;
}