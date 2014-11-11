#include "Rational.h"

int main() {
		{
			using namespace Simon::adt;
			Rational<int> r1(1, 5), r2(1, 6), r3;

			cout << "r1: ";
			r1.print_rational();
			cout << "r2: ";
			r2.print_rational();

			cout << "r1 + r2 = " << r1 + r2 << endl;;
		}
	
	system("pause");

	return 0;
}