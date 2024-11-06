#include <iostream>
#include "Sales_item.h"
#include "Sales_data.h"
#include<sstream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {

	fstream inFile("input_add_item.txt");

	//check to ensure input file exist.
	if (!inFile) cout << "No file found!" << endl;

	//create vector container;
	vector<string> vec1;
	//type to read;
	string line;

	string sought = "hello";

	while (getline(inFile, line)) {
		if (!line.empty()) {
			string temp;
			auto sbeg = line.begin(), send = line.end();
			for (auto it = sbeg; it != send && !isspace(*it); ++it) {
				temp += *it;
			}
			vec1.emplace_back(temp);
		}
	}
	//first sort the vector; binary search only works on sorted data;
	sort(vec1.begin(), vec1.end());
	//setup iterators;
	auto beg = vec1.begin(), end = vec1.end();
	auto mid = beg + (end - beg) / 2;

	while (mid != end && *mid != sought) {
		if (sought < *mid) {
			end = mid;
		}
		else {
			beg = mid + 1;
		}
		mid = beg + (end - beg) / 2;
	}
	if (mid != end && *mid == sought) {
		cout << "Found " << *mid << " at position " << (mid - vec1.begin()) << endl;
	}
	else {
		cout << "Value not found" << endl;
	}

	return 0;


}