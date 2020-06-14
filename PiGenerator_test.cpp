//#include "MTerm.h"
//#include "PrimeI.h"
// #include <iostream>
// #include <list>
#include <vector>
//#include "PiListContainer.h"
#include "PiGenerator.h"
using namespace std;

int main(void) {
	int mtermsAmount = 6;
	int dontcaresAmount = 2;
	unsigned int nums[8] { 0, 4, 8, 10, 11, 12, 13, 15 };
	list<int> allTerms(&nums[0], &nums[8]);

	auto it = allTerms.begin();
	cout << "allTerms" << endl;
	for (; it != allTerms.end(); it++) {
		cout << *it << " ";
	}

	int nbits = 4;

	cout << "Create PiGenerator" << endl;
	PiGenerator(nbits, allTerms, mtermsAmount, dontcaresAmount);



	cout << "Happy Ending" << endl;
	return 0;
}
