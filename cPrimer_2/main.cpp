#include <iostream>
using std::cin, std::cout, std::endl;
#include "Sales_item.h"
#include "Sales_data.h"
#include<sstream>
using std::istringstream;
#include <string>
using std::tolower, std::isalpha, std::isspace;
using std::string, std::erase;
#include <fstream>

int main() {
	std::ifstream inFile("erase_puncs.txt");

	string result;

	cout << "Enter a series test of numbers from 0-15\n"
		"Separated by ' [spaces] ' Hit [enter] when finished.\n" << endl;

	//open file from ifstream
	if (!inFile) {
		cout << "Error opening file" << std::endl;
		return 1;
	}	if (!inFile) {
		cout << "Error opening file" << std::endl;
		return 1;
	}

	while (getline(inFile, result)) {
		decltype(result.size()) n;

		for (n = 0; n < result.size(); ++n) {
			if (ispunct(result[n])) {
				result.erase(n, 1); // erase 1 char at element result[n];
				--n;
			}
		}
		cout << result;
	}
	inFile.close();




	return 0;


}
