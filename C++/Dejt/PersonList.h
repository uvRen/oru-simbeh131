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
		else {
			girls.push_front(p);
		}
	}
};