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
	if (!inFile) cout << "No file found!" << endl;

	vector<string> vec1;
	string line;
	//adding for vim motions.

	string sought = "hello";

	while (getline(inFile, line)) {

		if (!line.empty()) {
			string word = "";
			for (auto it = line.begin(); it != line.end(); ++it) {
				if (isspace(*it)) {
					vec1.emplace_back(word);
					word = "";
				}
				else {
					word += *it;
				}
			}
			if (!word.empty()) {
				vec1.emplace_back(word);
			}
		}
	}
	//first sort the vector; binary search only works on sorted data;
	sort(vec1.begin(), vec1.end());
	//setup iterators;
	//Adding a line with vim
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
	int count = 0;
	if (mid != end && *mid == sought) {
		cout << "Found " << *mid << " at position " << (mid - vec1.begin()) << endl;
		for (auto c : vec1) {
			cout << c << " ";
			++count;
			if (count >= 2) {
				count = 0;
				cout << endl;
			}
		}
	}
	else {
		cout << "Value not found" << endl;
	}

	return 0;
}
