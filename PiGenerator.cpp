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

	queue<PiListContainer> q;
	PiListContainer *c1 = cts[0];
	int rest = 0;  // 이번 레벨에서, 남은 컨테이너 수
	for (auto it = ++cts.begin(); it != cts.end(); it++) {
		q.push(*it);
		rest++;
	}

	// 만약 총 컨테이너 수가 4일 때, 큐에는 3개 들어간 상태로 시작. rest도 3.
	// 2개씩 합쳐서, 이제 3번이랑 4번이 합쳐진 후, rest--로 rest가 0이 됨.
	// 

	for (; !q.isEmpty(); rest--) {
		// 이번 레벨(합쳐진 수)에 있는 컨테이너끼리
		// 가능한 모든 경우의 수로 합치기 시도한 상태.
		// 즉 이번에 꺼내는 q는 다음 레벨의 것.
		if (rest == 0) {
			rest = q.size();
			c1 = *(q.top());
			q.pop();
			continue;
		}

		if (q.top().myPisAmount == 0)
			continue;

		if (q.top().numOfOnes - (*c1).numOfOnes != 1)
			continue;
		
		// queue에는 두 컨테이너를 합친 새로운 컨테이너 추가
		q.push(PiListContainer(*c1, q.top());
		rest++;

		// combined되지 않은 모든 pi들을
		// completePis에 추가.
		auto itpi = c1.pis.begin();
		for (; itpi != c1.pis.end(); it++)
			if (!(*itpi).isCombined)
				completePis.push_back(*itpi);
		itpi = q.top().pis.begin();
		for (; itpi != q.top().pis.end(); it++)
			if (!(*itpi).isCombined)
				completePis.push_back(*itpi);
	
	}
}
