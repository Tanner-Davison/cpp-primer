#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;
using std::istringstream;
#include <fstream>
using std::fstream;
#include <string>
using std::string;
#include <cctype>
using std::isspace;
#include <sstream>
using std::istringstream;




int main() {

	fstream inFile("add_ints.txt");
	string line;
	vector<int> int_container;

	while (getline(inFile, line)) {

		int add_num;
		istringstream iss(line);

		while (iss >> add_num) {
			int_container.emplace_back(add_num);
		}
	}
	int last_num = int_container.back();

	for (decltype(int_container.size()) index = 0; index <= int_container.size(); ++index) {
		if (index < int_container.size() - 1) {
			cout << int_container[index] << " + " << int_container[index + 1]
				<< " = " << (int_container[index] + int_container[index + 1]) << endl;
		}
	}

	return 0;
}