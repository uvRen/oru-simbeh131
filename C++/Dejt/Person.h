#include "InterestTable.h"

class Person {
private:
	string namn;
	InterestTable intresse;

public:
	Person() {
		namn = "";
	}

	Person(string namn) {
		this->namn = namn;
	}
};