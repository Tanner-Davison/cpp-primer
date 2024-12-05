#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
#include <utility> 

using namespace std;

int countWords(string str) {

	//loading str into the string stream;
	stringstream s(str);

	string word;

	int count = 0;

	/*read each word skipping white spaces into word simultanously tracking
	word count. */
	while (s >> word) {
		cout << "\nIteration" << (count + 1) << ": word = '" << word << "'" << endl;
		count++;
	}

	return count;

}



int main() {

	fstream inFile("input_add_item.txt");

	if (!inFile) {
		cout << "Error no file found" << endl;
		return 1;
	}
	int points = 100;

	vector<pair<string, string>> qa;

	string current_line;

	int line_count = 0;
	string question, answer;

	while (getline(inFile, question) && getline(inFile, answer)) {
		if (!question.empty() && !answer.empty()) {
			qa.emplace_back(question, answer);
		}
	}
	if (qa.empty()) {
		cout << "No questions found in file." << endl;
		return 1;
	}
	cout << qa[0].first << "\n";

	string human_response;
	getline(cin, human_response);

	if (human_response == qa[0].second) {
		cout << "PASS" << endl;
	}
	else {
		cout << "FAIL" << endl;
	}



	return 0;
}