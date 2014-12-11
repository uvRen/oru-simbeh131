#include "../forward_list/forward_list.h"
#include <string>
#include "InterestTable.h"

void testInterestTable() {
	InterestTable intresse;

	intresse.AddInterest("training");
	intresse.AddInterest("movies");
	intresse.AddInterest("swimming");

	intresse.printList();
	intresse.WriteToFile();
	intresse.ReadFromFile();
	intresse.printList();

	cout << endl << intresse.toString() << endl;
}

int main() {
	testInterestTable();


	system("pause");
	return 0;
}