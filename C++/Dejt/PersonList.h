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
	void AddPerson(Person p) {
		//om det är en man
		if (p.getGender().compare("male") == 0) {
			boys.push_front(p);
		}
		else if(p.getGender().compare("female") == 0) {
			girls.push_front(p);
		}
	}

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
};