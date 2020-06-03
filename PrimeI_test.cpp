#include "PrimeI.h"
//#include <iostream>
using namespace std;

int main(void) {
	int numAmount = 6;
	unsigned int *nums = new unsigned int[numAmount] { 0, 4, 8, 10, 11, 12 };
	int numdAmount = 2;
	unsigned int *numsd = new unsigned int[numdAmount] { 13, 15 };

	int allAmount = numAmount + numdAmount;

	MTerm *ms = new MTerm[allAmount];
	for (int i = 0; i < numAmount; i++) {
		ms[i] = new MTerm(nums[i], 4, false);
	}
	for (int i = 0; i < numdAmount; i++) {
		ms[numAmout + i] = new MTerm(numsd[i], 4, true);
	}

	PrimeI *pis = new PrimeI[allAmount];
	cout << "Print Initial PIs" << endl;
	for (int i = 0; i < allAmount; i++) {
		pis[i] = new PrimeI(ms[i]);
		cout << pis[i] << endl;
	}

	return 0;
}
