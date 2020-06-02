#include <iostream>
#include "MTerm.h"
using namespace std;

int main(void) {
	MTerm m0;
	MTerm m1(1);
	MTerm m2(2);
	MTerm m3(3);
	MTerm x5(5, 4, true);

	cout << "m0: " << m0 << endl;
	cout << "m1: " << m1 << endl;
	cout << "m2: " << m2 << endl;
	cout << "m3: " << m3 << endl;
	cout << "x5: " << x5 << endl;

	cout << "m0 m1 HD is One? " << m0.IsHDOne(m1) << endl;
	cout << "m0 m2 HD is One? " << m0.IsHDOne(m2) << endl;
	cout << "m0 m3 HD is One? " << m0.IsHDOne(m3) << endl;
	cout << "m0 x5 HD is One? " << m0.IsHDOne(x5) << endl;
	cout << "m1 m2 HD is One? " << m1.IsHDOne(m2) << endl;
	cout << "m1 m3 HD is One? " << m1.IsHDOne(m3) << endl;
	cout << "m1 x5 HD is One? " << m1.IsHDOne(x5) << endl;
	cout << "m2 m3 HD is One? " << m2.IsHDOne(m3) << endl;
	cout << "m2 x5 HD is One? " << m2.IsHDOne(x5) << endl;
	cout << "m3 x5 HD is One? " << m3.IsHDOne(x5) << endl;

	return 0;
}
