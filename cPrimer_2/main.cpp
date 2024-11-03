#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include <string>
using std::string;
#include <cctype>
using std::toupper, std::tolower, std::ispunct, std::isspace;
#include <vector>
using std::vector;

int main() {

	string line;
	decltype(line.size()) index;

	while (getline(cin, line)) {
		for (index = 0; index < line.size() && !isspace(line[index]); ++index) {
			line[index] = toupper(line[index]);
		}
		cout << line << endl;
	}

	return 0;


}