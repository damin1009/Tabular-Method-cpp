#include <iostream>

class MTerm {
public:
	unsigned int num; // 10진수 숫자
	int nbits; // 비트의 개수
	bool isDontCare;
	MTerm(unsigned int n=0, int nb=4, bool d=false): num(n), nbits(nb), isDontCare(d) {};

	int Bit(int pos) const; // pos번째 비트의 값을 반환. 0부터 셈.
	bool IsHDOne(const MTerm& m) const; // 두 비트의 HD가 1인지 반환
	friend std::ostream& operator<<(std::ostream& os, const MTerm& m);
		// num=3, nbits=4, isDontCare=true인 경우,
		// 0011(X)라고 출력한다. 돈케어가 아니면 M이라 출력.
};
