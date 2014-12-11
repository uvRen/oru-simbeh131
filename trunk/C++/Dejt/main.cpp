#include "../forward_list/forward_list.h"
#include <string>
#include "InterestTable.h"
#include "Person.h"

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

void testPerson() {
	Person p("Simon Berntsson");

	p.AddInterest("sport");
	p.AddInterest("data");
	p.AddInterest("godis");

	cout << p.toString() << endl;
}

int main() {
	cout << "testInterestTable():" << endl;
	testInterestTable();
	cout << endl << endl;
	cout << "testPerson():" << endl;
	testPerson();
	cout << endl << endl;
	

	system("pause");
	return 0;
}