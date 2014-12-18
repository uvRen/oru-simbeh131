#include <iostream>
#include "Rekursion.h"

using namespace std;

int main() {
	cout << "Ej rekursiv: " << Betyg3::Rekursion::fak(3) << endl;
	cout << "Rekursiv: " << Betyg3::Rekursion::fakRek(3) << endl;

	cout << "Summa: " << Betyg3::Rekursion::summa(5, 3) << endl;
	cout << "SummaRek: " << Betyg3::Rekursion::summaRek(5, 3) << endl;

	system("pause");
	return 0;


}