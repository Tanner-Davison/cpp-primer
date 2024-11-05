#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace {
	using namespace std;
}

int main() {

	fstream inFile("opposite_pairs.txt");
	string line;
	vector<int> int_container;

	if (!inFile)
		cout << "No file found!" << endl;

	while (getline(inFile, line)) {

		istringstream iss(line);
		int add_num;

		while (iss >> add_num) {
			int_container.emplace_back(add_num);
		}
	}
	int last_num = int_container.size();
	for (decltype(int_container.size()) index = 0; index < int_container.size() / 2; ++index) {
		cout << int_container[index] << " + "
			<< int_container[--last_num] << " = "
			<< (int_container[index] + int_container[last_num])
			<< endl;
	}

	return 0;
}