//#include <iostream>
#include "MTerm.h"
using namespace std;

int MTerm::Bit(int pos) const {
	// 범위를 벗어나는 경우에 대한 예외 처리는 하지 않음.
	unsigned int mask = 1 << pos;
	if (num & mask)
		return 1;
	else
		return 0;
}

bool MTerm::IsHDOne(const MTerm& m) const {
	// XOR을 이용해 비트가 다른 부분을 찾는다.
	unsigned int XORed = num ^ m.num;

	// 마스크를 이용해 1의 개수(비트가 다른 부분의 수)를 센다.
	unsigned int mask = 1;
	int numOfOneOfXORed = 0;
	for (int i = 0; i < nbits; i++) {
		if (XORed & mask)
			if (++numOfOneOfXORed > 1) // HD가 1보다 큰 것이므로 false 반환
				// d이미 HD가 1을 넘겼는데도 계속 작업하여
				// 쓸데없는 처리를 하게 되는 경우를 막기 위함.
				return false;
		mask <<= 1;
	}
	return (numOfOneOfXORed == 1);
}

int MTerm::OneAmount() const {
	int oneAmount = 0;
	for (int i = 0; i < nbits; i++)
		oneAmount += Bit(i);
	return oneAmount;
}

ostream& operator<<(ostream& os, const MTerm& m) {
	os << (m.isDontCare ? "x" : "m") << m.num << ":";
	for (int i = m.nbits - 1; i >= 0; i--)
		os << m.Bit(i);
}
