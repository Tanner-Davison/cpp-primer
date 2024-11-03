#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include <string>

using std::toupper;
using std::string;


int main() {

	string str1, str2;

	decltype(str1.size()) str1Cnt = 0; //best practice to ensure length when counting;
	decltype(str2.size()) str2Cnt = 0;//dont use size_t for strings;

	cin >> str1;
	cin >> str2;

	for (auto& c : str1) {
		c = toupper(c);
		++str1Cnt;
	}
	for (auto& c : str2) {
		c = toupper(c);
		++str2Cnt;
	}
	if (str1Cnt == str2Cnt) {
		cout << str1 << " count: " << str1Cnt
			<< " is equal to "
			<< str2 << " count: " << str2Cnt << endl;
	}
	else {
		if (str1Cnt > str2Cnt) {
			cout << str1 << " is greater than " << str2 << " by: "
				<< (str1Cnt - str2Cnt) << " characters" << endl;
		}
		else {
			cout << str2 << " is greater than " << str1 << " by: "
				<< (str2Cnt - str1Cnt) << " characters" << endl;
		}
	}
	return 0;


}