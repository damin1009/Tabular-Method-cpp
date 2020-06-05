#include "PrimeI.h"
//#include <iostream>
using namespace std;

int main(void) {
	int numAmount = 6;
	unsigned int *nums = new unsigned int[numAmount] { 0, 4, 8, 10, 11, 12 };
	int numdAmount = 2;
	unsigned int *numsd = new unsigned int[numdAmount] { 13, 15 };

	int allAmount = numAmount + numdAmount;

	MTerm ms[allAmount];
	for (int i = 0; i < numAmount; i++) {
		ms[i].Init(nums[i], 4, false);
	}
	for (int i = 0; i < numdAmount; i++) {
		ms[numAmount + i].Init(numsd[i], 4, true);
	}

	PrimeI pis[allAmount];
	cout << "Print Initial PIs" << endl;
	for (int i = 0; i < allAmount; i++) {
		pis[i].Init(ms[i]);
		cout << pis[i] << endl;
	}

	cout << "======Combinded======" << endl;

	PrimeI pi_0_4(pis[0], pis[1]); // 0 4 comb
	PrimeI pi_0_8(pis[0], pis[2]); // 0 8 comb

	PrimeI pi_8_10(pis[2], pis[3]); // 8 10 comb
	PrimeI pi_4_12(pis[1], pis[5]); // 4 12 comb
	PrimeI pi_8_12(pis[2], pis[5]); // 8 12 comb

	PrimeI pi_10_11(pis[3], pis[4]); // 10 11 comb
	PrimeI pi_12_13(pis[5], pis[6]); // 12 13 comb

	PrimeI pi_11_15(pis[4], pis[7]); // 11 15 comb
	PrimeI pi_13_15(pis[6], pis[7]); // 13 15 comb

	cout << pi_0_4 << endl;
	cout << pi_0_8 << endl;

	cout << pi_8_10 << endl;
	cout << pi_4_12 << endl;
	cout << pi_8_12 << endl;

	cout << pi_10_11 << endl;
	cout << pi_12_13 << endl;

	cout << pi_11_15 << endl;
	cout << pi_13_15 << endl;

	cout << "======Combinded 2======" << endl;
	PrimeI pi_0_4_8_12a(pi_0_4, pi_8_12);
	PrimeI pi_0_4_8_12b(pi_0_8, pi_4_12);
	cout << pi_0_4_8_12a << endl;
	cout << pi_0_4_8_12b << endl;
	return 0;
}
