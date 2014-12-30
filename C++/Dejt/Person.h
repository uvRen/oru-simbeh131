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

	//returner vilken k�n personen �r
	string getGender() {
		return this->gender;
	}

	//anger ett k�n till personen
	void setGender(string gender) {
		this->gender = gender;
	}

	//l�gger till ett nytt intresse till en person
	void AddInterest(string intresse) {
		this->intresse.AddInterest(intresse);
	}
	
	//l�ser in uppgifter om en person fr�n konsolf�nstret
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

	//returnerar en str�ng med all information om en person
	string toString() {
		ostringstream ut;

		ut << namn << '=' << intresse.toString();

		return ut.str();
	}

	//�verlagrar operatorn << f�r objektet 'Person'
	friend ostream& operator<<(ostream &ut, Person &p) {
		ut << p.toString();
		return ut;
	}

	friend istream& operator>>(istream &in, Person &p) {
		string s;
		getline(in, p.namn, '=');
		getline(in, s, '[');
		getline(in, s, ']');
		istringstream iss(s);

		while (getline(iss, s, ',')) {
			p.intresse.AddInterest(s);
		}
		return in;

	}

};