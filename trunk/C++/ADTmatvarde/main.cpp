#include "Interval.h"
#include <iostream>

int main() {
	Interval<double> a(100, 3), b(100, 3);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "a+b = " << a + b << endl;
	cout << "a-b = " << a - b << endl;
	cout << "a*b = " << a * b << endl;cout << "a*b = " << a * b << endl;
	cout << "a/b = " << a / b << endl;


	system("pause");
	return 0;
}