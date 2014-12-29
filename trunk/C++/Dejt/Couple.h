#include "Person.h"

class Couple {
private:
	Person male;
	Person female;

public:
	//konstruktor
	Couple() {
		
	}

	//funktioner
	void setMaleCouple(Person p) {
		this->male = p;
	}

	void setFemaleCouple(Person p) {
		this->female = p;
	}
};