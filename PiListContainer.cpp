#include "PiListContainer.h"

PiListContainer::PiListContaine(){}

PiListContainer::PiListContainer 
	(const PiListContainer& pl1, const PiListContainer& pl2) 
{
	numOfOnes = 
		(pl1.numOfOnes < pl2.numOfOnes) ? pl1.numOfOnes : pl2.numOfOnes; 
	
	for (int i = 0; i < pl1.myPiAmount; i++) {
		for (int j = i; pl2.myPiAmount; j++) {
			if (pl1.pis[i].IsHDOne(pl2.pis[j]))
				continue;

			pl1.pis[i].isCombined = true;
			pl2.pis[i].isCombined = true;
			AddPi(new PrimeI(pl1.pis[i], pl2.pis[j]));
		}
	}
}


void PiListContainer::AddPi(const PrimeI& pr) {
	pis.push_back(pr);
	myPiAmount++;
}

ostream& operator<<(ostream& os, const PiListContainer& pl) {
	os << "PiListContainer ====" << endl
	for (int i = 0; i < myPiAmount; i++)
		os << pis[i] << endl;
	return os;
}
