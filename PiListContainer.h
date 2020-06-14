#include <iostream>
#include <list>
#include "PrimeI.h"
using namespace std;

class PiListContainer {
public:
	int numOfOnes;
	std::list<PrimeI> pis;
	int myPiAmount;

	PiListContainer(int nm=0);
	PiListContainer(const PiListContainer& p);
	PiListContainer(PiListContainer& pl1, PiListContainer& pl2);
	void AddPi(const PrimeI& pr);

	friend ostream& operator<<(ostream& os, const PiListContainer& pl);
};

