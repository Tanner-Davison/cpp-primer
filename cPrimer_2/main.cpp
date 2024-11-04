#include <iostream>
using std::cin, std::cout, std::endl;
#include <string>
using std::string, std::erase;
#include <fstream>
using std::ifstream;

int main() {
	ifstream inFile("erase_puncs.txt");

	string result;


	if (!inFile) {//check if file from ifstream is open;
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
				--n;				// go back 1;
			}
		}
		cout << result;
	}
	inFile.close();

	return 0;


}
