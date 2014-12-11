#pragma once
#include "InterestTable.h"

class Person {
private:
	string namn;
	InterestTable intresse;

public:
	//konstruktor
	Person() {
		namn = "";
	}

	Person(string namn) {
		this->namn = namn;
	}

	//funktioner
	void AddInterest(string intresse) {
		this->intresse.AddInterest(intresse);
	}
	
	string toString() {
		ostringstream ut;

		ut << namn << '=' << intresse.toString() << endl;

		return ut.str();
	}
};