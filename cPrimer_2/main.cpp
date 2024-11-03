#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include <string>
using std::string;
#include <cctype>
using std::toupper, std::tolower, std::ispunct;
#include <vector>
using std::vector;

int main() {

	string line;
	vector<char> punc_symbols;
	decltype(line.size()) punct_cnt = 0;

	while (getline(cin, line)) {
		if (!line.empty()) {
			for (auto c : line) {
				if (ispunct(c)) {
					punc_symbols.push_back(c);
					++punct_cnt;
				}
			}
		}
	}
	cout << punct_cnt << " Puncuations found!"
		<< "\nIn Order of appearance: [";

	for (auto p : punc_symbols) {
		cout << p << " , ";
	}

	cout << "]";

	return 0;


}