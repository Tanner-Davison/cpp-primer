//this file is setup to print to output.txt;
#include <iostream>

using namespace std;


int main() {

	constexpr int sz = 10;
	int arr[sz]{};

	int* ptrArr = arr;	//arr[0];
	int* c = &arr[10];	//points to 1 past the last element;

	int count = 0;
	for (int* b = arr; b != c; ++b) {

		*b = ++count;	//increments count by 1 adding value to b;
		cout << *b << endl;

	}
	return 0;
}