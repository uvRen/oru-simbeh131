#include "Interval.h"
#include <iostream>

int main() {
	Interval<double> i1(2, 1), u1(5, 1), i2(2, 2), u2(5, 2), i3(2, 4), u3(5, 2);

	cout << "I=2mA med m\x84tnoggrannheten +-1% och U=5V med m\x84tnoggrannheten +-1%." << endl;
	cout << "R = U/I" << endl;
	cout << "R = " << u1 / i1 << endl;
	cout << "P = U * I" << endl;
	cout << "P = " << u1 * i1 << endl;

	cout << "I=2mA med m\x84tnoggrannheten +-2% och U=5V med m\x84tnoggrannheten +-2%." << endl;
	cout << "R = U/I" << endl;
	cout << "R = " << u2 / i2 << endl;
	cout << "P = U * I" << endl;
	cout << "P = " << u2 * i2 << endl;

	cout << "I=2mA med m\x84tnoggrannheten +-4% och U=5V med m\x84tnoggrannheten +-2%." << endl;
	cout << "R = U/I" << endl;
	cout << "R = " << u3 / i3 << endl;
	cout << "P = U * I" << endl;
	cout << "P = " << u3 * i3 << endl;


	system("pause");
	return 0;
}