#include <iostream>
#include "Sales_item.h"
#include "Sales_data.h"
#include<sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

	int total = 0;			  // Highest number of consecutive duplicates
	string winning_word = ""; //most consecutive duplicates
	string test_string = "this this is is is a test test test test";
	stringstream s(test_string);
	string word;
	string current_word = "";
	int count = 1;

	while (s >> word) {
		if (word == current_word) {
			if (count >= total) {
				total = ++count;
				winning_word = current_word;
			}
			++count;
		}
		else {
			if (count > total) {
				total = count;
				winning_word = word;
			}
			count = 1;
			current_word = word;
		};
	}
	cout << "'" << winning_word << "'" << " count: " << total << endl;

	return 0;
}