#pragma once
#include "Person.h"

class PersonList {
private:
	forward_list<Person> boys;
	forward_list<Person> girls;

public:
	//konstruktor
	PersonList() {

	}

	//funktioner
	//lägger till en person i personlistan.
	void AddPerson(Person p) {
		//om det är en man
		if (p.getGender().compare("male") == 0) {
			boys.push_front(p);
		}
		else if(p.getGender().compare("female") == 0) {
			girls.push_front(p);
		}
	}

	//skriver ut alla personer som finns i listan i konsolfönstret.
	void printList() {
		cout << "Male:" << endl;
		for (auto &a : boys) {
			cout << a << endl;
		}
		cout << "Female:" << endl;
		for (auto &a : girls) {
			cout << a << endl;
		}
	}

	//skriver alla män och kvinnor som finns i listorna till seperata filer. Män i en fil och kvinnor i en fil.
	void WriteToFile() {
		ofstream ut;
		string filnamn = "Males.txt";

		ut.open(filnamn);
		for (auto &a : boys) {
			ut << a << endl;
		}
		ut.close();

		filnamn = "Females.txt";
		ut.open(filnamn);
		for (auto &a : girls) {
			ut << a << endl;
		}
		ut.close();

	}
};