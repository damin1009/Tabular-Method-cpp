#include "PiListContainer.h"

PiListContainer::PiListContainer(int nm): numOfOnes(nm) {}

PiListContainer::PiListContainer(const PiListContainer& p) {
	numOfOnes = p.numOfOnes;
	pis.clear();
	auto it = p.pis.begin();
	for (; it != p.pis.end(); it++) {
		pis.push_back(PrimeI(*it));
	}
	myPiAmount = p.myPiAmount;
}

PiListContainer::PiListContainer 
	(PiListContainer& pl1, PiListContainer& pl2) 
{
	numOfOnes = 
		(pl1.numOfOnes < pl2.numOfOnes) ? pl1.numOfOnes : pl2.numOfOnes; 
	
	auto it1 = pl1.pis.begin();
	for (; it1 != pl1.pis.end(); it1++) {
		auto it2 = pl2.pis.begin();
		for (; it2 != pl2.pis.end(); it2++) {
			if (!(*it1).IsHDOne(*it2))
				continue;

			(*it1).isCombined = true;
			(*it2).isCombined = true;

			// 같은 pi가 있는지 확인
			const PrimeI p(*it1, *it2);
			auto myIt = pis.begin();
			for (; myIt != pis.end(); myIt++) {
				if ((*myIt).hyphens == p.hyphens
					&& (*myIt).binaryNum == p.binaryNum) {
					break;
				}
			}
			// 같은 pi가 없음
			if (myIt == pis.end())
				AddPi(p);
		}
	}
}


void PiListContainer::AddPi(const PrimeI& pr) {
	pis.push_back(PrimeI(pr));
	myPiAmount++;
}

ostream& operator<<(ostream& os, const PiListContainer& pl) {
	os << "PiListContainer = numOfOnes: " << pl.numOfOnes << endl;
	auto it = pl.pis.begin();
	for (; it != pl.pis.end(); it++)
		os << *it << endl;
	return os;
}
