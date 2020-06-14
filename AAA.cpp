#include <list>
#include "AA.cpp"

int main(void) {
	list<AAA> a;
	a.push_back(AAA(1));
	a.push_back(AAA(2));
	auto it = a.begin();
	(*it).num = 5;
	cout << (*it).num << endl;
	return 0;
}
