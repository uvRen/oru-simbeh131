#include "circular_list.h"

using namespace std;

int main() {
	Betyg4::circular_list lista;

	lista.add("hej1");
	lista.add("hej2");
	lista.add("hej3");
	lista.add("hej4");

	lista.print();

	/*Betyg4::circular_list lista2(lista);

	cout << "Lista1:" << endl;
	lista.print();
	cout << "Lista2:" << endl;
	lista2.print();*/

	system("pause");
	return 0;
}