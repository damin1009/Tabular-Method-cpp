#include "PiListContainer.h"
//#include <iostream>
//#include "PrimeI.h"
//using namespace std;

int main(void) {
	// PrimeI_test.cpp에서 내용 따옴
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

	PiListContainer pl0();
	PiListContainer pl1();
	PiListContainer pl2();
	PiListContainer pl3();
	pl0.AddPi(pis[0]);
	pl1.AddPi(pis[1]);
	pl1.AddPi(pis[2]);
	pl2.AddPi(pis[3]);
	pl2.AddPi(pis[4]);
	pl3.AddPi(pis[5]);
	pl3.AddPi(pis[6]);
	pl4.AddPi(pis[7]);

	PiListContainer pl0_cmb1(pl0, pl1);
	PiListContainer pl1_cmb1(pl1, pl2);
	PiListContainer pl2_cmb1(pl2, pl3);
	PiListContainer pl3_cmb1(pl3, pl4);
	cout << "pl0_cmb1" << pl0_cmb1 << endl;
	cout << "pl1_cmb1" << pl1_cmb1 << endl;
	cout << "pl2_cmb1" << pl2_cmb1 << endl;
	cout << "pl3_cmb1" << pl3_cmb1 << endl;

	return 0;
}
