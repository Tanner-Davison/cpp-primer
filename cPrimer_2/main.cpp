#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;
#include<sstream>
#include <fstream>
#include <iomanip>
using std::fixed, std::setprecision;
using std::ifstream;
using std::istringstream;
using std::string;
using std::getline;

int main() {

	ifstream inFile("input_add_item.txt");
	string line;
	vector<unsigned>clusters(11, 0);
	double test_count = 0;
	while (getline(inFile, line)) {
		istringstream iss(line);
		unsigned score;
		while (iss >> score) {
			if (score <= 100) {
				++test_count;
				++clusters[score / 10]; //adding 1 to custers at index score/10;
			}
		}
	}
	int count = 0;
	cout << "\n\t  Range   #" << " % \n"
		<< "\t  -----   -" << " - " << endl;
	for (auto& score : clusters) {
		if (count >= 100) {
			cout << "\t[  " << count << "+ ] ";
		}
		else if (count < 10) {
			cout << "\t[0" << count << " - 0" << (count + 9) << "] ";
		}
		else {
			cout << "\t[" << count << " - " << (count + 9) << "] ";
		}
		cout << score << " ";
		if (score == 0) {
			cout << " -";
		}
		else {
			cout << fixed << setprecision(2)
				<< ((static_cast<double>(score) / test_count) * 100)
				<< "%";
		}
		cout << endl;

		count += 10;
	}
	return 0;


}