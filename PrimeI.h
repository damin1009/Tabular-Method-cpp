#include "MTerm.h"
class PrimeI {
public:
	MTerm *myMTerms; // 이 PI에 속한 MTerm들.
	int myMTermsCount; // 이 PI에 속한 MTerm의 수.
	unsigned int binaryNum; // 0-01 이라면, 0001. 하이픈은 0으로.
		// 하이픈을 0으로 하는 이유는, 1의 수를 셀 때 하이픈을 제외해야 하므로.
	int numOfOnes; // 1의 수. 하이픈은 제외임.
	unsigned int hyphens; // 0-01 이라면, 하이픈 위치에 1. 0100.
	bool isCombined;

	void Init(const MTerm& mt);
	PrimeI();
	PrimeI(const MTerm& mt);
	PrimeI(const PrimeI& p1, const PrimeI& p2); // 두 PI를 합친 새로운 PI 생성
		// 물론 합쳐질 수 있는 순간 그것들은 PI가 아닌 것이긴 한데
		// 굳이 '아직 PI인지 아닌지 모르는 묶음"이라고 할 필요는 없으니...
	~PrimeI() { delete[] myMTerms; }

	bool IsHDOne(const PrimeI& p) const;  // 다른 PI와 HD를 비교하여, 1인지 반환
	friend std::ostream& operator<<(std::ostream& os, const PrimeI& p);
};
