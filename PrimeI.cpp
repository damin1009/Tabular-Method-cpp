#include "PrimeI.h"
#include <iostream>
using namespace std;

PrimeI::PrimeI() {
	myMTerms = new MTerm[0];
	myMTermsCount = 0;
	numOfOnes = 0;
	hyphens = 0;
	isCombined = false;
}

PrimeI::PrimeI(const MTerm& mt) {
	myMTerms = new MTerm[1] { mt };
	myMTermsCount = 1;
	numOfOnes = mt.OneAmount();
	hyphens = 0;
	isCombined = false;
}

PrimeI::PrimeI(const PrimeI& p1, const PrimeI& p2) {
	// PI는 서로 HD가 1일 때만 합쳐질 수 있지만,
	// 이를 여기서 확인하지는 않는다.
	myMTermsCount = p1.myMTermsCount + p2.myMTermsCount;
	myMTerms = new MTerm[myMTermsCount];
	for (int i = 0; i < p1.myMTermsCount; i++)
		myMTerms[i] = p1.myMTerms[i];
	for (int i = 0, int j = p1.myMTermsCount; i < p2.myMTermsCout; i++, j++)
		myMTerms[j] = p2.myMTerms[j];
	
	hyphens = 0;
	// hyphens를 XOR 이용해서 구하기
	


}
