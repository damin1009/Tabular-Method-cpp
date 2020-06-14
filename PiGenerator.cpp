//#include "MTerm.h"
//#include "PrimeI.h"
// #include <iostream>
// #include <list>
//#include "PiListContainer.h"
#include "PiGenerator.h"
#include <queue>
using namespace std;

PiGenerator::PiGenerator() {

}

PiGenerator::PiGenerator(int nbits, list<int> allTerms, int mtermsAmount, int dontcaresAmount) {
	// 우선 PiListContainer 초기화
	for (int i = 0; i <= nbits; i++)
		cts.push_back(PiListContainer(i));

	// 그리고 작은 pi 만들어서,
	// 1의 개수가 같은 것끼리 PiListContainer에 집어넣기
	auto it = allTerms.begin();
	int allAmount = mtermsAmount + dontcaresAmount;
	int i = 0;
	for (i = 0; i < allAmount && it != allTerms.end(); i++, it++) {
		PrimeI p(MTerm(*it, nbits, i >= mtermsAmount));
			// i >= mtermsAmount 의 의미:
			// if (i >= mtermsAmount) 돈케어 else 필수
		cts[p.numOfOnes].AddPi(p);
	}

	// 혹시 인자가 잘못 왔을 가능성 생각.
	if (i != allAmount || it != allTerms.end()) {
		cout << "에러!! mtermsAmount와 dontcaresAmount가 잘못 들어온 것 같습니다." << endl;
		cout << "mtermsAmount:" << mtermsAmount << "  dontcaresAmount:" << dontcaresAmount << endl;
		cout << "allAmount:" << allAmount << "  allTerms.size(): " << allTerms.size() << endl;
		it = allTerms.begin();
		cout << "allTerms: ";
		for (; it != allTerms.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "초기 PiListContainer들이 잘 생성되었는지 확인" << endl;
	for (int i = 0; i < cts.size(); i++)
		cout << cts[i] << endl;
}

void PiGenerator::MakePis() {
	completePis.clear();

	if (cts.size() < 2) {
		return;
	}

	vector<PiListContainer> q;
	auto it = cts.begin();
	int rest = 0;  // 이번 레벨에서, 남은 컨테이너 수
	for (; it != cts.end(); it++) {
		q.push_back(*it);
		rest++;
	}
	rest--;
	
	cout << "Init Comp" << endl;

	// 만약 총 컨테이너 수가 4일 때, 큐에는 3개 들어간 상태로 시작. rest도 3.
	// 2개씩 합쳐서, 이제 3번이랑 4번이 합쳐진 후, rest--로 rest가 0이 됨.
	// 
	for (int i = 1; i < q.size(); rest--, i++) {
		// rest == 0이라면, 이번 레벨(합쳐진 수)에 있는 컨테이너끼리
		//   가능한 모든 경우의 수로 합치기 시도한 상태.
		//   즉 이번에 꺼내는 q는 다음 레벨의 것.
		if (rest == 0) {
			cout << ">> rest가 0이 되었음!" << endl;
			// 이번 컨테이너와 다음 컨테이너를 합칠 수는 없음.
			//   레벨이 달라서.
			//   따라서 이번 단계는 건너뛰면서, rest를 설정하고,
			//   다음 컨테이너와 그다음 컨테이너끼리 합칠 수 있도록 함.
			rest = q.size() - i;

			if (rest < 2)
				break;

			rest--;
			i++;
		}

		// pi를 하나도 가지지 않은, 빈 컨테이너라면, 합치지 않고 넘어감.
		// 또한 두 컨테이너의 numOfOnes의 차이가 1이 아니라면, 합치지 않고 넘어감.
		// 앞에 있는 컨테이너의 numOfOnes가 뒤에 있는 컨테이너보다 무조건 작다.
		if ( (q[i-1].myPiAmount == 0) || (q[i].myPiAmount == 0)
			|| (q[i].numOfOnes - q[i-1].numOfOnes != 1) ) {
			continue;
		}

		cout << ">> Combine Two Container" << endl;
		cout << q[i-1];
		cout << q[i] << endl;
		// queue에 두 컨테이너를 합친 새로운 컨테이너 추가
		q.push_back(PiListContainer(q[i-1], q[i]));
		cout << ">> Result New Container" << endl;
		cout << q.back() << endl;
	}

	// combined되지 않은 모든 pi들을
	// completePis에 추가.
	auto itvec = q.begin();	
	for (; itvec != q.end(); itvec++) {
		auto itit = (*itvec).pis.begin();
		for (; itit != (*itvec).pis.end(); itit++) {
			if (!(*itit).isCombined)
				completePis.push_back(*itit);
		}
	}
	
	cout << ">> PI들이 제대로 생성되었는가??" << endl;
	for (int i = 0; i < completePis.size(); i++)
		cout << completePis[i] << endl;
}
