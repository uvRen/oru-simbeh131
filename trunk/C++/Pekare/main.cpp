#include <iostream>
#include <string>

using namespace std;

int main() {
	int *p = new int[2];
	p[0] = 21;
	p[1] = 30;
	int a = 10;

	cout << "*p: " << *p << endl; //skriver ut p[0]
	cout << "*p+1: " << *(p + 1) << endl; // skriver ut p[1]
	cout << " p: " << p << endl; // skriver ut adressen till HEAPEN d�r p finns.
	cout << "&p: " << &p << endl; // skriver ut adressen till pekaren *p som finns p� STACKEN.
	cout << "a: " << a << endl; // skriver ut a som finns p� STACKEN.
	cout << "&a: " << &a << endl; //skriver ut adressen till a p� STACKEN.

	system("pause");
	return 0;
}