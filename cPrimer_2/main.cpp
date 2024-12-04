#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
	fstream inFile("input_add_item.txt");
	if (!inFile) {
		cout << "no input file found!" << endl;
		return 1;
	}

	vector<unsigned> vwls{ 0,0,0,0,0,0 };
	unsigned long long count = 0, spaces = 0;
	string line;

	while (getline(inFile, line)) {
		++newline;
		for (unsigned char c : line) {
			if (isspace(c)) {
				++spaces;
			}
			else {
				c = tolower(c);
				switch (c) {
				case 'a': ++vwls[0]; break;
				case 'e': ++vwls[1]; break;
				case 'i': ++vwls[2]; break;
				case 'o': ++vwls[3]; break;
				case 'u': ++vwls[4]; break;
				default: ++count; break;
				}
			}
		}
		++vwls[5];
	}
	int total = 0;
	for (auto num : vwls) {
		total += num;
	}
	const long long lettersTotal = (total + count);

	cout << "Number of vowels a: \t" << vwls[0] << "\n"
		<< "Number of vowels e: \t" << vwls[1] << "\n"
		<< "Number of vowels i: \t" << vwls[2] << "\n"
		<< "Number of vowels o: \t" << vwls[3] << "\n"
		<< "Number of vowels u: \t" << vwls[4] << "\n"
		<< "\n Total Vowels: \t" << total << "\n"
		<< "\n Non-vowels: \t" << count << "\n"
		<< "\n Letter count: " << lettersTotal << "\n"
		<< "\n Blanks, Returns " << vwls[5] << "\n"
		<< "\n Spaces count: " << spaces << "\n";

	if (lettersTotal > 1000) {
		cout << "Thats a lot of letters!" << endl;
	}
	else {
		cout << "You have less than 1000 letters in this test." << endl;
	}

	return 0;
}