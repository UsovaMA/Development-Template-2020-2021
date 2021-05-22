#include "TPolinom.h"
using namespace std;

int main() {

	double a[] = { 1, 2, 3 };
	double b[] = { 4, 5, 6 };
	TMonom A(3, 3, a);
	TMonom B(2, 3, b);
	cout << "Monom A = " << A << endl;
	cout << "Monom B = " << B << endl;

	TPolinom P;
	P += A;
	P += B;
	cout << "Polinom P = A + B = " << P << endl;

	TPolinom P2(P);
	cout << "Polinom P2 = " << P2 << endl;

	TPolinom P3;
	P3 = P + P2;
	cout << "Polinom P3 = P + P2 = " << P3 << endl;

	P3 *= A;
	cout << "P3 *= A = " << P3 << endl;


	return 0;
}
