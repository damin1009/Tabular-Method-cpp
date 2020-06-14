//#include "MTerm.h"
//#include "PrimeI.h"
// #include <iostream>
// #include <list>
#include <vector>
#include "PiListContainer.h"

class PiGenerator {
public:
	vector<PiListContainer> cts; // 1의 수가 x개인 pi들을 담는 PiListContainer을 원소로 가지는 리스트
		// 1의 개수가 0 1 2 3 4 ... 인 순서로 PiListContainer을 담는다.
	vector<PrimeI> completePis;  // MakePis() 함수를 실행했을 때
		// 진짜 PI들이 담기는 리스트.

	PiGenerator();
	PiGenerator(int nbits, list<int> allTerms, int mtermsAmount, int dontcaresAmount);
		// 시작 term들을 생성하고, 이를 작은 pi 클래스로 만들고,
		//   이를 적절한 PiListContainer에 담는다.
	void MakePis();
		// 1의 개수가 1 차이나는 것 끼리 비교하며
		//  "진짜" PI를 찾아내, completePis에 저장한다.
};
