#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <ostream>
#include <istream>
using namespace std;
//uppercases all string
void up(string& str) {
	if (!str.empty())
		for (auto it = str.begin(); it < str.end(); ++it) {
			*it = toupper(*it);
		}
}
//uppercases first letter of string;
void upfirst(string& str) {
	auto it = str.begin();
	if (!str.empty()) {
		if (!isspace(*it)) {
			*it = toupper(*it);
		}
	}
}

struct Rep {
	string company, title, rep;
	vector<string> garbage;
	Rep(vector<string>& reps) {
		if (reps.size() >= 3) {
			company = reps[0];
			title = reps[1];
			rep = reps[2];
		}
		if (reps.size() > 3) {
			garbage.assign(reps.begin() + 3, reps.end());
			for (auto& word : garbage) {
				up(word);
			}
		}
		up(title);
		upfirst(company);
		upfirst(rep);
	}
	friend ostream& operator <<(ostream& output, const Rep& rep) {
		output << rep.title << " " << rep.company << " " << rep.rep << "\n";
		if (rep.garbage.size() > 0) {
			output << "\n\tGarbage Found: [";
			for (auto g : rep.garbage) {
				output << g << ",";
			}
			if (!rep.garbage.empty()) {
				output << rep.garbage.back();
			}
			output << "] " << "\n";
		}

		return output;
	}
};

int main() {

	fstream inFile("input_add_item.txt");
	if (!inFile) cout << "No input file found!" << endl;
	string title, company, rep;
	string line;

	vector<Rep> allReps;

	while (getline(inFile, line)) {
		vector<string> singleRep;
		string word;
		//go through each line assaigning word to valid character and push to array;
		for (auto linep = line.begin(); linep != line.end(); ++linep) {
			if (!isspace(*linep)) {
				word += *linep;
			}
			else if (!word.empty()) {
				singleRep.push_back(word);
				word.clear();
			}
		}
		if (!word.empty()) {
			singleRep.push_back(word);
			word.clear();
		}
		if (!singleRep.empty()) {
			Rep newRep = singleRep;
			allReps.push_back(newRep);
		}
	}

	for (auto r : allReps) {
		cout << r << endl;
	}



	return 0;
}