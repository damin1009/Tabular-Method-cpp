#include "PrimeI.h"
#include <cmath>
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
	int j = p1.myMTermsCount;
	for (int i = 0; i < p2.myMTermsCount; i++, j++)
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

	isCombined = false;
}

bool PrimeI::IsHDOne(const PrimeI& p) const {
	if (myMTermsCount != p.myMTermsCount) // 가진 Term의 개수가 다르면 합칠 수 없음.
		return false;
	if (abs(numOfOnes - p.numOfOnes) != 1) // 1의 수의 차이가 정확히 1이 아니라면 합칠 수 없음.
		return false;
	if (hyphens != p.hyphens) // 하이픈 위치가 다르면 합칠 수 없음.
		return false;
	
	//XOR 연산으로 비트가 다른 부분을 찾는다.
	unsigned int xored = binaryNum ^ p.binaryNum;
	unsigned int mask = 1;
	int numOfOneOfXORed = 0;
	for (int i = 0; i < myMTerms[0].nbits; i++) {
		if (xored & mask)
			if (++numOfOneOfXORed > 1) // HD가 1보다 큰 상황
				return false;
		mask << 1;
	}
	return (numOfOneOfXORed == 1); // HD가 0인지 1인지
}

ostream& operator<<(ostream& os, const PrimeI& p) {
	os << "PI->";
	for (int i = 0; i < p.myMTermsCount; i++)
		os << p.myMTerms[i] << " ";
	os << "[";
	unsigned int mask = 1 << p.myMTerms[i].nbits;
	for (int i = p.myMTerms[0].nbits - 1; i >= 0; i--) {
		mask >> 1;
		if (mask & p.hyphens)
			os << "-";
		else
			os << (mask & p.binaryNum);
	}
	os << "]";
	os << endl;
	os << "  -> numOfOnes: " << p.numOfOnes << " and isCombined: " << p.isCombined;
}





