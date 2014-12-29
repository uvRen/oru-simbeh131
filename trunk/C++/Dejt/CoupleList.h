#pragma once
#include "Couple.h"
#include "PersonList.h"
#include "Person.h"

class CoupleList {
private:
	forward_list<Couple> lista;

public:
	//konstruktor
	CoupleList() {

	}

	//funktioner
	void AddCouple(Couple c) {
		this->lista.push_front(c);
	}
};