#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	fstream inFile("input_add_item.txt");

	if (!inFile) {
		cout << "no input file found!" << endl;
		return 1;
	}

	unsigned acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0;

	string line;

	while (getline(inFile, line)) {
		stringstream ss(line);
		unsigned char c;
		while (ss >> c) {
			switch (c) {
			case 'a':
				++acnt;
				break;
			case 'e':
				++ecnt;
				break;
			case 'o':
				++ocnt;
				break;
			case 'u':
				++ucnt;
				break;
			}
		}
	}
	cout << "Number of vowels a: \t" << acnt << "\n"
		<< "Number of vowels e: \t" << ecnt << "\n"
		<< "Number of vowels i: \t" << icnt << "\n"
		<< "Number of vowels o: \t" << ocnt << "\n"
		<< "Number of vowels u: \t" << ucnt << "\n";
	return 0;
}