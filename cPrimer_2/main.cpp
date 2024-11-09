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

int main() {

	char ca[] = { 'c','h','a','r','\0' };
	char ca2[] = { 'a','r','r','a','y','\0' };

	string combined;
	combined += ca;
	combined += " ";
	combined += ca2;

	auto* p = &combined;
	while (p)
	{
		cout << *p;
		++p;
	}

	cout << endl;

	return 0;
}