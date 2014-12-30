#pragma once
#include "Person.h"

class Couple {
private:
	Person male;
	Person female;

public:
	//konstruktor
	Couple() {
		
	}

	Couple(Person male, Person female) {
		this->male = male;
		this->female = female;
	}

	//funktioner
	Couple& operator=(Couple &c) {
		this->male = c.male;
		this->female = c.female;
		return *this;
	}

	//tilldelar en man till paret
	void setMaleCouple(Person p) {
		this->male = p;
	}

	//tilldelar en kvinna till paret
	void setFemaleCouple(Person p) {
		this->female = p;
	}
};