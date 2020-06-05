#include <iostream>
#include <vector>
#include "PrimeI.h"
using namespace std;

class PiListContainer {
public:
	int numOfOnes;
	vector<PrimeI> pis;
	int myPiAmount;

	PiListContainer();
	PiListContainer(const PiListContainer& pl1, const PiListContainer& pl2);
	void AddPi(const PrimeI& pr);

	friend ostream& operator<<(ostream& os, const PiListConrainer& pl);
};

