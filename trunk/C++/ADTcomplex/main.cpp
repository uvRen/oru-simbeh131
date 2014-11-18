#include "Complex.h"

int main() {
	Complex<int> a(1, 2), b(3, 4), c(5, -2);

	cout << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl;

	cout << a << b << c << " = " << a*b*c << endl;
	
	system("pause");
	return 0;
}