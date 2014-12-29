#include "../forward_list/forward_list.h"
#include <string>
#include "InterestTable.h"
#include "Person.h"
#include "PersonList.h"
#include "Couple.h"
#include "CoupleList.h"

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
	Person p("Simon Berntsson", "male"), p2;

	p.AddInterest("sport");
	p.AddInterest("data");
	p.AddInterest("godis");

	p2.Read();

	cout << p.toString() << endl;
	cout << p2.toString() << endl;
}

void testPersonList() {
	PersonList lista;
	Person p1, p2, p3, p4;

	p1.Read();
	p2.Read();

	lista.AddPerson(p1);
	lista.AddPerson(p2);

	lista.printList();
	lista.WriteToFile();
}

void testCouple() {
	Person p("Simon Berntsson", "male"), p2("Bella Johnsson", "female");
	/*p.AddInterest("hej");
	p2.AddInterest("hejsan");*/

	Couple c(p, p2);

	/*c.setMaleCouple(p);
	c.setFemaleCouple(p2);*/
}

int main() {
	//testPerson();
	//testInterestTable();
	//testPersonList();
	testCouple();

	system("pause");
	return 0;
}