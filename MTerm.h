#include <iostream>

class MTerm {
public:
	unsigned int num; // 10진수 숫자
	int nbits; // 비트의 개수
	bool isDontCare;
	void Init(unsigned int n=0, int nb=4, bool d=false) {
		num = n; nbits = nb; isDontCare = d; 
	}
	void Init(const MTerm& m) {
		Init(m.num, m.nbits, m.isDontCare);
	}
	MTerm(unsigned int n=0, int nb=4, bool d=false) { Init(n, nb, d); }
	MTerm(const MTerm& m) { Init(m); }

	int Bit(int pos) const; // pos번째 비트의 값을 반환. 0부터 셈.
	bool IsHDOne(const MTerm& m) const; // 두 비트의 HD가 1인지 반환
	int OneAmount() const; // 1의 수 반환
	friend std::ostream& operator<<(std::ostream& os, const MTerm& m);
		// num=3, nbits=4, isDontCare=true인 경우,
		// x3:0011라고 출력한다. 돈케어가 아니면 m으로 시작.
};
