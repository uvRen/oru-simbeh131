#include "Rational.h"

int main() {
		{
			using namespace Simon::adt;
			Rational<int> r1(3, 4), r2(4, 5), r3;

			cout << "r1: ";
			r1.print_rational();
			cout << "r2: ";
			r2.print_rational();

			cout << "r1 + r2 = " << r1 + r2 << endl;
			cout << "r1 - r2 = " << r1 - r2 << endl;
			cout << "r1 * r2 = " << r1 * r2 << endl;
			cout << "r1 / r2 = " << r1 / r2 << endl;

		}
	
	system("pause");

	return 0;
}