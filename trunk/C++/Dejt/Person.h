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
	Person& operator=(const Person &p) {
		this->namn = p.namn;
		this->gender = p.gender;
		return *this;
	}

	string getGender() {
		return this->gender;
	}

	void AddInterest(string intresse) {
		this->intresse.AddInterest(intresse);
	}
	
	string toString() {
		ostringstream ut;

		ut << namn << '=' << intresse.toString() << endl;

		return ut.str();
	}
};