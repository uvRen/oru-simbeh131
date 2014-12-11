#pragma once
#include "InterestTable.h"

class Person {
private:
	string namn, gender;
	InterestTable intresse;

public:
	//konstruktor
	Person() {
		namn = "";
		gender = "";
	}

	Person(string namn, string gender) {
		this->namn = namn;
		this->gender = gender;

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