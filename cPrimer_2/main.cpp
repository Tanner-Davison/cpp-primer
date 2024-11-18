#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

	fstream inFile("input_add_item.txt");

	if (!inFile) {
		cout << "no input file found!" << endl;
		return 1;

	}
	vector<unsigned>vwls{ 0,0,0,0,0 };

	string line;

	while (getline(inFile, line)) {
		stringstream ss(line);
		unsigned char c;
		while (ss >> c) {
			switch (c) {
			case 'a':
				++vwls[0];
				break;
			case 'e':
				++vwls[1];
				break;
			case 'i':
				++vwls[2];
				break;
			case 'o':
				++vwls[3];
				break;
			case 'u':
				++vwls[4];
				break;
			}
		}
	}
	int total = 0;
	for (int num : vwls) {
		total += num;
	}
	cout << "Number of vowels a: \t" << vwls[0] << "\n"
		<< "Number of vowels e: \t" << ++vwls[1] << "\n"
		<< "Number of vowels i: \t" << ++vwls[2] << "\n"
		<< "Number of vowels o: \t" << ++vwls[3] << "\n"
		<< "Number of vowels u: \t" << ++vwls[4] << "\n"
		<< "\n Total Vowels: \t" << total << "\n";
	return 0;
}