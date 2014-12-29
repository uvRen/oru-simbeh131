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
	Person& operator=(Person &p) {
		this->namn = p.namn;
		this->gender = p.gender;
		this->intresse = p.intresse;
		return *this;
	}

	string getGender() {
		return this->gender;
	}

	void AddInterest(string intresse) {
		this->intresse.AddInterest(intresse);
	}
	
	void Read() {
		string input;
		cout << "Name: ";
		getline(cin, input);
		this->namn = input;

		cout << "Gender: ";
		getline(cin, input);
		this->gender = input;

		cout << "Interest: ";
		getline(cin, input);

		istringstream iss(input);
		while (getline(iss, input, ',')) {
			AddInterest(input);
		}

	}

	string toString() {
		ostringstream ut;

		ut << namn << '=' << intresse.toString();

		return ut.str();
	}

	friend ostream& operator<<(ostream &ut, Person &p) {
		ut << p.toString();
		return ut;
	}

};