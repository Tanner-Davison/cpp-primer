#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include <string>
#include <cctype>
#include <vector>
using std::toupper, std::tolower, std::ispunct, std::isspace, std::string, std::vector;

int main() {

	string line;
	decltype(line.size()) index;

	while (getline(cin, line)) {
		for (auto it = line.begin(); it != line.end() && !isspace(*it); ++it) {
			*it = toupper(*it);
		}
		cout << line << endl;
	}

	return 0;


}