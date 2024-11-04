#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream, std::getline;
using std::cout, std::endl;



int main() {
	ifstream inFile("inputs.txt");
	string line;
	if (!inFile) cout << "No file exists" << endl;

	vector<int> ivec;

	while (getline(inFile, line)) {
		istringstream iss(line);
		int word;
		while (iss >> word) {
			ivec.push_back(word);
		}
	}

	if (ivec.empty()) {
		cout << "Vector is empty" << endl;
		return 1;
	}
	else {
		for (int& word : ivec) {
			unsigned long long wordl{ static_cast<unsigned long long>(word) * 80 };
			cout << word << " * 80 = " << wordl << endl;
		}
	}
	return 0;
}