#include "PrimeI.h"
#include <iostream>
using namespace std;

PrimeI::PrimeI() {
	myMTerms = new MTerm[0];
	myMTermsCount = 0;
	binaryNum = 0;
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

	binaryNum = p1.binaryNum & p2.binaryNum;
	// 01-1과 01-0이 만난다면, 01--가 되어야 함.
	// binaryNum은 각각 0101과 0100이고, & 하면 0100. 정확함.
	numOfOnes = 0;
	unsigned int mask = 1;
	for (int i = 0; i < myMTerms[0].nbits; i++) {
		if (binaryNum & mask)
			numOfOnes++;
		mask << 1;
	}


	// hyphens를 XOR 이용해서 구하기
	hyphens = p1.hyphens;
	// 우선 합쳐지려면 p1과 p2의 하이픈이 같아야 함.
	hyphens |= p1.binaryNum ^ p2.binaryNum;
	// 그리고 p1과 p2를 XOR연산하여 다른 부분을 찾아냄.
	//   이 부분이 추가로 하이픈이 된다.

}
